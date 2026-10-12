#include <globaldefs.h>
#include "System/Interrupts.h"

struct OperationState0221f158 {
    unsigned char padding[0x18];
    int state;
};
extern OperationState0221f158 data_ov031_0224f620;
extern "C" int func_ov031_0220d214();

// USA: func_ov031_0221f158
extern "C" THUMB int func_ov031_0221f158() {
    int irqState = DisableIRQInterrupts();
    if (data_ov031_0224f620.state == 7) {
        if (func_ov031_0220d214() == 3) {
            data_ov031_0224f620.state = 4;
            SetIRQInterruptState(irqState);
            return 1;
        }
    }
    SetIRQInterruptState(irqState);
    return 0;
}
