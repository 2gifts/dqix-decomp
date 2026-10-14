#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021842c8(void* obj);

struct S021844a4 { char pad[0x9c]; void* f9c; unsigned int fa0; void* fa4; };

// USA: func_ov011_021844a4
ARM int SetAllocFields_021844a4(struct S021844a4* obj, void* p1, unsigned int size) {
    void* base = func_ov011_021842c8(obj);
    if (base == 0) return 1;
    void* r = ((SafeAllocator*)((char*)base + 4))->Allocate(size);
    obj->f9c = r;
    if (r == 0) return 1;
    obj->fa4 = p1;
    obj->fa0 = size;
    return 0;
}
