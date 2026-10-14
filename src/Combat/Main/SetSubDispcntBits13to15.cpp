#include <globaldefs.h>

// USA: func_020e2b78
ARM void SetSubDispcntBits13to15_020e2b78(int val) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~0xe000) | (val << 13);
}
