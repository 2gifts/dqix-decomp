#include <globaldefs.h>

// USA: func_020daf54
ARM int GetReg04001000Field8_020daf54(void) {
    volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
    return (*reg & 0x1f00) >> 8;
}
