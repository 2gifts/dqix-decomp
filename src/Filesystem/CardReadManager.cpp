#include "Filesystem/FSInnerDefs.h"
#include "System/BiosData.h"
#include "System/Memory.h"
#include "System/Interrupts.h"
#include "System/Cache.h"
#include "System/DMA.h"
#include <globaldefs.h>
#include <asmhacks.h>

#pragma optimize_for_size off

#define ADDR_ITCM_START 0x01ff8000
#define ADDR_ITCM_END 0x02000000

#define ADDR_GAMECARD_BUS_ROMCTRL 0x040001a4
#define ADDR_GAMECARD_RECEIVED_DATA 0x04100010
#define GAMECARD_BUS_COMMAND_BYTE(n) *(unsigned char*)(0x040001a8 + n)

#define ROMCTRL_FLAG_WORD_READY (1u << 23)
#define ROMCTRL_FLAG_BUSY (1u << 31)

void SendTaskToReadContext(CardReadManager::ReadProc);

extern "C"
{
    extern "C" unsigned int _Z29GetDataTcmRegionBase_020c89e4v();

    extern "C" void _Z25StartDmaWithFlush020ca8e8jjjj(unsigned int dmaChannel, const void* readFrom, void* writeTo, unsigned int length);

    extern "C" void _Z32RegisterType0x11Handler_020d1118v();

    extern "C" void _Z33SyncIfBufferValueChanged_020d1234j(unsigned int);
}

void WaitForReadManagerIdle_Internal();
Struct_02111f20::LowLevelReadProc GetLowLevelCartridgeReadProc();

extern "C" bool TransferScratchBuffer(Struct_02111f20* input)
{
    CardReadManager* ptr = &data_021118e0;
    unsigned int romCurrentBlockStart = ptr->cartridgeReadOffset & 0xfffffe00;
    if (romCurrentBlockStart == (unsigned int)input->alignedWrite)
    {
        unsigned int offsetFromAlignment = ptr->cartridgeReadOffset
            - romCurrentBlockStart;
        unsigned int usefulLength = 0x200 - offsetFromAlignment;
        if (usefulLength > ptr->writeLength)
            usefulLength = ptr->writeLength;

        VectorizedInvertedMemcpy(input->scratchBuffer + offsetFromAlignment,
            ptr->writeDst, usefulLength);
        ptr->cartridgeReadOffset += usefulLength;
        ptr->writeDst += usefulLength;
        ptr->writeLength -= usefulLength;
    }
    return ptr->writeLength != 0;
}

void SendGamecardBusCommand(unsigned int firstWord, unsigned int secondWord)
{
    volatile unsigned int* control = (unsigned int*)ADDR_GAMECARD_BUS_ROMCTRL;
    while (*control & ROMCTRL_FLAG_BUSY) {}

    *(unsigned char*)0x40001a1 = 0xC0;

    GAMECARD_BUS_COMMAND_BYTE(0) = firstWord >> 24;
    GAMECARD_BUS_COMMAND_BYTE(1) = firstWord >> 16;
    GAMECARD_BUS_COMMAND_BYTE(2) = firstWord >> 8;
    GAMECARD_BUS_COMMAND_BYTE(3) = firstWord >> 0;

    GAMECARD_BUS_COMMAND_BYTE(4) = secondWord >> 24;
    GAMECARD_BUS_COMMAND_BYTE(5) = secondWord >> 16;
    GAMECARD_BUS_COMMAND_BYTE(6) = secondWord >> 8;
    GAMECARD_BUS_COMMAND_BYTE(7) = secondWord >> 0;
}

void ReadSingleSegmentFromCartridge()
{
    CardReadManager* readManager = &data_021118e0;
    void* gamecardReceivedDataRegister = (void*)ADDR_GAMECARD_RECEIVED_DATA;
    Struct_02111f20* ps1f20 = &data_02111f00.innerStruct;

    DECLARE_ASM_NOP();

    _Z25StartDmaWithFlush020ca8e8jjjj(readManager->dmaChannel, gamecardReceivedDataRegister, readManager->writeDst, 0x200);
    unsigned int offset = readManager->cartridgeReadOffset;
    SendGamecardBusCommand(0xb7000000 | (offset >> 8), offset << 24);
    *(unsigned int*)ADDR_GAMECARD_BUS_ROMCTRL = ps1f20->control_4;
}

void DMAChainSegmentInterruptHandler()
{
    ResetDMAChannel(data_021118e0.dmaChannel);

    CardReadManager* manager = &data_021118e0;

    manager->cartridgeReadOffset += 512;
    manager->writeDst += 512;
    manager->writeLength -= 512;

    bool moreToWrite = manager->writeLength != 0;

    if (!moreToWrite)
    {
        DisableSpecificInterrupts(IRQ_MASK_GAMECARD_DATA_TRANSFER_DONE);
        AcknowledgeSpecificInterrupts(IRQ_MASK_GAMECARD_DATA_TRANSFER_DONE);
        CardReadManager* readManager = &data_021118e0;
        unsigned int romChipID = SetupNormalGamecardBusCommandMode();
        _Z33SyncIfBufferValueChanged_020d1234j(romChipID);

        readManager->pSharedData->unknown_0 = 0;
        CardReadManager::CompletionCallback cleanProc = readManager->onComplete;
        NitroHandle* handle = readManager->handle;

        int oldState = DisableIRQInterrupts();
        readManager->flags &= ~((1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS) | (1 << READ_MANAGER_FLAG_CONTEXT_HAS_TASK_PENDING) | (1 << CARTRIDGE_READ_CONTEXT_FLAG_6));
        UnblockContexts(&readManager->ongoingReadBlock);

        if (readManager->flags & (1 << CARTRIDGE_READ_CONTEXT_FLAG_4))
            MarkContextReadyAndSwitch(&readManager->cartridgeReadContext);
        SetIRQInterruptState(oldState);

        if (cleanProc != NULL)
            cleanProc(handle);
    }
    else
    {
        DECLARE_ASM_NOP();
        ReadSingleSegmentFromCartridge();
    }
}

extern "C" bool TryReadViaDMA(Struct_02111f20* handler)
{
    CardReadManager* readManager = &data_021118e0;
    unsigned int length = readManager->writeLength;

    bool canDoDMARead = false;
    bool readAlignedToCartridgeSegments = false;
    bool destinationIsSuitableMemoryType = false;
    bool destinationIsCacheAligned = false;

    unsigned int destination = (unsigned int)readManager->writeDst;
    unsigned int alignmentMod32 = (unsigned int)destination & 0x1f;

    if (alignmentMod32 == 0 && ((readManager->dmaChannel <= 3)))
        destinationIsCacheAligned = true;

    if (destinationIsCacheAligned)
    {
        unsigned int dtcmBase = _Z29GetDataTcmRegionBase_020c89e4v();
        bool isDTCM = true;
        bool isITCM = false;
        if (destination + length > ADDR_ITCM_START && destination < ADDR_ITCM_END)
            isITCM = true;

        if (!isITCM && (dtcmBase >= destination + length || dtcmBase + 0x4000 <= destination))
            isDTCM = false;

        if (!isDTCM)
            destinationIsSuitableMemoryType = true;
    }

    if (destinationIsSuitableMemoryType && ((readManager->cartridgeReadOffset | length) & 0x1ff) == 0)
        readAlignedToCartridgeSegments = true;

    if (readAlignedToCartridgeSegments && length != 0)
        canDoDMARead = true;

    handler->control_4 = (data_020f22cc->gamecardBusControlNormalSettings & ~0x07000000) | 0xa1000000;

    if (canDoDMARead)
    {
        int oldState = DisableIRQInterrupts();
        if (length < readManager->instructionCacheCleanThreshold)
            InvalidateInstructionCacheRange((void*)destination, length);
        else
            InvalidateInstructionCache();

        if (length < readManager->dataCacheCleanThreshold)
        {
            if (alignmentMod32 != 0)
            {
                destination -= alignmentMod32;
                CleanCacheRange((void*)destination, 0x20);
                CleanCacheRange((void*)(destination + length), 0x20);
                length += 0x20;
            }
            InvalidateDataCacheRange((void*)destination, length);
            DrainWriteBuffer();
        }
        else
        {
            CleanInvalidateDataCache();
        }

        SetInterruptHandler(IRQ_MASK_GAMECARD_DATA_TRANSFER_DONE, &DMAChainSegmentInterruptHandler);
        AcknowledgeSpecificInterrupts(IRQ_MASK_GAMECARD_DATA_TRANSFER_DONE);
        EnableSpecificInterrupts(IRQ_MASK_GAMECARD_DATA_TRANSFER_DONE);
        SetIRQInterruptState(oldState);
        ReadSingleSegmentFromCartridge();
    }

    return canDoDMARead;
}

extern "C" void ReadBlocksFromCartridge(Struct_02111f20* handler)
{
    CardReadManager* readManager = &data_021118e0;
    while (true)
    {
        unsigned int alignedOffset = readManager->cartridgeReadOffset & 0xfffffe00;
        unsigned int* practicalWriteLoc;
        if (alignedOffset != readManager->cartridgeReadOffset ||
            ((unsigned int)readManager->writeDst & 3) ||
            readManager->writeLength < 0x200)
        {
            handler->alignedWrite = (unsigned int*)alignedOffset;
            practicalWriteLoc = (unsigned int*)handler->scratchBuffer;
        }
        else
            practicalWriteLoc = (unsigned int*)readManager->writeDst;
        SendGamecardBusCommand(0xb7000000 | (alignedOffset >> 8), alignedOffset << 24);
        *(volatile unsigned int*)ADDR_GAMECARD_BUS_ROMCTRL = handler->control_4;

        unsigned int control;
        int wordIndex = 0;
        unsigned int bytesCopied = 0;
        do {
            control = *(volatile unsigned int*)ADDR_GAMECARD_BUS_ROMCTRL;
            if (control & ROMCTRL_FLAG_WORD_READY)
            {
                unsigned int data = *(volatile unsigned int*)ADDR_GAMECARD_RECEIVED_DATA;
                if (bytesCopied < 0x200)
                {
                    practicalWriteLoc[wordIndex] = data;
                    bytesCopied += 4;
                    wordIndex++;
                }
            }
        } while (control & ROMCTRL_FLAG_BUSY);

        if (practicalWriteLoc == (unsigned int*)readManager->writeDst)
        {
            unsigned int remainingLength;
            CardReadManager* manager = &data_021118e0;
            manager->cartridgeReadOffset += 0x200;
            manager->writeDst += 0x200;
            remainingLength = manager->writeLength - 0x200;
            manager->writeLength = remainingLength;
            if (remainingLength != 0)
                continue;
            break;
        }
        else if (!TransferScratchBuffer(handler))
            break;
    }
}

unsigned int SetupNormalGamecardBusCommandMode()
{
    SendGamecardBusCommand(0xb8000000, 0x00000000);
    unsigned int newSettings = data_020f22cc->gamecardBusControlNormalSettings;
    newSettings &= ~0x07000000;
    newSettings |=  0xa7000000;
    newSettings &=  0xffffe000;
    *(volatile unsigned int*)ADDR_GAMECARD_BUS_ROMCTRL = newSettings;
    do {
    } while ((*(volatile unsigned int*)ADDR_GAMECARD_BUS_ROMCTRL & ROMCTRL_FLAG_WORD_READY) == 0);
    return *(volatile unsigned int*)ADDR_GAMECARD_RECEIVED_DATA;
}

extern "C" void SafeReadBlocksFromCartridge(CardReadManager*)
{
    Struct_02111f20* rawHandler = &data_02111f00.innerStruct;
    if (TransferScratchBuffer(rawHandler))
    {
        Struct_02111f20::LowLevelReadProc readProc = rawHandler->lowLevelReadProc;
        readProc(rawHandler);
    }

    CardReadManager* readManager = &data_021118e0;
    unsigned int romChipID = SetupNormalGamecardBusCommandMode();
    _Z33SyncIfBufferValueChanged_020d1234j(romChipID);

    readManager->pSharedData->unknown_0 = 0;
    CardReadManager::CompletionCallback callback = readManager->onComplete;
    NitroHandle* handle = readManager->handle;

    int oldState = DisableIRQInterrupts();
    readManager->flags &= ~((1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS) | (1 << READ_MANAGER_FLAG_CONTEXT_HAS_TASK_PENDING) | (1 << CARTRIDGE_READ_CONTEXT_FLAG_6));
    UnblockContexts(&readManager->ongoingReadBlock);

    if (readManager->flags & (1 << CARTRIDGE_READ_CONTEXT_FLAG_4))
        MarkContextReadyAndSwitch(&readManager->cartridgeReadContext);
    SetIRQInterruptState(oldState);

    if (callback != NULL)
        callback(handle);

    DECLARE_ASM_NOP();
}

void LoadDataFromCartridgeToMemory(unsigned int dmaChannel,
    unsigned int cartridgeOffset, void* dest, unsigned int length,
    CardReadManager::CompletionCallback onComplete, NitroHandle* handle, CBool async)
{
    Struct_02111f20* rawHandler = &data_02111f00.innerStruct;
    CardReadManager* readManager = &data_021118e0;
    VerifyCardReadManagerInitialized();

    int oldState = DisableIRQInterrupts();

    while (readManager->flags & (1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS))
    {
        BlockCurrentContext(&readManager->ongoingReadBlock);
    }
    readManager->flags |= (1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS);
    readManager->onComplete = onComplete;
    readManager->handle = handle;
    SetIRQInterruptState(oldState);
    readManager->cartridgeReadOffset = cartridgeOffset + data_02111f00.number;
    readManager->dmaChannel = dmaChannel;
    readManager->writeDst = (unsigned char*)dest;
    readManager->writeLength = length;

    if (dmaChannel <= 3)
        ResetDMAChannel(dmaChannel);

    if (TryReadViaDMA(rawHandler))
    {
        if (!async)
            WaitForReadManagerIdle_Internal();
    }
    else if (async)
    {
        SendTaskToReadContext(&SafeReadBlocksFromCartridge);
    }
    else
    {
        readManager->currentTaskExecutionContext = data_02111304.activeContext;
        SafeReadBlocksFromCartridge(readManager);
    }
}

void InitializeCardReading()
{
    CardReadManager* readManager = &data_021118e0;
    if (readManager->flags != 0)
        return;

    readManager->flags = (1 << CARTRIDGE_READ_CONTEXT_FLAG_0);
    readManager->writeLength = 0;
    readManager->writeDst = NULL;
    readManager->cartridgeReadOffset = 0;
    readManager->dmaChannel = -1;
    readManager->onComplete = NULL;
    readManager->handle = NULL;

    data_02111f00.number = 0;
    InitializeCardReadManager();
    data_02111f00.innerStruct.lowLevelReadProc = GetLowLevelCartridgeReadProc();
    _Z32RegisterType0x11Handler_020d1118v();
}

void WaitForReadManagerIdle_Internal()
{
    AwaitCardReadManagerIdle();
}

Struct_02111f20::LowLevelReadProc GetLowLevelCartridgeReadProc()
{
    return &ReadBlocksFromCartridge;
}

void IPCCommand11Proc(unsigned int command, unsigned int argument, unsigned int flag)
{
    if (command != 11 || !flag)
        return;

    CardReadManager* manager = (CardReadManager*)&data_021118e0;

    ProcessorContext* context = manager->currentTaskExecutionContext;
    manager->flags &= ~(1 << READ_MANAGER_FLAG_AWAITING_ARM7_ACTION);

    MarkContextReadyAndSwitch(context);
}

void CartridgeReadContextLoop()
{
    CardReadManager* readManager = &data_021118e0;
    while (true)
    {
        int priorState = DisableIRQInterrupts();
        if (!(readManager->flags & (1 << READ_MANAGER_FLAG_CONTEXT_HAS_TASK_PENDING)))
        {
            do {
                BlockCurrentContext(NULL);
            } while (!(readManager->flags & (1 << READ_MANAGER_FLAG_CONTEXT_HAS_TASK_PENDING)));
        }
        SetIRQInterruptState(priorState);
        readManager->cartridgeReadProc(readManager);
    }
}
