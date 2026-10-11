#include <globaldefs.h>

// USA: func_020119e8
ARM void ClearByte0x6480(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    (base + 0x6000)[0x200] = 0;
#else
    (base + 0x6000)[0x480] = 0;
#endif
}
