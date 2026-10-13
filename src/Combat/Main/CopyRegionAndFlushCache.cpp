#include <globaldefs.h>
#include "System/Memory.h"
#include "System/Cache.h"

// USA: _Z23CopyRegionAndFlushCachePvPKvj
ARM unsigned int CopyRegionAndFlushCache(void* dst, const void* src, unsigned int length) {
    VectorizedInvertedMemcpy(src, dst, length);
    CleanInvalidateCacheRange(dst, length);
    return length;
}
