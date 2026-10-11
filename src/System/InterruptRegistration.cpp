#include "System/DTCM.h"
#include "System/Interrupts.h"
#include <globaldefs.h>

struct DMAOrTimerResponse {
    DMACompletionCallback callback;
    unsigned int stayEnabledAfter;
    int userdata;
};

extern DMAOrTimerResponse data_0211127c[8];

inline DMACompletionCallback &CallbackByIndex(int n, int base = 0) {
    return *(DMACompletionCallback *) ((unsigned int) &data_0211127c[base].callback + n * sizeof(DMAOrTimerResponse));
}

inline unsigned int &ShouldStayEnabledByIndex(int n, int base = 0) {
    return *(unsigned int *) ((unsigned int) &data_0211127c[base].stayEnabledAfter + n * sizeof(DMAOrTimerResponse));
}

inline int &CallbackUserdataByIndex(int n, int base = 0) {
    return *(int *) ((unsigned int) &data_0211127c[base].userdata + n * sizeof(DMAOrTimerResponse));
}

// KEEP-NAME: shared mask/opaque handler interface serves two callback signatures.
// USA: func_020c6aec
ARM void SetInterruptHandler(unsigned int mask, const void *proc) {
    int dmaTimerIndex;
    int interruptID;

    interruptID = 0;
    do {
        if (mask & 1) {
            DMAOrTimerResponse *dmaTimerData = NULL;
            if (interruptID >= 8 && interruptID <= 11) {
                int dmaTimerIndex = interruptID - 8;
                dmaTimerData      = &data_0211127c[dmaTimerIndex];
            } else if (interruptID >= 3 && interruptID <= 6) {
                dmaTimerIndex = interruptID + 1;
                dmaTimerData  = &data_0211127c[dmaTimerIndex];
            } else {
                data_027e0000.interruptProcTable[interruptID] = (InterruptHandlerProc) proc;
            }

            if (dmaTimerData != NULL) {
                dmaTimerData->callback         = (DMACompletionCallback) proc;
                dmaTimerData->userdata         = 0;
                dmaTimerData->stayEnabledAfter = true;
            }
        }
        interruptID++;
        mask >>= 1;
    } while (interruptID < 22);
}

// USA: func_020c6b74
// KEEP-NAME: curated interrupt-handler lookup interface.
ARM InterruptHandlerProc GetInterruptHandler(unsigned int mask) {
    int interruptId             = 0;
    InterruptHandlerProc *pProc = &data_027e0000.interruptProcTable[0];
    do {
        if (!(mask & 1)) continue;

        if (interruptId >= 8 && interruptId <= 11) {
            return (InterruptHandlerProc) data_0211127c[interruptId - 8].callback;
        } else if (interruptId >= 3 && interruptId <= 6) {
            return (InterruptHandlerProc) data_0211127c[interruptId + 1].callback;
        } else {
            return *pProc;
        }

    } while (interruptId++, mask >>= 1, pProc++, interruptId < 22);
    return NULL;
}

// KEEP-NAME
// USA: func_020c6c00
ARM void SetDMACompletionCallback(int channel, DMACompletionCallback callback, int userdata) {
    CallbackByIndex(channel)          = callback;
    CallbackUserdataByIndex(channel)  = userdata;
    unsigned int previousInterruptMask                = EnableSpecificInterrupts(IRQ_MASK_DMA_N(channel));
    ShouldStayEnabledByIndex(channel) = previousInterruptMask & IRQ_MASK_DMA_N(channel);
}

// KEEP-NAME
// USA: func_020c6c48
ARM void SetTimerOverflowCallback(int timer, DMACompletionCallback callback, int userdata) {
    CallbackByIndex(timer, 4)         = callback;
    CallbackUserdataByIndex(timer, 4) = userdata;
    EnableSpecificInterrupts(IRQ_MASK_TIMER_N_OVERFLOW(timer));
    ShouldStayEnabledByIndex(timer, 4) = true;
}
