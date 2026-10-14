#include <globaldefs.h>

// USA: func_02039888
ARM int GetSignedByte0x1ca_02039888(void* obj) {
#if defined(jpn)
    return *(signed char*)((char*)obj + 0x1be);
#else
    return *(signed char*)((char*)obj + 0x1ca);
#endif
}
