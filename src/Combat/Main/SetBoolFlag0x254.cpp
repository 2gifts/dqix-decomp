#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x248 };
#else
enum { FIELD_OFFSET = 0x254 };
#endif

// USA: func_0203983c
ARM void SetBoolFlag0x254(unsigned char* obj, int value) {
    obj[FIELD_OFFSET] = value != 0;
}
