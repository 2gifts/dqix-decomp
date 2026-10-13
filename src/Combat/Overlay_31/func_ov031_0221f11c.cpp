#include <globaldefs.h>
#include "System/Interrupts.h"

struct OperationState0221f11c {
    unsigned char padding[0x18];
    int state;
};
extern OperationState0221f11c data_ov031_0224f620;
int DispatchOnZeroPair_0220cdd4(int, int, int);

// USA: func_ov031_0221f11c
extern "C" THUMB int func_ov031_0221f11c() {
    int irqState = DisableIRQInterrupts();
    if (data_ov031_0224f620.state == 5) {
        if (DispatchOnZeroPair_0220cdd4(0, 0, 0) == 3) {
            data_ov031_0224f620.state = 4;
            SetIRQInterruptState(irqState);
            return 1;
        }
    }
    SetIRQInterruptState(irqState);
    return 0;
}
