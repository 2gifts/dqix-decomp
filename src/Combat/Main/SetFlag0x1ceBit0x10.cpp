#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x1c2 };
#else
enum { FIELD_OFFSET = 0x1ce };
#endif

// USA: func_02039dd8
ARM void SetFlag0x1ceBit0x10(unsigned char* obj) {
    obj[FIELD_OFFSET] |= 0x10;
}
