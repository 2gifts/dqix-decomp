#include <globaldefs.h>

// USA: func_020340f4
ARM void ClearByte0xc1Flag0x4_020340f4(unsigned char* obj) {
    obj[0xc1] &= ~4;
}
