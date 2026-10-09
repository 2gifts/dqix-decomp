#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct0205a198 {
    char data[0x28];
};
extern "C" void _Z12Init0205a198P14Struct0205a198(struct Struct0205a198*);
struct ClearTarget0205a234;
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(struct ClearTarget0205a234*);

struct Menu02172128 {
    char pad0[0x170];
    Struct0205a198* entries;
    ClearTarget0205a234* target;
    char pad1[0x1a78 - 0x178];
    SafeAllocator allocs[6];
    char pad2[0x1af8 - 0x1af0];
    SafeAllocator restAlloc;
};

// USA: func_ov000_02172128
extern "C" ARM void func_ov000_02172128(Menu02172128* self, SafeAllocator* allocator) {
    self->allocs[0].CreateTypeA(allocator->Allocate(0x400), 0x400);
    self->allocs[1].CreateTypeA(allocator->Allocate(0x1400), 0x1400);
    self->allocs[3].CreateTypeA(allocator->Allocate(0x2c00), 0x3000);
    self->allocs[2].CreateTypeA(allocator->Allocate(0x7000), 0x7000);
    self->allocs[1].Reset();
    self->allocs[2].Reset();
    self->allocs[4].CreateTypeA(allocator->Allocate(0x4266), 0x4266);
    self->allocs[5].CreateTypeA(allocator->Allocate(0xc00), 0xc00);
    self->entries = (Struct0205a198*)allocator->Allocate(0x640);
    for (unsigned char i = 0; i < 0x28; i++) {
        _Z12Init0205a198P14Struct0205a198(&self->entries[i]);
    }
    self->target = (ClearTarget0205a234*)allocator->Allocate(8);
    _Z23ClearField0And40205a234P19ClearTarget0205a234(self->target);
    unsigned int size = allocator->GetMaxPossibleAllocation();
    self->restAlloc.CreateTypeA(allocator->Allocate(size), size);
}
