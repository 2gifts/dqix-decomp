#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_020119f8
ARM unsigned char CopyToRegion0x6482IfDst(char* obj, void* dst) {
    if (dst != NULL) {
#if defined(jpn)
        VectorizedInvertedMemcpy(obj + 0x6202, dst, 0x1c);
#else
        VectorizedInvertedMemcpy(obj + 0x6482, dst, 0x1c);
#endif
    }
#if defined(jpn)
    return *(unsigned char*)(obj + 0x6200);
#else
    return *(unsigned char*)(obj + 0x6480);
#endif
}
