#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020114c0
ARM void CopyInRegion0x571d(char* obj, int len, void* src) {
#if defined(jpn)
    memcpy(obj + 0x54bd, src, len);
#else
    memcpy(obj + 0x571d, src, len);
#endif
#if defined(jpn)
    *(unsigned char*)(obj + 0x54c1) = (unsigned char)len;
#else
    *(unsigned char*)(obj + 0x5721) = (unsigned char)len;
#endif
}
