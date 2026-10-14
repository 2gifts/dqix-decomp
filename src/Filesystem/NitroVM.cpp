#include "Filesystem/FSInnerDefs.h"
#include "System/Interrupts.h"
#include "System/Memory.h"
#include <globaldefs.h>
#include <asmhacks.h>

// -O2,p optimization seems to be needed here
#pragma optimize_for_size off

typedef int(*FixedCommand)(NitroVM*);

#if defined(jpn)
#define data_020f2288 data_020f23f4
#endif

#define NITROFS_ID_INVALID 0x10000
extern unsigned char data_020f2288[]; // ":/"

extern "C" void NitroVM_UnlinkAndStoreResult(NitroVM* vm, int result)
{
    int priorIRQState = DisableIRQInterrupts();

    NitroVM* prev = vm->links.pPrev;
    NitroVM* next = vm->links.pNext;

    if (prev != NULL)
        prev->links.pNext = next;
    
    if (next != NULL)
        next->links.pPrev = prev;

    vm->links.pPrev = NULL;
    vm->links.pNext = NULL;
    // Clear flags 0, 1, 2, 3 and 6
    vm->flags &= ~(
        (1 << NITROVM_FLAG_IN_HANDLE_QUEUE) |
        (1 << NITROVM_FLAG_MARKED_FOR_UNLINK_FROM_HANDLE) |
        (1 << NITROVM_FLAG_SYNCHRONOUS) |
        (1 << NITROVM_FLAG_EXECUTING_FROM_QUEUE) |
        (1 << NITROVM_FLAG_READY_TO_EXECUTE));
    vm->storedResult = result;

    UnblockContexts(&vm->blockedContexts);

    SetIRQInterruptState(priorIRQState);
}

extern "C" int NitroVM_ExecuteCommand(NitroVM* vm, int opcode)
{
    int result;
    int machineStartingFlags = vm->flags;
    NitroHandle* nitroHandle = vm->linkedHandle;
    int opcodeMask = 1 << opcode;

    // Bit verbose, but this way works with volatile and non-volatile
    unsigned int handleFlagAdjust = nitroHandle->flags;
    if (GET_FLAG_BIT(machineStartingFlags, NITROVM_FLAG_SYNCHRONOUS))
        handleFlagAdjust |= (1 << NITROHANDLE_FLAG_SYNC_COMMAND_IN_PROGRESS);
    else
        handleFlagAdjust |= (1 << NITROHANDLE_FLAG_ASYNC_COMMAND_IN_PROGRESS);
    nitroHandle->flags = handleFlagAdjust;

    if ((nitroHandle->overrideOpcodeFlags & opcodeMask))
    {
        result = nitroHandle->instructionOverride(vm, opcode);
        switch (result)
        {
        case NITRO_RESULT_SUCCESS:
        case NITRO_RESULT_FAILURE:
        case NITRO_RESULT_COMMAND_UNSUPPORTED:
            vm->storedResult = result;
            break;
        case NITRO_RESULT_OPCODE_NOT_IMPLEMENTED:
            nitroHandle->overrideOpcodeFlags &= ~opcodeMask;
            result = NITRO_RESULT_FALLBACK_TO_DEFAULT;
            break;
        }
    }
    else
        result = NITRO_RESULT_FALLBACK_TO_DEFAULT;

    if (result == NITRO_RESULT_FALLBACK_TO_DEFAULT)
    {
        static const FixedCommand defaultCommands[] = {
            &NitroVM_DefaultCommand_Read,
            &NitroVM_DefaultCommand_Write,
            &NitroVM_DefaultCommand_GetDirectoryData,
            &NitroVM_DefaultCommand_GetFileOrDirectoryNameData,
            &NitroVM_DefaultCommand_GetFileOrDirectoryByName,
            &NitroVM_DefaultCommand_GetPath,
            &NitroVM_DefaultCommand_GetFATEntry,
            &NitroVM_DefaultCommand_SetFilePointers,
            &NitroVM_DefaultCommand_Nop
        };
        result = defaultCommands[opcode](vm);
    }

    if (result == NITRO_RESULT_TASK_STILL_RUNNING)
    {
        if (GET_FLAG_BIT(vm->flags, NITROVM_FLAG_SYNCHRONOUS))
        {
            int priorIRQState = DisableIRQInterrupts();
            if (GET_FLAG_BIT(nitroHandle->flags, NITROHANDLE_FLAG_SYNC_COMMAND_IN_PROGRESS))
            {
                do
                {
                    BlockCurrentContext(&nitroHandle->taskWaitBlock);
                } while (GET_FLAG_BIT(nitroHandle->flags, NITROHANDLE_FLAG_SYNC_COMMAND_IN_PROGRESS));
            }
            result = vm->storedResult;
            SetIRQInterruptState(priorIRQState);
        }
    }
    else
    {
        if (!GET_FLAG_BIT(vm->flags, NITROVM_FLAG_SYNCHRONOUS))
        {
            nitroHandle->flags &= ~(1 << NITROHANDLE_FLAG_ASYNC_COMMAND_IN_PROGRESS);
            NitroVM_UnlinkAndStoreResult(vm, result);
        }
        else
        {
            nitroHandle->flags &= ~(1 << NITROHANDLE_FLAG_SYNC_COMMAND_IN_PROGRESS);
            vm->storedResult = result;
        }
    }
    
    return result;
}

extern "C" int CaseInsensitiveStrncmp(const unsigned char* first,
    const unsigned char* second, unsigned int len)
{
    unsigned int index = 0;
    // needed to prevent optimizing to len != 0
    unsigned int ZERO = 0;
    if (len > ZERO)
    {
        do
        {
            unsigned int charA = first[index] - 'A';
            unsigned int charB = second[index] - 'A';

            if (charA <= 25)
                charA += 'a' - 'A';

            if (charB <= 25)
                charB += 'a' - 'A';

            if (charA != charB)
                return charA - charB;
            index++;
        } while (index < len);
    }
    return 0;
}

int Nitro_ReadMetadataBytes(FSReadDescription* readDesc, void* dst, unsigned int len)
{
    NitroHandle* nitroHandle = readDesc->nitroHandle;
    nitroHandle->flags |= (1 << NITROHANDLE_FLAG_SYNC_COMMAND_IN_PROGRESS);

    int result = nitroHandle->fastReadProc(nitroHandle, dst, readDesc->offset, len);
    switch (result)
    {
    case NITRO_RESULT_SUCCESS:
    case NITRO_RESULT_FAILURE:
        nitroHandle->flags &= ~(1 << NITROHANDLE_FLAG_SYNC_COMMAND_IN_PROGRESS);
        break;
    case NITRO_RESULT_TASK_STILL_RUNNING:
    {
        int priorState = DisableIRQInterrupts();
        if (GET_FLAG_BIT(nitroHandle->flags, NITROHANDLE_FLAG_SYNC_COMMAND_IN_PROGRESS))
        {
            do
            {
                BlockCurrentContext(&nitroHandle->taskWaitBlock);
            } while (GET_FLAG_BIT(nitroHandle->flags, NITROHANDLE_FLAG_SYNC_COMMAND_IN_PROGRESS));
        }

        SetIRQInterruptState(priorState);
        result = nitroHandle->linkToFirstVM.pNext->storedResult;
    }
    }
    readDesc->offset += len;
    return result;
}

// Sets up and executes command 2 with 'proper' registers (i.e. stuff that
// needs to be zero for proper behaviour is set to zero). This means, afterwards
// base_b_low holds the id of this directory (i.e. input parameter)
// base_b_high holds the id of the first file in the directory
// base_c holds an offset to the relevant FNT subtable (in particular, you're
// ready to iteratively run command 3 to get data about each contained file/subdir)
int NitroVM_LoadDirectoryDataByIndex(NitroVM* vm, unsigned int dirIndex)
{
    vm->flags |= (1 << NITROVM_FLAG_SYNCHRONOUS);
    vm->args_GetDirectoryData.accessor.handle = vm->linkedHandle;
    vm->args_GetDirectoryData.accessor.handleSubtableOffset = 0;
    vm->args_GetDirectoryData.accessor.firstFileID = 0;
    vm->args_GetDirectoryData.accessor.dirID = dirIndex;
    return NitroVM_ExecuteCommand(vm, NITROVM_OPCODE_GET_DIRECTORY_DATA);
}

int NitroVM_DefaultCommand_Read(NitroVM* vm)
{
    unsigned int oldCursor = vm->fileInfo.cursorPos;
    unsigned int length = vm->args_Read.length;
    NitroHandle* nitroHandle = vm->linkedHandle;
    void* dst = vm->args_Read.destination;

    vm->fileInfo.cursorPos = oldCursor + length;
    return nitroHandle->readProc(nitroHandle, dst, oldCursor, length);
}

int NitroVM_DefaultCommand_Write(NitroVM* vm)
{
    unsigned int oldOffset = vm->fileInfo.cursorPos;
    unsigned int length = vm->args_Write.length;
    NitroHandle* nitroHandle = vm->linkedHandle;
    void* src = vm->args_Write.source;

    vm->fileInfo.cursorPos = oldOffset + length;
    return nitroHandle->writeProc(nitroHandle, src, oldOffset, length);
}

struct FNTMainTableEntry
{
    unsigned int subtableOffset; // relative to FNT base
    unsigned short firstContainedFileID;
    unsigned short numDirectoriesOrParentID; // first (root) entry holds num directories, rest hold parent ID
};

int NitroVM_DefaultCommand_GetDirectoryData(NitroVM* vm)
{
    NitroHandle* nitroHandle = vm->linkedHandle;
    NitroDirectoryAccessor* extendedRegs = &vm->args_GetDirectoryData.accessor;
    FNTMainTableEntry tableEntry;
    FSReadDescription readDesc;
    
    readDesc.nitroHandle = nitroHandle;
    readDesc.offset = extendedRegs->dirID * 8 + nitroHandle->nameTableOffsetFast;
    
    int result = Nitro_ReadMetadataBytes(&readDesc, &tableEntry, 8);

    if (result == NITRO_RESULT_SUCCESS)
    {
        vm->dirInfo.accessor = *(NitroDirectoryAccessor*)extendedRegs;
    
        if (extendedRegs->firstFileID == 0 && extendedRegs->handleSubtableOffset == 0)
        {
            vm->dirInfo.accessor.firstFileID = tableEntry.firstContainedFileID;
            vm->dirInfo.accessor.handleSubtableOffset = nitroHandle->nameTableOffsetFast + tableEntry.subtableOffset;
        }
        vm->dirInfo.parentID = tableEntry.numDirectoriesOrParentID & 0xfff;
    }

    return result;
}

int NitroVM_DefaultCommand_GetFileOrDirectoryNameData(NitroVM* vm)
{
    FileDataStore* pStorage = vm->args_GetFileOrDirectoryNameData.output;
    FSReadDescription readDesc;

    readDesc.nitroHandle = vm->linkedHandle;
    readDesc.offset = vm->dirInfo.accessor.handleSubtableOffset;

    unsigned char stringLengthAndType;
    int result = Nitro_ReadMetadataBytes(&readDesc, &stringLengthAndType, 1);

    if (result != 0)
        return result;

    pStorage->stringLength = stringLengthAndType & 0x7f;
    pStorage->isDirectory = ((int)stringLengthAndType >> 7) & 1;
    
    if (pStorage->stringLength == 0)
        return NITRO_RESULT_FAILURE;

    if (!vm->args_GetFileOrDirectoryNameData.skipStoreString)
    {
        result = Nitro_ReadMetadataBytes(&readDesc, pStorage->name, pStorage->stringLength);
        if (result != NITRO_RESULT_SUCCESS)
            return result;

        pStorage->name[pStorage->stringLength] = '\0';
    }
    else // do skip over the string
    {
        readDesc.offset += pStorage->stringLength;
    }

    if (pStorage->isDirectory)
    {
        unsigned short directoryID;
        result = Nitro_ReadMetadataBytes(&readDesc, &directoryID, 2);
        if (result != NITRO_RESULT_SUCCESS)
            return result;
        pStorage->dir.handle = vm->linkedHandle;
        pStorage->dir.dirID = directoryID & 0xfff;
        pStorage->dir.firstFileID = 0;
        pStorage->dir.handleSubtableOffset = 0;
    }
    else
    {
        pStorage->file.handle = vm->linkedHandle;
        pStorage->file.fileID = vm->dirInfo.accessor.firstFileID;
        vm->dirInfo.accessor.firstFileID++;
    }
    
    vm->dirInfo.accessor.handleSubtableOffset = readDesc.offset;
    return result;
}

int NitroVM_DefaultCommand_GetFileOrDirectoryByName(NitroVM* vm)
{
    FileDataStore storage;
    const unsigned char* filePath = vm->args_GetFileOrDirectoryByName.path;
    CBool targetIsDirectory = vm->args_GetFileOrDirectoryByName.searchForDirectory;

    NitroVM_ExecuteCommand(vm, NITROVM_OPCODE_GET_DIRECTORY_DATA);
    
    // Parse the filename string in terms of tokens (i.e. directory names
    // followed by the final filename).
    if (filePath[0] != '\0')
    {
        do
        {
            int tokenLength = 0;
            // This variable is used for 2 different purposes: mainly to hold
            // a bool (whether the current token refers to a directory or the file)
            // but in the beginning, we use it to hold characters of the string
            int isParsingDirectory;
            goto SkipInitialIncrement;
            while (true)
            {
                tokenLength++;
            SkipInitialIncrement:
                int regularChar = false;
                isParsingDirectory = filePath[tokenLength];
                if (!(isParsingDirectory == '\0' || isParsingDirectory == '/' || isParsingDirectory == '\\'))
                    regularChar = true;
                if (!regularChar)
                    break;
            }

            // If this doesn't run, then isParsingDirectory = '\0' already, i.e. is false
            if (isParsingDirectory != '\0' || targetIsDirectory)
                isParsingDirectory = true;

            if (tokenLength == 0)
                return NITRO_RESULT_FAILURE;
            
            // Special treatment for directory names "." (this dir) and ".." (go up a dir)
            if (*filePath == '.')
            {
                if (tokenLength == 1)
                {
                    filePath++;
                    goto loopEnd;
                }
                // single & instead of &&. Probably originally a typo but means
                // the check doesn't short-circuit (and the bools cast to int)
                if (tokenLength == 2 & filePath[1] == '.')
                {
                    if (vm->dirInfo.accessor.dirID != 0)
                        NitroVM_LoadDirectoryDataByIndex(vm, vm->dirInfo.parentID);
                    filePath += 2;
                    goto loopEnd;
                }
            }

            if (tokenLength > 127)
                return NITRO_RESULT_FAILURE;

            vm->args_GetFileOrDirectoryNameData.output = &storage;
            vm->args_GetFileOrDirectoryNameData.skipStoreString = 0;
            while (true)
            {
                if (NitroVM_ExecuteCommand(vm, NITROVM_OPCODE_GET_FILE_OR_DIRECTORY_NAME_DATA) != NITRO_RESULT_SUCCESS)
                    return NITRO_RESULT_FAILURE;
                
                if (isParsingDirectory == storage.isDirectory && tokenLength == storage.stringLength
                && CaseInsensitiveStrncmp(filePath, storage.name, tokenLength) == 0)
                    break;
            }

            if (isParsingDirectory)
            {
                vm->args_GetDirectoryData.accessor = storage.dir;
                filePath += tokenLength;
                NitroVM_ExecuteCommand(vm, NITROVM_OPCODE_GET_DIRECTORY_DATA);
            }
            else
            {
                if (targetIsDirectory)
                    return NITRO_RESULT_FAILURE;

                volatile FileDataStore& volStorage = storage;
                NitroFileAccessor* output = (NitroFileAccessor*)vm->args_GetFileOrDirectoryByName.output;

                NitroHandle* nh = volStorage.file.handle;
                unsigned int fileID = volStorage.file.fileID;
                output->handle = nh;
                output->fileID = fileID;
                return NITRO_RESULT_SUCCESS;
            }

        loopEnd:
            filePath += filePath[0] != '\0' ? 1 : 0;
        } while (filePath[0] != '\0');
    }

    // I think we only get here if the final token represents a directory,
    // i.e. we're looking for a directory in the first place
    if (!targetIsDirectory)
        return NITRO_RESULT_FAILURE;
    
    // base registers a, b, c follow the right format for NitroDirectoryMetadata
    *((NitroDirectoryAccessor*)vm->args_GetFileOrDirectoryByName.output) = vm->dirInfo.accessor;
    return NITRO_RESULT_SUCCESS;
}
