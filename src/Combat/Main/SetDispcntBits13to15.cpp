#include <globaldefs.h>

// USA: func_020e2b94
ARM void SetDispcntBits13to15_020e2b94(int val) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0xe000) | (val << 13);
}
