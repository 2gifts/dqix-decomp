#include <globaldefs.h>
#include "System/Memory.h"
#include "System/Interrupts.h"

struct Transfer0221f854 {
    char pad[0x28];
    void* auxiliary;
    int state;
    char pad30[0x1c];
    void* payload;
    char pad50[8];
    int option;
};
extern Transfer0221f854 data_ov031_0224f670;
extern "C" void func_020ca408(void*, void*, int);
extern "C" THUMB int func_ov031_0221f630();
extern "C" int func_ov031_0220d010(void*, void*, int);

// USA: func_ov031_0221f854
extern "C" THUMB int func_ov031_0221f854(void* payload, void* auxiliary, int option) {
    int irqState = DisableIRQInterrupts();
    data_ov031_0224f670.option = option;
    if (auxiliary) VectorizedInvertedMemcpy(auxiliary, data_ov031_0224f670.auxiliary, 96);
    else VectorizedMemset(data_ov031_0224f670.auxiliary, 0, 96);
    func_020ca408(payload, data_ov031_0224f670.payload, 192);
    if (func_ov031_0221f630() == 1) {
        data_ov031_0224f670.state = 8;
        SetIRQInterruptState(irqState);
        return 1;
    }
    if (data_ov031_0224f670.state == 3 && func_ov031_0220d010(data_ov031_0224f670.payload, data_ov031_0224f670.auxiliary, data_ov031_0224f670.option) == 3) {
        data_ov031_0224f670.state = 8;
        SetIRQInterruptState(irqState);
        return 1;
    }
    SetIRQInterruptState(irqState);
    return 0;
}
