#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov003_0217db88(void);
int PopStack0AndTrigger_020a1e54(int a);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern int data_02114e20;
extern "C" void func_020a0c0c(void);

struct Obj020dae08 {
    char pad0;
    char field1;
    char pad2[0xc - 2];
    int field0xc;
    char pad3[0x14 - 0xc - 4];
    SafeAllocator allocator;
};

// USA: func_020dae08  (semantic: ShutdownTask020dae08)
extern "C" ARM void func_020dae08(struct Obj020dae08* self) {
    if (self->field0xc != 0) {
        func_ov003_0217db88();
        self->field0xc = 0;
        PopStack0AndTrigger_020a1e54(1);
    }
    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
    }
    func_020a0c0c();
    self->field1 = 1;
}
