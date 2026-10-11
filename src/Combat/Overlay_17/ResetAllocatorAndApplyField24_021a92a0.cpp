#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

int GetGlobal02109400(void);
void BlankFunction02094b38(void);
struct Obj02094ab0;
extern "C" void func_02094ab0(struct Obj02094ab0* obj);
extern "C" int func_ov017_0218b5b0(void);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void TailForward02012da4(AllocatorUnion*, void*);
extern AllocatorUnion data_02114e20;

struct Obj021a92a0 {
    unsigned char pad0[0x24];
    int field24;
#if defined(jpn)
    unsigned char pad1[0x1f4 - 0x28];
#else
    unsigned char pad1[0x264 - 0x28];
#endif
    SafeAllocator allocator;
};

// JPN: func_ov017_021a9a84
// USA: func_ov017_021a92a0  (semantic: ResetAllocatorAndApplyField24_021a92a0)
extern "C" ARM void func_ov017_021a92a0(struct Obj021a92a0* self) {
    void* g = (void*)GetGlobal02109400();
    ((void (*)(void*, int)) & BlankFunction02094b38)(g, 0x205);
    func_02094ab0((struct Obj02094ab0*)g);

    void* handle = self->allocator.GetSignedAllocator();
    if (handle != NULL) {
        self->allocator.Destroy();
        TailForward02012da4(&data_02114e20, handle);
    }

    ClearBitsInField4((unsigned int*)func_ov017_0218b5b0(), 0x40);
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | (self->field24 << 8);
}
