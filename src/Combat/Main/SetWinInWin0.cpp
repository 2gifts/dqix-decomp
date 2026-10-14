#include <globaldefs.h>

// USA: func_020e2b00
ARM void SetWinInWin0_020e2b00(unsigned int content, int colorEffect) {
    volatile unsigned short* winin = (volatile unsigned short*)0x4000048;
    unsigned int v = (*winin & ~0x3f) | content;
    if (colorEffect) v |= 0x20;
    *winin = v;
}
