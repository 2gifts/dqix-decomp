#include <globaldefs.h>

#if defined(jpn)
#define DestroySafeAllocator_021fbe4c func_ov023_021fb1c8
#endif
#include "Memory/SafeAllocator.h"

struct Obj021fbe4c {
    char pad[0x20];
    SafeAllocator allocator;
};

// USA: func_ov023_021fbe4c
#if defined(jpn)
extern "C"
#endif
ARM void DestroySafeAllocator_021fbe4c(struct Obj021fbe4c* self) {
    if (self->allocator.GetSignedAllocator() == NULL) return;
    self->allocator.Destroy();
}
