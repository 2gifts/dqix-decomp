#include <globaldefs.h>
#include "System/Cache.h"
#include "System/DMA.h"
#include "System/IPC.h"
#include "System/Interrupts.h"

struct InitData020c7de4;

extern "C" void _Z18InitStruct020c7de4P16InitData020c7de4ii(InitData020c7de4* queue, int messages, int count);
extern "C" int func_020c7e0c(void* queue, void* message, int flags);
void ClearBit0At027FFF96();
extern "C" void func_020d42e0(unsigned int command, unsigned int data, unsigned int error);

typedef void (*WMCallbackFunc)(void* arg);

struct WMArm9Buf
{
    void* WM7;
    void* status;
    unsigned long* indbuf;
    unsigned long* fifo9to7;
    unsigned long* fifo7to9;
    unsigned short dmaNo;
    unsigned short scanOnlyFlag;
    WMCallbackFunc CallbackTable[0x2c];
    WMCallbackFunc indCallback;
    WMCallbackFunc portCallbackTable[16];
    void* portCallbackArgument[16];
    unsigned long connectedAidBitmap;
    unsigned short myAid;
};

struct WMSystemState
{
    unsigned short wmInitialized;
    WMArm9Buf* wm9buf;
};

extern WMSystemState data_021142e0;
extern InitData020c7de4 data_021142e8;
extern void* data_02114308[10];
extern unsigned short data_02114380[10][0x80];

// USA: func_020d3df8
extern "C" ARM int func_020d3df8(void* sysBuf, unsigned short dmaNo, unsigned long bufSize)
{
    int lastState = DisableIRQInterrupts();
    if (data_021142e0.wmInitialized)
    {
        SetIRQInterruptState(lastState);
        return 3;
    }
    if (sysBuf == NULL)
    {
        SetIRQInterruptState(lastState);
        return 6;
    }
    if (dmaNo > 3)
    {
        SetIRQInterruptState(lastState);
        return 6;
    }
    if ((unsigned long)sysBuf & 0x1f)
    {
        SetIRQInterruptState(lastState);
        return 6;
    }
    InitializeInterProcessorCommunication();
    if (!IsIPCCommandHandlerRegistered(10, IPCSide_Arm7))
    {
        SetIRQInterruptState(lastState);
        return 4;
    }
    InvalidateDataCacheRange(sysBuf, bufSize);
    DMAMemsetSynchronous(dmaNo, (unsigned int)sysBuf, 0, bufSize);
    data_021142e0.wm9buf = (WMArm9Buf*)sysBuf;
    data_021142e0.wm9buf->WM7 = (unsigned char*)sysBuf + 0x200;
    data_021142e0.wm9buf->status = (unsigned char*)data_021142e0.wm9buf->WM7 + 0x300;
    data_021142e0.wm9buf->fifo9to7 = (unsigned long*)((unsigned char*)data_021142e0.wm9buf->status + 0x800);
    data_021142e0.wm9buf->fifo7to9 = (unsigned long*)((unsigned char*)data_021142e0.wm9buf->fifo9to7 + 0x100);
    ClearBit0At027FFF96();
    data_021142e0.wm9buf->dmaNo = dmaNo;
    data_021142e0.wm9buf->connectedAidBitmap = 0;
    data_021142e0.wm9buf->myAid = 0;
    for (int i = 0; i < 16; i++)
    {
        data_021142e0.wm9buf->portCallbackTable[i] = NULL;
        data_021142e0.wm9buf->portCallbackArgument[i] = NULL;
    }
    _Z18InitStruct020c7de4P16InitData020c7de4ii(&data_021142e8, (int)data_02114308, 10);
    for (int i = 0; i < 10; i++)
    {
        data_02114380[i][0] = 0x8000;
        CleanCacheRange(data_02114380[i], sizeof(unsigned short));
        func_020c7e0c(&data_021142e8, data_02114380[i], 1);
    }
    SetArm9IPCCommandHandler(10, func_020d42e0);
    data_021142e0.wmInitialized = true;
    SetIRQInterruptState(lastState);
    return 0;
}
