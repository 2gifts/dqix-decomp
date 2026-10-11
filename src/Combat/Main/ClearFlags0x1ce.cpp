#include <globaldefs.h>

// USA: func_020397ac
ARM void ClearFlags0x1ce(unsigned char* obj, unsigned int mask) {
#if defined(jpn)
    obj[0x1c2] &= ~mask;
#else
    obj[0x1ce] &= ~mask;
#endif
}
