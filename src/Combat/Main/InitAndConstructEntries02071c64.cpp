#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct S02071c64 {
    void* field0;
    void* field4;
    unsigned short field8;
    unsigned short fieldA;
};

extern "C" void func_02071b38(void* entry);

// USA: func_02071c64
extern "C" ARM void func_02071c64(struct S02071c64* self, void* allocator, unsigned int count) {
    if (self->field4 != 0) return;
    self->fieldA = 0;
    self->field8 = count;
    void* block = ((SafeAllocator*)allocator)->Allocate(count << 5);
    self->field4 = block;
    self->field0 = block;
    unsigned short i;
    for (i = 0; i < count; i++) {
        func_02071b38((char*)self->field4 + i * 0x20);
    }
}
