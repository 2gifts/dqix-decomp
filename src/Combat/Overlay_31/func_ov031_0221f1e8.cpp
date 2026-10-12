#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"

struct TransferState0221f1e8 {
    char pad_0[0xc];
    int mode;
    char pad_10[8];
    int status;
    int field_1c;
    void* primaryBuffer;
    void* secondaryBuffer;
};
extern TransferState0221f1e8 data_ov031_0224f620;
extern "C" void func_020ca408(const void*, void*, unsigned int);
extern "C" int func_ov031_0221ef80();
extern "C" int func_ov031_0220d010(void*, void*, int);

// USA: func_ov031_0221f1e8
extern "C" THUMB int func_ov031_0221f1e8(const void* primary, const void* secondary, int mode) {
    int interruptState = DisableIRQInterrupts();
    data_ov031_0224f620.mode = mode;
    if (secondary != 0)
        VectorizedInvertedMemcpy(secondary, data_ov031_0224f620.secondaryBuffer, 0x50);
    else
        VectorizedMemset(data_ov031_0224f620.secondaryBuffer, 0, 0x50);
    func_020ca408(primary, data_ov031_0224f620.primaryBuffer, 0xc0);
    if (func_ov031_0221ef80() == 1) {
        data_ov031_0224f620.status = 8;
        SetIRQInterruptState(interruptState);
        return 1;
    }
    if (data_ov031_0224f620.status == 3 &&
        func_ov031_0220d010(data_ov031_0224f620.primaryBuffer, data_ov031_0224f620.secondaryBuffer, data_ov031_0224f620.mode) == 3) {
        data_ov031_0224f620.status = 8;
        SetIRQInterruptState(interruptState);
        return 1;
    }
    SetIRQInterruptState(interruptState);
    return 0;
}
