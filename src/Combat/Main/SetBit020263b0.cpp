#include <globaldefs.h>

// USA: func_020263b0
ARM void SetBit020263b0(unsigned char* obj, unsigned int index) {
    if (index < 4) {
#if defined(jpn)
        obj[0x6B1] |= 1 << index;
#else
        obj[0x75D] |= 1 << index;
#endif
    }
}
