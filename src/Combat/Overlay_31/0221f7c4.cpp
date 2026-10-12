#include "globaldefs.h"
#include "System/Interrupts.h"

struct OperationState0221f7c4 {
    unsigned char padding[0x2c];
    int state;
};

extern OperationState0221f7c4 data_ov031_0224f670;
extern "C" int func_ov031_0220d214(void);

// USA: func_ov031_0221f7c4
extern "C" THUMB int func_ov031_0221f7c4(void) {
    int irqState = DisableIRQInterrupts();
    if (data_ov031_0224f670.state == 7) {
        if (func_ov031_0220d214() == 3) {
            data_ov031_0224f670.state = 4;
            SetIRQInterruptState(irqState);
            return 1;
        }
    }
    SetIRQInterruptState(irqState);
    return 0;
}
