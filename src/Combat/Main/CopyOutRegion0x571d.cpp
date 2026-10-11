#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020114ec
ARM unsigned char CopyOutRegion0x571d(char* obj, void* dst) {
#if defined(jpn)
    unsigned char len = *(unsigned char*)(obj + 0x54c1);
#else
    unsigned char len = *(unsigned char*)(obj + 0x5721);
#endif
#if defined(jpn)
    memcpy(dst, obj + 0x54bd, len);
#else
    memcpy(dst, obj + 0x571d, len);
#endif
#if defined(jpn)
    return *(unsigned char*)(obj + 0x54c1);
#else
    return *(unsigned char*)(obj + 0x5721);
#endif
}
