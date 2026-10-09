#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"

struct Entry020966a0;
struct Foo0207df50;

struct ZoneStruct0219b938 {
    char pad0[0x498];
    Model3D models[2];

    Model3D* GetModel(int i) { return &models[i]; }
};

extern "C" struct ZoneStruct0219b938* func_02012fe4(void);
void InvokeAllEntries020966a0(struct Entry020966a0* entries);
extern "C" void func_0204719c(void* p);
void* GetData02109020(void);
extern "C" void func_0208f36c(void* p, int value);
void CopyInternalFields0207df50(struct Foo0207df50* p);

struct EntryIdList0219b938 {
    int ids[17];
};

extern struct EntryIdList0219b938 data_ov017_021d64b0;

struct Entry0219b938 {
    char data[0x88];
};

struct Battle0219b938 {
    char pad0[0x9c];
    SafeAllocator allocator;
    char padAllocatorEnd[0x4fc - 0x9c - sizeof(SafeAllocator)];
    char fields4fc[0x2b90 - 0x4fc];
    struct Entry0219b938 entries[0x14];
    char pad35d0[0x4328 - 0x2b90 - 0x14 * 0x88];
    struct Entry020966a0* callbacks;
};

// USA: func_ov017_0219b938
extern "C" ARM void func_ov017_0219b938(struct Battle0219b938* self) {
    struct ZoneStruct0219b938* zone = func_02012fe4();
    zone->GetModel(0)->Func0207e2e0();
    zone->GetModel(1)->Func0207e2e0();
    InvokeAllEntries020966a0(self->callbacks);
    struct EntryIdList0219b938 list = data_ov017_021d64b0;
    int i;
    for (i = 0; list.ids[i] >= 0; i++) {
        func_0204719c(&self->entries[list.ids[i]]);
    }
    func_0204719c(&self->entries[0x12]);
    func_0204719c(&self->entries[0x13]);
    func_0208f36c(GetData02109020(), 0);
    self->allocator.Reset();
    CopyInternalFields0207df50((struct Foo0207df50*)self->fields4fc);
}
