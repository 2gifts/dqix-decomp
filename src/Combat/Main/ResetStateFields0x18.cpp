#include <globaldefs.h>

// USA: func_020883cc
ARM void ResetStateFields0x18_020883cc(unsigned char* obj) {
    obj[0x21] = 0;
    *(int*)(obj + 0x18) &= ~0x20;
    obj[0x5e] = 3;
    obj[0x81] = 0;
    *(int*)(obj + 0x14) |= 0x20;
}
