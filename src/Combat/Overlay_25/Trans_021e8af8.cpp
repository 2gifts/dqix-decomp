#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct SafeAllocator;
struct Foo0207df50;

struct Trans_021e8af8_Obj {
    char pad[0x10];
    SafeAllocator* allocators[4];
    Foo0207df50* fields[4];
    unsigned char index;
};

void CopyInternalFields0207df50(Foo0207df50*);
extern "C" void _ZN13SafeAllocator7DestroyEv(SafeAllocator*, unsigned int);
extern "C" void func_ov025_021e8bc4(Trans_021e8af8_Obj*, unsigned int);

// USA: func_ov025_021e8af8  (semantic: Trans_021e8af8)
extern "C" ARM void func_ov025_021e8af8(Trans_021e8af8_Obj* self) {
    if (self->index == 0) {
        return;
    }
    func_ov025_021e8bc4(self, self->index);
    void* signedAllocator = self->allocators[self->index]->GetSignedAllocator();
    _ZN13SafeAllocator7DestroyEv(self->allocators[self->index], self->index);
    self->allocators[self->index - 1]->Free(signedAllocator);
    CopyInternalFields0207df50(self->fields[self->index]);
    self->index--;
}
