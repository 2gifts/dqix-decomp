#include <globaldefs.h>

// USA: func_020546a8
ARM int GetSignedByte0x2d0_020546a8(void* obj) {
#if defined(jpn)
    return *(signed char*)((char*)obj + 0x2c4);
#else
    return *(signed char*)((char*)obj + 0x2d0);
#endif
}
