#include <globaldefs.h>

// USA: func_020119cc
ARM unsigned char GetByte0x646d(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    return (base + 0x6000)[0x1ed];
#else
    return (base + 0x6000)[0x46d];
#endif
}
