#include <globaldefs.h>
#include "System/Interrupts.h"

// KEEP-NAME
// USA: func_020c6a94
ARM void Timer0OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(4);
}
