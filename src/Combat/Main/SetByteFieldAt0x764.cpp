#include <globaldefs.h>

// USA: func_02026418
ARM void SetByteFieldAt0x764(unsigned char* obj, unsigned char value) {
#if defined(jpn)
    obj[0x6b8] = value;
#else
    obj[0x764] = value;
#endif
}
