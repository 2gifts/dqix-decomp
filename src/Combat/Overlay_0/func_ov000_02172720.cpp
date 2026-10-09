#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Obj0205d048;
struct List0204afb4;
extern "C" void func_0205d048(struct Obj0205d048* obj);
extern "C" void _Z23ResetRecordList0204afb4P12List0204afb4(struct List0204afb4* obj);
extern "C" void _Z17ResetSlot02170054Pv(void* obj);

struct Slot_02172720 {
    char pad0[0x448];
};

struct Owner_02172720 {
    char pad0[0x188];
    char field_0x188[0x8a4 - 0x188];
    char list8a4[0x20];
    char list8c4[0x20];
    char pad8e4[0x90c - 0x8e4];
    int taskId;
    char pad910[0x958 - 0x910];
    Slot_02172720 slots[4];
    SafeAllocator alloc1a78;
    SafeAllocator alloc1a8c;
    SafeAllocator alloc1aa0;
    SafeAllocator alloc1ab4;
    SafeAllocator alloc1ac8;
    SafeAllocator alloc1adc;
    char pad1af0[0x1af8 - 0x1af0];
    SafeAllocator alloc1af8;
    char pad1b0c[0x1d72 - 0x1b0c];
    unsigned short flags;
};

struct Data02184288 {
    int field0;
    int field4;
    int field8;
};
extern struct Data02184288 data_ov000_02184288;

extern "C" void func_ov000_02172850(Owner_02172720* self);

// USA: func_ov000_02172720
extern "C" ARM void func_ov000_02172720(Owner_02172720* self) {
    if (self->taskId >= 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
    }
    func_0205d048((struct Obj0205d048*)self->field_0x188);
    _Z23ResetRecordList0204afb4P12List0204afb4((struct List0204afb4*)self->list8c4);
    _Z23ResetRecordList0204afb4P12List0204afb4((struct List0204afb4*)self->list8a4);
    SafeAllocator* allocs[7] = {
        &self->alloc1aa0,
        &self->alloc1ab4,
        &self->alloc1ac8,
        &self->alloc1adc,
        &self->alloc1af8,
        &self->alloc1a78,
        &self->alloc1a8c,
    };
    for (int i = 0; i < 7; i++) {
        SafeAllocator* alloc = allocs[i];
        if (alloc->GetSignedAllocator() != 0) {
            alloc->Destroy();
        }
    }
    for (int i = 0; i < 4; i++) {
        _Z17ResetSlot02170054Pv(&self->slots[i]);
    }
    func_ov000_02172850(self);
    self->flags &= 0x40;
    data_ov000_02184288.field8 = 0;
}
