#include <globaldefs.h>

// USA: func_020884f8
ARM void ClearFlag0x80000AndBits0x3c_020884f8(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x80000;
    *(unsigned short*)(obj + 0x22) &= ~0x3c;
}
