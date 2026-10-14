#include <globaldefs.h>

// USA: func_020e2ab0
ARM void SetSubWindow0In_020e2ab0(int val, int enableEffect) {
    volatile unsigned short* reg = (volatile unsigned short*)0x4001048;
    int r = (*reg & ~0x3f) | val;
    if (enableEffect) r |= 0x20;
    *reg = r;
}
