#include <globaldefs.h>
#include "System/Interrupts.h"

// KEEP-NAME
// USA: func_020c6a74
ARM void DMA2InterruptHandler(void) {
    OnDMAOrTimerCompletion(2);
}
