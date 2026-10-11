#include <globaldefs.h>

// USA: func_02012034
ARM unsigned char GetByte0x7f70(void* obj) {
#if defined(jpn)
    return ((unsigned char*)obj + 0x7000)[0xc9c];
#else
    return ((unsigned char*)obj + 0x7000)[0xf70];
#endif
}
