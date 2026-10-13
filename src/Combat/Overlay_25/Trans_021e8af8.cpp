#include <globaldefs.h>

struct SafeAllocator;
struct Foo0207df50;

struct Trans_021e8af8_Obj {
    char pad[0x10];
    SafeAllocator* allocators[4];
    Foo0207df50* fields[4];
    unsigned char index;
};

extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50*);
extern "C" void _ZN13SafeAllocator4FreeEPv(SafeAllocator*, void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(SafeAllocator*, unsigned int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(SafeAllocator*);
extern "C" void func_ov025_021e8bc4(Trans_021e8af8_Obj*, unsigned int);

// USA: func_ov025_021e8af8  (semantic: Trans_021e8af8)
extern "C" ARM void func_ov025_021e8af8(Trans_021e8af8_Obj* self) {
    if (self->index == 0) {
        return;
    }
    func_ov025_021e8bc4(self, self->index);
    void* signedAllocator = _ZNK13SafeAllocator18GetSignedAllocatorEv(self->allocators[self->index]);
    _ZN13SafeAllocator7DestroyEv(self->allocators[self->index], self->index);
    _ZN13SafeAllocator4FreeEPv(self->allocators[self->index - 1], signedAllocator);
    _Z26CopyInternalFields0207df50P11Foo0207df50(self->fields[self->index]);
    self->index--;
}
