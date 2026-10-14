#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

struct Foo0201e480 {
    char  pad[0xc];
    void* ptr;
    int   idx;
    int   count;
};

// USA: func_0201e480
ARM void ZoneFeatures::AllocateOpcode66Entries(int count, SafeAllocator* alloc) {
    struct Foo0201e480* obj = (struct Foo0201e480*)this;
    obj->ptr = alloc->Allocate(count * 0x24);
    obj->idx = 0;
    obj->count = count;
}
