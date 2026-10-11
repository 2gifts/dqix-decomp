#include <globaldefs.h>

// USA: func_02039888
ARM int GetSignedByte0x1ca(void* obj) {
#if defined(jpn)
    return *(signed char*)((char*)obj + 0x1be);
#else
    return *(signed char*)((char*)obj + 0x1ca);
#endif
}
