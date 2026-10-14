#include <globaldefs.h>

// USA: func_0203d018
ARM void ClearField0x98Bit0_0203d018(unsigned char* obj) {
    *(int*)(obj + 0x98) &= ~1;
}
