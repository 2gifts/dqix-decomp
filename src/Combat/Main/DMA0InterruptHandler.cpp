#include <globaldefs.h>
#include "System/Interrupts.h"

// KEEP-NAME
// USA: func_020c6a54
ARM void DMA0InterruptHandler(void) {
    OnDMAOrTimerCompletion(0);
}
