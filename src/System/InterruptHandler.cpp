#include "System/Interrupts.h"
#include "System/DMA.h"
#include "System/BiosData.h"
#include "System/DTCM.h"
#include <globaldefs.h>
#include <asmhacks.h>

#pragma optimize_for_size off

#if defined(jpn)
#define data_0211127c data_02110f1c
#define data_020f2274 data_020f23e0
#endif

struct DMAOrTimerResponse
{
    DMACompletionCallback callback;
    unsigned int stayEnabledAfter;
    int userdata;
};

// 0-3 are DMA, 4-7 are timers
extern DMAOrTimerResponse data_0211127c[8];
// maps index in the previous array to interrupt ID
extern unsigned short data_020f2274[8];

inline DMACompletionCallback& CallbackByIndex(int n, int base = 0)
{
    return *(DMACompletionCallback*)((unsigned int)&data_0211127c[base].callback + n * sizeof(DMAOrTimerResponse));
}

inline unsigned int& ShouldStayEnabledByIndex(int n, int base = 0)
{
    return *(unsigned int*)((unsigned int)&data_0211127c[base].stayEnabledAfter + n * sizeof(DMAOrTimerResponse));
}

inline int& CallbackUserdataByIndex(int n, int base = 0)
{
    return *(int*)((unsigned int)&data_0211127c[base].userdata + n * sizeof(DMAOrTimerResponse));
}

// Start of exposed functions

void WaitForInterrupt(bool onlySubsequent, unsigned int mask)
{
    int priorState = DisableIRQInterrupts();
    if (onlySubsequent)
        DTCM_DATA.interruptsFired &= ~mask;
    SetIRQInterruptState(priorState);
    
    if (!(mask & DTCM_DATA.interruptsFired))
    {
        BlockedContextList* list = &data_027e0000.block_60;
        unsigned int* pData;
        do {
            pData = &DTCM_DATA.interruptsFired;
            BlockCurrentContext(list);
        } while (!(mask & *pData));
    }
    DECLARE_ASM_NOP();
}

void EmptyInterruptHandler() {}

// This function matches with wrong registers
void OnDMAOrTimerCompletion(int index)
{
    unsigned int irqId = data_020f2274[index];
    unsigned int irqMask = 1 << irqId;

    DMACompletionCallback callback = CallbackByIndex(index);
    CallbackByIndex(index) = NULL;

    if (callback != NULL)
        callback(CallbackUserdataByIndex(index));
        
    
    unsigned int stayEnabled = 0;
    
    DTCMData& itcm = DTCM_DATA;
    stayEnabled = ShouldStayEnabledByIndex(index);
    itcm.interruptsFired |= irqMask;
    

    if (!stayEnabled)
    {
        DisableSpecificInterrupts(irqMask);
    }
}

void InitializeInterruptContextBlock_020c6ad4()
{
    BlockedContextList& list = GetInterruptDataBlockedContextList();
    list.first = list.last = NULL;
}
