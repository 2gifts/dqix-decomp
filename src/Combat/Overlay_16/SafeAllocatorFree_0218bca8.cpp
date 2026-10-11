#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern char data_ov016_0219d0c0[];

#if defined(jpn)
static const int allocatorOffset = 0;
#else
static const int allocatorOffset = 8;
#endif

// Paired with SafeAllocatorAllocate_0218bc8c through the same overlay-owned allocator.
// SafeAllocator decides whether freeing releases one allocation or resets its arena.
// USA: func_ov016_0218bca8
// JPN: func_ov016_0218c788
ARM void SafeAllocatorFree_0218bca8(void* allocation) {
    SafeAllocator* allocator = *(SafeAllocator**)(data_ov016_0219d0c0 + allocatorOffset);
    allocator->Free(allocation);
}
