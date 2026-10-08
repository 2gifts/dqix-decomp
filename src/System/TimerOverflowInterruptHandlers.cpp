#include "System/Interrupts.h"
#include <globaldefs.h>

// USA: func_020c6a94
ARM void Timer0OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(4);
}

// USA: func_020c6aa4
ARM void Timer1OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(5);
}

// USA: func_020c6ab4
ARM void Timer2OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(6);
}

// USA: func_020c6ac4
ARM void Timer3OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(7);
}
