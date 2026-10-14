#include <globaldefs.h>

// USA: func_0203986c
ARM void SetByte0x1c9_0203986c(unsigned char* obj, int value) {
#if defined(jpn)
    obj[0x1bd] = value;
#else
    obj[0x1c9] = value;
#endif
}
