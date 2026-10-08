#include "System/DTCM.h"
#include "System/Interrupts.h"
#include <globaldefs.h>

extern BlockedContextList data_027e0060;

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