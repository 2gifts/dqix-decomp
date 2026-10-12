#include <globaldefs.h>
#include <System/Interrupts.h>

struct SessionState {
    unsigned char padding[0x18];
    int state;
};

extern SessionState data_ov031_0224f620;
extern "C" int func_ov031_0220cce4();
extern "C" int func_ov031_0221ef80();

// USA: func_ov031_0221f190
extern "C" THUMB int func_ov031_0221f190() {
    int irqState = DisableIRQInterrupts();
    if (data_ov031_0224f620.state == 3) {
        if (func_ov031_0220cce4() != 3) {
            SetIRQInterruptState(irqState);
            return 0;
        }
        data_ov031_0224f620.state = 2;
        SetIRQInterruptState(irqState);
        return 1;
    }
    if (func_ov031_0221ef80() == 1) {
        data_ov031_0224f620.state = 2;
        SetIRQInterruptState(irqState);
        return 1;
    }
    SetIRQInterruptState(irqState);
    return 0;
}
