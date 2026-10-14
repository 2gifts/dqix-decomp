#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// USA: func_02092a74
ARM void CreateTypeAFromAllocator_02092a74(SafeAllocator* self, SafeAllocator* src) {
    void* buf;
    if (src == NULL) return;
    buf = src->Allocate(0x800);
    self->CreateTypeA(buf, 0x800);
}
