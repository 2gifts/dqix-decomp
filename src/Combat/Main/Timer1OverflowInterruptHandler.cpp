#include <globaldefs.h>
#include "System/Interrupts.h"

// KEEP-NAME
// USA: func_020c6aa4
ARM void Timer1OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(5);
}
