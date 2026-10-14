#include <globaldefs.h>

// USA: func_020e2ad8
ARM void SetWinInWin1_020e2ad8(unsigned int content, int colorEffect) {
    volatile unsigned short* winin = (volatile unsigned short*)0x4000048;
    unsigned int v = (*winin & ~0x3f00) | (content << 8);
    if (colorEffect) v |= 0x2000;
    *winin = v;
}
