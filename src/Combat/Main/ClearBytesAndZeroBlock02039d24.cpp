#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02039d24
ARM void ClearBytesAndZeroBlock02039d24(unsigned char* obj) {
#if defined(jpn)
    obj[0x1bf] = 0;
#else
    obj[0x1cb] = 0;
#endif
#if defined(jpn)
    obj[0x1c0] = 0;
#else
    obj[0x1cc] = 0;
#endif
#if defined(jpn)
    obj[0x1c1] = 0;
#else
    obj[0x1cd] = 0;
#endif
#if defined(jpn)
    memset(obj + 0x1c4, 0, 0x80);
#else
    memset(obj + 0x1d0, 0, 0x80);
#endif
}
