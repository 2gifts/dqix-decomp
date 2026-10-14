#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

struct Foo0201e518 {
    char  pad[0x18];
    void* ptr;
    int   idx;
    int   count;
};

// USA: func_0201e518
ARM void ZoneFeatures::AllocateOpcode68Entries(int count, SafeAllocator* alloc) {
    struct Foo0201e518* obj = (struct Foo0201e518*)this;
    obj->ptr = alloc->Allocate(count * 0x70);
    obj->idx = 0;
    obj->count = count;
}
