#include <globaldefs.h>
#include "System/Memory.h"
#include "System/Cache.h"

// USA: _Z20ClearAndInit020d84f8Pvj
ARM unsigned int ClearAndInit020d84f8(void* obj, unsigned int len) {
    VectorizedMemset(obj, 0, len);
    CleanInvalidateCacheRange(obj, len);
    return len;
}
