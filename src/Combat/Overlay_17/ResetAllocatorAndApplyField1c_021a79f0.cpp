#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

int GetGlobal02109400(void);
void BlankFunction02094b38(void);
struct Obj02094ab0;
extern "C" void func_02094ab0(struct Obj02094ab0* obj);
extern "C" void func_020a0c0c(void);
void TailForward02012da4(AllocatorUnion*, void*);
extern AllocatorUnion data_02114e20;

struct Obj021a79f0 {
    unsigned char pad0[0x1c];
    int field1c;
#if defined(jpn)
    unsigned char pad2[0x1ec - 0x20];
#else
    unsigned char pad2[0x25c - 0x20];
#endif
    SafeAllocator allocator;
};

// JPN: func_ov017_021a8380
// USA: func_ov017_021a79f0  (semantic: ResetAllocatorAndApplyField1c_021a79f0)
extern "C" ARM void func_ov017_021a79f0(struct Obj021a79f0* self) {
    void* g = (void*)GetGlobal02109400();
    ((void (*)(void*, int)) & BlankFunction02094b38)(g, 0x205);
    func_02094ab0((struct Obj02094ab0*)g);

    void* handle = self->allocator.GetSignedAllocator();
    if (handle != NULL) {
        self->allocator.Destroy();
        TailForward02012da4(&data_02114e20, handle);
    }

    func_020a0c0c();
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | (self->field1c << 8);
}
