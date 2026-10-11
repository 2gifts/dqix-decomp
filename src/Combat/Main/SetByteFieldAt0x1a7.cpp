#include <globaldefs.h>

// USA: func_02053ec0
ARM void SetByteFieldAt0x1a7(unsigned char* obj, unsigned char value) {
#if defined(jpn)
    obj[0x19b] = value;
#else
    obj[0x1a7] = value;
#endif
}
