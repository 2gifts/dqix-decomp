#include "System/Interrupts.h"
#include <globaldefs.h>

// USA: func_020c6a54
ARM void DMA0InterruptHandler(void) {
    OnDMAOrTimerCompletion(0);
}

// USA: func_020c6a64
ARM void DMA1InterruptHandler(void) {
    OnDMAOrTimerCompletion(1);
}

// USA: func_020c6a74
ARM void DMA2InterruptHandler(void) {
    OnDMAOrTimerCompletion(2);
}

// USA: func_020c6a84
ARM void DMA3InterruptHandler(void) {
    OnDMAOrTimerCompletion(3);
}
