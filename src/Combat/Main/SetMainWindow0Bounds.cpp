#include <globaldefs.h>

// USA: func_020e2a54
ARM void SetMainWindow0Bounds_020e2a54(int x1, int y1, int x2, int y2) {
    *(volatile unsigned short*)0x4000040 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
    *(volatile unsigned short*)0x4000044 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
}
