#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern char data_ov016_0219d0c0[];

#if defined(jpn)
static const int allocatorOffset = 0;
#else
static const int allocatorOffset = 8;
#endif

// Uses the same overlay-owned allocator as SafeAllocatorFree_0218bca8.
// Allocation rounding and synchronization remain the responsibility of SafeAllocator.
// USA: func_ov016_0218bc8c
// JPN: func_ov016_0218c76c
ARM void* SafeAllocatorAllocate_0218bc8c(unsigned int byteCount) {
    SafeAllocator* allocator = *(SafeAllocator**)(data_ov016_0219d0c0 + allocatorOffset);
    return allocator->Allocate(byteCount);
}
