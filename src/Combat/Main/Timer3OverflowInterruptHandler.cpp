#include <globaldefs.h>
#include "System/Interrupts.h"

// KEEP-NAME
// USA: func_020c6ac4
ARM void Timer3OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(7);
}
