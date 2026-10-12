#include <globaldefs.h>
#include "System/Memory.h"

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

#if defined(jpn)
#define ClearAndInit020d84f8 func_020d9e5c
extern "C" ARM unsigned int ClearAndInit020d84f8(void* obj, unsigned int len);
#endif

// USA: _Z20ClearAndInit020d84f8Pvj
ARM unsigned int ClearAndInit020d84f8(void* obj, unsigned int len) {
    VectorizedMemset(obj, 0, len);
    CleanInvalidateCacheRange((const void*)((int)obj), len);
    return len;
}
