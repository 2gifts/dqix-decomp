#include <globaldefs.h>

// USA: func_020546bc
ARM int GetSignedByte0x2d1_020546bc(void* obj) {
#if defined(jpn)
    return *(signed char*)((char*)obj + 0x2c5);
#else
    return *(signed char*)((char*)obj + 0x2d1);
#endif
}
