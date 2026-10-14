#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" int func_ov017_0218b5b0(void);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);

extern int data_02114e20;

struct Obj021bef84 {
    char pad[0x44];
    SafeAllocator allocator;
};

// USA: func_ov017_021bef84  (semantic: ClearAllocatorAndBits_021bef84)
extern "C" ARM void func_ov017_021bef84(struct Obj021bef84* self) {
    int h = func_ov017_0218b5b0();
    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
    }
    ClearBitsInField4_0203b4e8((unsigned int*)h, 0xc0);
}
