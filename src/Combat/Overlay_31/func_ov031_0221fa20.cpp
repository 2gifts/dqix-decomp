#include <globaldefs.h>
#include "System/Interrupts.h"

struct QueueState {
    char pad[0x68];
    int writeIndex;
    int readIndex;
};

extern QueueState data_ov031_0224f670;
extern void* data_ov031_0224f6f4[4];

// USA: func_ov031_0221fa20
extern "C" THUMB void* func_ov031_0221fa20() {
    int interruptState = DisableIRQInterrupts();
    int index = data_ov031_0224f670.readIndex;
    void* entry;
    if (data_ov031_0224f670.writeIndex == index) {
        entry = 0;
    } else {
        entry = data_ov031_0224f6f4[index];
        data_ov031_0224f670.readIndex = index + 1;
        if (data_ov031_0224f670.readIndex >= 4) data_ov031_0224f670.readIndex = 0;
    }
    SetIRQInterruptState(interruptState);
    return entry;
}
