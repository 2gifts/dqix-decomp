#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Trans021842a0 {
    int field0;
    SafeAllocator allocator;
    int field18;
    int field1c;
};

// USA: func_ov011_021842a0  (semantic: Trans_021842a0)
extern "C" ARM void func_ov011_021842a0(Trans021842a0* self) {
    self->field0 = 0;
    self->allocator.ResetAllocatorPointer();
    self->field18 = 0;
    self->field1c = 0;
}
