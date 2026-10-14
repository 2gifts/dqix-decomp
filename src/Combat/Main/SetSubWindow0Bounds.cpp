#include <globaldefs.h>

// USA: func_020e29ec
ARM void SetSubWindow0Bounds_020e29ec(int x1, int y1, int x2, int y2) {
    *(volatile unsigned short*)0x4001040 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
    *(volatile unsigned short*)0x4001044 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
}
