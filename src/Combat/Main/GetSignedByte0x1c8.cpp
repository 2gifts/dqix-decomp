#include <globaldefs.h>

// USA: func_02039860
ARM int GetSignedByte0x1c8_02039860(void* obj) {
#if defined(jpn)
    return *(signed char*)((char*)obj + 0x1bc);
#else
    return *(signed char*)((char*)obj + 0x1c8);
#endif
}
