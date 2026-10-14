#include <globaldefs.h>

// USA: func_020e29b8
ARM void SetSubWindow1Bounds_020e29b8(int left, int top, int right, int bottom) {
    volatile unsigned short* reg = (volatile unsigned short*)0x4001042;
    reg[0] = ((left << 8) & 0xff00) | (right & 0xff);
    reg[2] = ((top << 8) & 0xff00) | (bottom & 0xff);
}
