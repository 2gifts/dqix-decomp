#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern char data_ov016_0219d0c0[];

#if defined(jpn)
static const int allocatorOffset = 0;
#else
static const int allocatorOffset = 8;
#endif

// USA: func_ov016_0218bc8c
ARM void* SafeAllocatorAllocate_0218bc8c(unsigned int byteCount) {
    SafeAllocator* allocator = *(SafeAllocator**)(data_ov016_0219d0c0 + allocatorOffset);
    return allocator->Allocate(byteCount);
}
