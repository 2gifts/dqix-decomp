#include <globaldefs.h>
#include "System/Interrupts.h"

// KEEP-NAME
// USA: func_020c6a64
ARM void DMA1InterruptHandler(void) {
    OnDMAOrTimerCompletion(1);
}
