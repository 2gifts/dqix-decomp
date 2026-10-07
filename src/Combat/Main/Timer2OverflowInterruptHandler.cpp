#include <globaldefs.h>
#include "System/Interrupts.h"

// KEEP-NAME
// USA: func_020c6ab4
ARM void Timer2OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(6);
}
