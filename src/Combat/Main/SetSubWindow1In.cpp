#include <globaldefs.h>

// USA: func_020e2a88
ARM void SetSubWindow1In_020e2a88(int val, int enableEffect) {
    volatile unsigned short* reg = (volatile unsigned short*)0x4001048;
    int r = (*reg & ~0x3f00) | (val << 8);
    if (enableEffect) r |= 0x2000;
    *reg = r;
}
