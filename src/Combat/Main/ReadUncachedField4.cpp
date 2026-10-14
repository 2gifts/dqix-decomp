#include <globaldefs.h>

void InvalidateDataCacheRange(const void* addr, unsigned int size);
extern int* data_021142c0;

// USA: func_020d29f4
ARM int ReadUncachedField4_020d29f4(void) {
    InvalidateDataCacheRange((const void*)(data_021142c0 + 1), 4);
    return data_021142c0[1];
}
