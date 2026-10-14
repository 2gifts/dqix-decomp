#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_02011a24
ARM void CopyInToRegion0x6482_02011a24(char* obj, void* src) {
#if defined(jpn)
    VectorizedInvertedMemcpy(src, obj + 0x6202, 0x1c);
#else
    VectorizedInvertedMemcpy(src, obj + 0x6482, 0x1c);
#endif
}
