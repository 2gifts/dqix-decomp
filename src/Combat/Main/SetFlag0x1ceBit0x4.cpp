#include <globaldefs.h>

// USA: func_02039d48
ARM void SetFlag0x1ceBit0x4(unsigned char* obj) {
#if defined(jpn)
    obj[0x1c2] |= 4;
#else
    obj[0x1ce] |= 4;
#endif
}
