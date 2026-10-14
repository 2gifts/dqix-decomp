#include <globaldefs.h>

// USA: func_0203979c
ARM void SetFlags0x1ce_0203979c(unsigned char* obj, unsigned int mask) {
#if defined(jpn)
    obj[0x1c2] |= mask;
#else
    obj[0x1ce] |= mask;
#endif
}
