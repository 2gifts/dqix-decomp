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

int NitroVM_DefaultCommand_GetFATEntry(NitroVM* vm)
{
    unsigned int offsets[2]; // [0] = start, [1] = end
    FSReadDescription readHandle;

    unsigned int entryIdx = vm->args_GetFATEntry.accessor.fileID;
    if (vm->linkedHandle->fatSize <= entryIdx * 8)
        return 1;
    
    readHandle.nitroHandle = vm->linkedHandle;

    // Dumb way to write readHandle.offset = fatOffset + entryIdx * 8
    int off = readHandle.nitroHandle->fatOffsetFast;
    readHandle.offset = entryIdx * 8;
    off += readHandle.offset;
    readHandle.offset = off;

    int result = Nitro_ReadMetadataBytes(&readHandle, &offsets, 8);
    if (result != NITRO_RESULT_SUCCESS)
        return result;

    vm->args_SetFilePointers.startOffset = offsets[0];
    vm->args_SetFilePointers.endOffset = offsets[1];
    vm->args_SetFilePointers.fileID = entryIdx;

    return NitroVM_ExecuteCommand(vm, NITROVM_OPCODE_SET_FILE_POINTERS);
}

int NitroVM_DefaultCommand_SetFilePointers(NitroVM* vm)
{
    vm->fileInfo.startOffset = vm->args_SetFilePointers.startOffset;
    vm->fileInfo.cursorPos = vm->args_SetFilePointers.startOffset;
    vm->fileInfo.endOffset = vm->args_SetFilePointers.endOffset;
    vm->fileInfo.fileID = vm->args_SetFilePointers.fileID;
    return NITRO_RESULT_SUCCESS;
}

int NitroVM_DefaultCommand_Nop(NitroVM* vm)
{
    return NITRO_RESULT_SUCCESS;
}

unsigned int Nitro_CalculateSignature(const char* str, int len)
{
    unsigned int signature = 0;

    if (len <= 3)
    {
        int idx = 0; 
        if (len > 0)
        {   
            int bitshift = 0;
            
            do {
                if ((unsigned char)str[idx] == '\0')
                    break;
                
                // Convert to lowercase
                unsigned int charValue = (unsigned char)str[idx] - 'A';
                if (charValue <= 'Z' - 'A')
                    charValue += 'a';
                else
                    charValue += 'A';

                idx++;
                signature |= charValue << bitshift;
                bitshift += 8;
            } while (idx < len);
        }
    }

    return signature;
}

int DefaultNitroReadProc(NitroHandle* handle, void* dst, unsigned int offset, unsigned int len)
{
    VectorizedInvertedMemcpy((const unsigned char*)handle->pFileImage + offset, dst, len);
    return NITRO_RESULT_SUCCESS;
}

int DefaultNitroWriteProc(NitroHandle* handle, const void* src, unsigned int offset, unsigned int len)
{
    VectorizedInvertedMemcpy(src, (unsigned char*)handle->pFileImage + offset, len);
    return NITRO_RESULT_SUCCESS;
}

int MemoryMappedMetadataReadProc(NitroHandle* handle, void* dst, unsigned int offset, unsigned int len)
{
    VectorizedInvertedMemcpy((void*)offset, dst, len);
    return NITRO_RESULT_SUCCESS;
}

NitroVM* NitroHandle_AdvanceCommandQueue(NitroHandle* handle)
{
    int oldState = DisableIRQInterrupts();
    if (GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_VM_LIST_DIRTY))
    {
        handle->flags &= ~(1 << NITROHANDLE_FLAG_VM_LIST_DIRTY);
        NitroVM* currentVM = handle->linkToFirstVM.pNext;
        if (currentVM != NULL)
        {
            do {
                NitroVM* nextVM = currentVM->links.pNext;
                if (GET_FLAG_BIT(currentVM->flags, NITROVM_FLAG_MARKED_FOR_UNLINK_FROM_HANDLE))
                {
                    if (handle->linkToFirstVM.pNext == currentVM)
                        handle->linkToFirstVM.pNext = nextVM;
                    NitroVM_UnlinkAndStoreResult(currentVM, NITRO_RESULT_INVALID_HANDLE);
                    // Effect of this: if last VM in the list marked for unlink,
                    // need to do another pass through...?
                    if (nextVM == NULL)
                        nextVM = handle->linkToFirstVM.pNext;
                }
                currentVM = nextVM;
            } while (currentVM != NULL);
        }
    }

    if (!GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_AWAITING_BUS_RELEASE) && !GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_QUEUE_PAUSED))
    {
        NitroVM* vm = handle->linkToFirstVM.pNext;
        if (vm != NULL)
        {
            int flagCleared = !GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_NDS_BUS_HELD);
            if (flagCleared)
                handle->flags |= (1 << NITROHANDLE_FLAG_NDS_BUS_HELD);
            SetIRQInterruptState(oldState);
            if (flagCleared && (handle->overrideOpcodeFlags & (1 << NITROVM_OPCODE_ACQUIRE_NDS_BUS)))
                handle->instructionOverride(vm, NITROVM_OPCODE_ACQUIRE_NDS_BUS);
            oldState = DisableIRQInterrupts();
            vm->flags |= (1 << NITROVM_FLAG_READY_TO_EXECUTE);
            if (GET_FLAG_BIT(vm->flags, NITROVM_FLAG_SYNCHRONOUS))
            {
                UnblockContexts(&vm->blockedContexts);
                SetIRQInterruptState(oldState);
                return NULL;
            }
            else
            {
                SetIRQInterruptState(oldState);
                return vm;
            }
        }
    }

    if (GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_NDS_BUS_HELD))
    {
        handle->flags &= ~(1 << NITROHANDLE_FLAG_NDS_BUS_HELD);
        if (handle->overrideOpcodeFlags & (1 << NITROVM_OPCODE_RELEASE_NDS_BUS))
        {
            NitroVM tempVM;
            NitroVM_Initialize(&tempVM);
            tempVM.linkedHandle = handle;
            handle->instructionOverride(&tempVM, NITROVM_OPCODE_RELEASE_NDS_BUS);
        }
    }

    if (GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_AWAITING_BUS_RELEASE))
    {
        handle->flags = (handle->flags & ~(1 << NITROHANDLE_FLAG_AWAITING_BUS_RELEASE)) | (1 << NITROHANDLE_FLAG_QUEUE_PAUSED);
        UnblockContexts(&handle->busReleaseBlock);
    }

    SetIRQInterruptState(oldState);
    return NULL;
}

void NitroVM_ProcessReadyCommandQueueEntries(NitroVM* queueHead)
{
    NitroVM* vm = queueHead;
    NitroHandle* handle = vm->linkedHandle;
    if (vm != NULL)
    {
        do
        {
            int oldState = DisableIRQInterrupts();
            vm->flags |= (1 << NITROVM_FLAG_READY_TO_EXECUTE);
            if (GET_FLAG_BIT(vm->flags, NITROVM_FLAG_SYNCHRONOUS))
            {
                UnblockContexts(&vm->blockedContexts);
                SetIRQInterruptState(oldState);
                break;
            }
            vm->flags |= (1 << NITROVM_FLAG_EXECUTING_FROM_QUEUE);
            SetIRQInterruptState(oldState);

            if (NitroVM_ExecuteCommand(vm, vm->pendingCommand) == NITRO_RESULT_TASK_STILL_RUNNING)
                break;

            vm = NitroHandle_AdvanceCommandQueue(handle);
        } while (vm != NULL);
    }
}

CBool NitroVM_ExecuteAndUnlink(NitroVM* vm)
{
    int result = NitroVM_ExecuteCommand(vm, vm->pendingCommand);
    NitroVM_UnlinkAndStoreResult(vm, result);

    NitroVM* maybeMainVM = NitroHandle_AdvanceCommandQueue(vm->linkedHandle);
    if (maybeMainVM != NULL)
        NitroVM_ProcessReadyCommandQueueEntries(maybeMainVM);

    return vm->storedResult == NITRO_RESULT_SUCCESS;
}

CBool NitroVM_QueueCommand(NitroVM* vm, int opcode)
{
    NitroHandle* handle = vm->linkedHandle;
    vm->pendingCommand = opcode;
    vm->storedResult = NITRO_RESULT_UNDEFINED;
    int opcodeMask = 1 << opcode;
    vm->flags |= (1 << NITROVM_FLAG_IN_HANDLE_QUEUE);

    int oldState = DisableIRQInterrupts();
    if (handle->flags & (1 << NITROHANDLE_FLAG_DESTRUCTION_UNDERWAY))
    {
        NitroVM_UnlinkAndStoreResult(vm, NITRO_RESULT_INVALID_HANDLE);
        SetIRQInterruptState(oldState);
        return false;
    }

    // if opcode is between 2 and 8 (inclusive)
    if (opcodeMask & 0x1fc)
        vm->flags |= (1 << NITROVM_FLAG_SYNCHRONOUS);

    NitroVM* lastAttachedVM;
    // At least one of these needs to be a volatile read
    NitroVM* previous = *(NitroVM* volatile*)&vm->links.pPrev;
    NitroVM* next = *(NitroVM* volatile*)&vm->links.pNext;
    
    // Move vm to end of the list
    if (previous)
        previous->links.pNext = next;
    
    lastAttachedVM = (NitroVM*)&handle->linkToFirstVM;
    if (next)
        next->links.pPrev = previous;
    
    if (lastAttachedVM->links.pNext)
    {
        NitroVM* loopVM = lastAttachedVM->links.pNext;
        do {
            lastAttachedVM = loopVM;
            loopVM = loopVM->links.pNext;
        } while (loopVM != NULL);
    }
    
    lastAttachedVM->links.pNext = vm;
    vm->links.pPrev = lastAttachedVM;
    vm->links.pNext = NULL;

    if (!GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_QUEUE_PAUSED) && !GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_NDS_BUS_HELD))
    {
        // Claim: if we get here, the queue was empty, so can execute this VM already
        handle->flags |= (1 << NITROHANDLE_FLAG_NDS_BUS_HELD);
        SetIRQInterruptState(oldState);
        if (handle->overrideOpcodeFlags & (1 << NITROVM_OPCODE_ACQUIRE_NDS_BUS))
            handle->instructionOverride(vm, NITROVM_OPCODE_ACQUIRE_NDS_BUS);
        int oldState = DisableIRQInterrupts();
        vm->flags |= (1 << NITROVM_FLAG_READY_TO_EXECUTE);
        if (!GET_FLAG_BIT(vm->flags, NITROVM_FLAG_SYNCHRONOUS))
        {
            SetIRQInterruptState(oldState);
            NitroVM_ProcessReadyCommandQueueEntries(vm);
            return true;
        }
        SetIRQInterruptState(oldState);
    }
    else
    {
        if (!GET_FLAG_BIT(vm->flags, NITROVM_FLAG_SYNCHRONOUS))
        {
            SetIRQInterruptState(oldState);
            return true;
        }

        do
        {
            BlockCurrentContext(&vm->blockedContexts);
        } while (!(vm->flags & (1 << NITROVM_FLAG_READY_TO_EXECUTE)));
        SetIRQInterruptState(oldState);
    }
    return NitroVM_ExecuteAndUnlink(vm);
}