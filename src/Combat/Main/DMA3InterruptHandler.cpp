#include <globaldefs.h>
#include "System/Interrupts.h"

// KEEP-NAME
// USA: func_020c6a84
ARM void DMA3InterruptHandler(void) {
    OnDMAOrTimerCompletion(3);
}
