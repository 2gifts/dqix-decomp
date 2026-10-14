#include <globaldefs.h>

// USA: func_020e2a20
ARM void SetMainWindow1Bounds_020e2a20(int x1, int y1, int x2, int y2) {
    *(volatile unsigned short*)0x4000042 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
    *(volatile unsigned short*)0x4000046 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
}
