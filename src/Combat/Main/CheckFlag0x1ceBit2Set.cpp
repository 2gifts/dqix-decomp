#include <globaldefs.h>

// USA: func_02039d68
ARM int CheckFlag0x1ceBit2Set_02039d68(unsigned char* obj) {
#if defined(jpn)
    return (obj[0x1c2] & 4) != 0;
#else
    return (obj[0x1ce] & 4) != 0;
#endif
}
