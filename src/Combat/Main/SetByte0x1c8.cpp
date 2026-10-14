#include <globaldefs.h>

// USA: func_02039858
ARM void SetByte0x1c8_02039858(unsigned char* obj, int value) {
#if defined(jpn)
    obj[0x1bc] = value;
#else
    obj[0x1c8] = value;
#endif
}
