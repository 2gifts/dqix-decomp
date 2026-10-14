#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x1c2 };
#else
enum { FIELD_OFFSET = 0x1ce };
#endif

// USA: func_020398a4
ARM void ClearFlag0x1ceBit0x1_020398a4(unsigned char* obj) {
    obj[FIELD_OFFSET] &= ~1;
}
