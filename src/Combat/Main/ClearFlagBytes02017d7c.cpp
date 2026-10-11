#include <globaldefs.h>

// USA: func_02017d7c
ARM void ClearFlagBytes02017d7c(void* obj) {
    unsigned char* p = (unsigned char*)obj;
#if defined(jpn)
    *(unsigned char*)(p + 0x285d) = 0;
#else
    *(unsigned char*)(p + 0x281d) = 0;
#endif
#if defined(jpn)
    *(unsigned char*)(p + 0x285e) = 0;
#else
    *(unsigned char*)(p + 0x281e) = 0;
#endif
}
