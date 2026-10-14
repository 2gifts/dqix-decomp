#include <globaldefs.h>

struct SafeAllocator;
struct Foo0207df50;

struct Trans_021e8b6c_Obj {
    char pad[0x10];
    SafeAllocator* allocators[4];
    Foo0207df50* fields[4];
    unsigned char index;
};

void CopyInternalFields0207df50(Foo0207df50*);
extern "C" void _ZN13SafeAllocator5ResetEv(SafeAllocator*);
extern "C" void func_ov025_021e8bc4(Trans_021e8b6c_Obj*, unsigned int);

// USA: func_ov025_021e8b6c  (semantic: Trans_021e8b6c)
extern "C" ARM void func_ov025_021e8b6c(Trans_021e8b6c_Obj* self) {
    _ZN13SafeAllocator5ResetEv(self->allocators[self->index]);
    CopyInternalFields0207df50(self->fields[self->index]);
    func_ov025_021e8bc4(self, self->index);
}
