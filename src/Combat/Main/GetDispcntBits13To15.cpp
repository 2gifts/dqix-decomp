#include <globaldefs.h>

// USA: func_020e2bc4
ARM int GetDispcntBits13To15_020e2bc4(void) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    return (*dispcnt & 0xe000) >> 13;
}
