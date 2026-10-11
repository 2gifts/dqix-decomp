#include <globaldefs.h>

void ReleaseHandleField340(void*);

// USA: func_020939fc
ARM void ClearFlag0x3c9Bit0AndCleanup(unsigned char* obj) {
#if defined(jpn)
    obj[0x139] &= ~1;
#else
    obj[0x3c9] &= ~1;
#endif
    ReleaseHandleField340(obj);
}
