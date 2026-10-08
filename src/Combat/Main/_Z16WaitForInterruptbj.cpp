#include "System/DTCM.h"
#include "System/Interrupts.h"
#include <globaldefs.h>

extern BlockedContextList data_027e0060;

// Clears any of `mask` that is already pending when `onlySubsequent` is set, restores the prior
// IRQ state, then blocks this context on the interrupt block queue until one of the requested
// interrupts has fired. Every access to the fired-interrupt word goes through `dtcm` so the
// literal pool holds 0x027e0000 exactly once.
// KEEP-NAME
// USA: func_020c6954
extern "C" ARM void _Z16WaitForInterruptbj(bool onlySubsequent, unsigned int mask) {
    DTCMData *dtcm = &DTCM_DATA;
    int priorState = DisableIRQInterrupts();

    if (onlySubsequent) {
        dtcm->interruptsFired &= ~mask;
    }

    SetIRQInterruptState(priorState);

    if (mask & dtcm->interruptsFired) {
        return;
    }

    unsigned int *fired = (unsigned int *) ((char *) dtcm + 0x3ff8);
    do {
        BlockCurrentContext(&data_027e0060);
    } while (!(mask & *fired));
}