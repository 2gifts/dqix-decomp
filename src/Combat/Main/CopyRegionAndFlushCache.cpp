#include <globaldefs.h>
#include "System/Memory.h"
#include "System/Cache.h"

// USA: _Z32CopyRegionAndFlushCache_020d8524PvPKvj
ARM unsigned int CopyRegionAndFlushCache_020d8524(void* dst, const void* src, unsigned int length) {
    VectorizedInvertedMemcpy(src, dst, length);
    CleanInvalidateCacheRange(dst, length);
    return length;
}
