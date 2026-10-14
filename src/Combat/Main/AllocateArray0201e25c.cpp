#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

struct Foo0201e25c {
    void* ptr;
    int   idx;
    int   count;
};

// USA: func_0201e25c
ARM void ZoneFeatures::AllocateOpcode64Entries(int count, SafeAllocator* alloc) {
    struct Foo0201e25c* obj = (struct Foo0201e25c*)this;
    obj->ptr = alloc->Allocate(count * 0x58);
    obj->idx = 0;
    obj->count = count;
}
