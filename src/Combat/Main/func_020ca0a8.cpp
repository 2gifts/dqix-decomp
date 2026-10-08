#include <globaldefs.h>
#include "System/DMA.h"
#include "System/Interrupts.h"

#define REG_GXSTAT (*(volatile unsigned long*)0x04000600)

typedef void (*GXCommandDMACallback)(void* arg);

struct GXCommandDMAParams
{
    volatile int isBusy;
    unsigned long channel;
    unsigned long src;
    unsigned long length;
    GXCommandDMACallback callback;
    void* arg;
    unsigned long fifoInterruptCondition;
    InterruptHandlerProc fifoInterruptHandler;
};

extern GXCommandDMAParams data_02111684;

extern "C" void func_020ca1a0();

static inline void SetFifoInterruptCondition(unsigned long condition)
{
    REG_GXSTAT = (condition << 30) | (REG_GXSTAT & ~0xc0000000);
}

static inline void CallCallback(GXCommandDMACallback callback, void* arg)
{
    if (callback)
    {
        callback(arg);
    }
}

// USA: func_020ca0a8
extern "C" ARM void func_020ca0a8(unsigned long channel, const void* src, unsigned long length,
    GXCommandDMACallback callback, void* arg)
{
    if (length == 0)
    {
        CallCallback(callback, arg);
        return;
    }

    while (data_02111684.isBusy)
    {
    }

    while (!(((REG_GXSTAT & 0x07000000) >> 24) & 2))
    {
    }

    data_02111684.isBusy = 1;
    data_02111684.channel = channel;
    data_02111684.src = (unsigned long)src;
    data_02111684.length = length;
    data_02111684.callback = callback;
    data_02111684.arg = arg;

    VerifyDMASource(channel, (unsigned long)src, length, 0);
    AwaitDMACompletion(channel);

    {
        int priorState = DisableIRQInterrupts();

        data_02111684.fifoInterruptCondition = (REG_GXSTAT & 0xc0000000) >> 30;
        data_02111684.fifoInterruptHandler = GetInterruptHandler(0x200000);

        SetFifoInterruptCondition(1);
        SetInterruptHandler(0x200000, (const void*)func_020ca1a0);
        EnableSpecificInterrupts(0x200000);
        func_020ca1a0();

        SetIRQInterruptState(priorState);
    }
}
