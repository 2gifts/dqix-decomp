#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02011494
ARM unsigned char CopyOutRegion0x5718_02011494(char* obj, void* dst) {
#if defined(jpn)
    unsigned char len = *(unsigned char*)(obj + 0x54bc);
#else
    unsigned char len = *(unsigned char*)(obj + 0x571c);
#endif
#if defined(jpn)
    memcpy(dst, obj + 0x54b8, len);
#else
    memcpy(dst, obj + 0x5718, len);
#endif
#if defined(jpn)
    return *(unsigned char*)(obj + 0x54bc);
#else
    return *(unsigned char*)(obj + 0x571c);
#endif
}
