#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

// USA: func_02012d88
ARM void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size) {
    void* p = alloc->Allocate((size + 3) & ~3);
    if (p == NULL)
        return NULL;
    return p;
}
