#include <globaldefs.h>
#include <System/DMA.h>
#include <System/DTCM.h>

struct DMAOrTimerResponse
{
    DMACompletionCallback callback;
    unsigned int stayEnabledAfter;
    int userdata;
};

extern DMAOrTimerResponse data_0211127c[8];
extern unsigned short data_020f2274[8];

unsigned int DisableSpecificInterrupts(unsigned int flagMask);

// USA: func_020c69cc // KEEP-NAME
ARM void OnDMAOrTimerCompletion(int index)
{
    unsigned int mask = 1 << data_020f2274[index];
    DMACompletionCallback callback = data_0211127c[index].callback;
    data_0211127c[index].callback = NULL;
    if (callback != NULL)
        callback(data_0211127c[index].userdata);
    DTCM_DATA_INTERRUPTS_FIRED |= mask;
    if (!data_0211127c[index].stayEnabledAfter)
        DisableSpecificInterrupts(mask);
}
