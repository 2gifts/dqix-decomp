#include <globaldefs.h>
#include "System/Memory.h"

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

#if defined(jpn)
#define CopyRegionAndFlushCache func_020d9e88
extern "C" ARM unsigned int CopyRegionAndFlushCache(void* dst, const void* src, unsigned int length);
#endif

// USA: _Z23CopyRegionAndFlushCachePvPKvj
ARM unsigned int CopyRegionAndFlushCache(void* dst, const void* src, unsigned int length) {
    VectorizedInvertedMemcpy(src, dst, length);
    CleanInvalidateCacheRange((const void*)((int)dst), length);
    return length;
}
