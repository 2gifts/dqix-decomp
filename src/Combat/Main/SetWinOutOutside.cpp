#include <globaldefs.h>

// USA: func_020e2b50
ARM void SetWinOutOutside_020e2b50(unsigned int content, int colorEffect) {
    volatile unsigned short* winout = (volatile unsigned short*)0x400004a;
    unsigned int v = (*winout & ~0x3f) | content;
    if (colorEffect) v |= 0x20;
    *winout = v;
}
