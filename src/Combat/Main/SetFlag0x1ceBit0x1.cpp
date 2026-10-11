#include <globaldefs.h>

// USA: func_02039894
ARM void SetFlag0x1ceBit0x1(unsigned char* obj) {
#if defined(jpn)
    obj[0x1c2] |= 1;
#else
    obj[0x1ce] |= 1;
#endif
}
