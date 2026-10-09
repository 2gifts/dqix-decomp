#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct0205a198 {
    char data[0x28];
};
struct ClearTarget0205a234;
struct EntryManager020e2490;

extern "C" void _Z12Init0205a198P14Struct0205a198(Struct0205a198* s);
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(ClearTarget0205a234* t);
extern "C" void _Z24InitEntryManager020e2490P20EntryManager020e2490iiPvP13SafeAllocatorih(EntryManager020e2490* mgr, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag);

struct Obj02158a84 {
    SafeAllocator alloc0;
    SafeAllocator alloc14;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    SafeAllocator alloc50;
    char pad64[0xec - 0x64];
    Struct0205a198* entries;
    ClearTarget0205a234* clearTarget;
    char padf4[0x570 - 0xf4];
    EntryManager020e2490* entryManager;
};

// USA: func_ov003_02158a84
extern "C" ARM void func_ov003_02158a84(Obj02158a84* self, SafeAllocator* alloc) {
    if (alloc == NULL) {
        return;
    }
    self->alloc0.CreateTypeA(alloc->Allocate(0x4000), 0x4000);
    self->alloc14.CreateTypeA(alloc->Allocate(0x7000), 0x7000);
    self->alloc28.CreateTypeA(alloc->Allocate(0x8000), 0x8000);
    self->alloc3c.CreateTypeA(alloc->Allocate(0x800), 0x800);
    self->alloc50.CreateTypeA(alloc->Allocate(0x200), 0x200);
    self->entries = (Struct0205a198*)alloc->Allocate(0x230);
    for (int i = 0; i < 14; i++) {
        _Z12Init0205a198P14Struct0205a198(&self->entries[i]);
    }
    self->clearTarget = (ClearTarget0205a234*)alloc->Allocate(8);
    _Z23ClearField0And40205a234P19ClearTarget0205a234(self->clearTarget);
    self->alloc50.Reset();
    self->entryManager = (EntryManager020e2490*)self->alloc50.Allocate(0x24);
    _Z24InitEntryManager020e2490P20EntryManager020e2490iiPvP13SafeAllocatorih(self->entryManager, 0, 1, self->clearTarget, &self->alloc50, 4, 0x40);
}
