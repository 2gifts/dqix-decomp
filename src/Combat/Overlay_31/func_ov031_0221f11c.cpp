#include <globaldefs.h>
#include "System/Interrupts.h"

struct OperationState0221f11c {
    unsigned char padding[0x18];
    int state;
};
extern OperationState0221f11c data_ov031_0224f620;
extern "C" int _Z27DispatchOnZeroPair_0220cdd4ii(int, int);
typedef int (*DispatchPair0221f11c)(int, int, int);

// USA: func_ov031_0221f11c
extern "C" THUMB int func_ov031_0221f11c() {
    int irqState = DisableIRQInterrupts();
    if (data_ov031_0224f620.state == 5) {
        if (((DispatchPair0221f11c)_Z27DispatchOnZeroPair_0220cdd4ii)(0, 0, 0) == 3) {
            data_ov031_0224f620.state = 4;
            SetIRQInterruptState(irqState);
            return 1;
        }
    }
    SetIRQInterruptState(irqState);
    return 0;
}
