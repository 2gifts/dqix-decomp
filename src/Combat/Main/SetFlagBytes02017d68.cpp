#include <globaldefs.h>

// USA: func_02017d68
ARM void SetFlagBytes02017d68(void* obj) {
    unsigned char* p = (unsigned char*)obj;
#if defined(jpn)
    *(unsigned char*)(p + 0x285d) = 1;
#else
    *(unsigned char*)(p + 0x281d) = 1;
#endif
#if defined(jpn)
    *(unsigned char*)(p + 0x285e) = 1;
#else
    *(unsigned char*)(p + 0x281e) = 1;
#endif
}
