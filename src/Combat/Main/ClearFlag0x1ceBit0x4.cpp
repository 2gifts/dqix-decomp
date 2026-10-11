#include <globaldefs.h>

// USA: func_02039d58
ARM void ClearFlag0x1ceBit0x4(unsigned char* obj) {
#if defined(jpn)
    obj[0x1c2] &= ~4;
#else
    obj[0x1ce] &= ~4;
#endif
}
