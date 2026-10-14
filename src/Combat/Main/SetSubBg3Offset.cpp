#include <globaldefs.h>

// USA: func_0204a6ec
ARM void SetSubBg3Offset_0204a6ec(int x, int y) {
    *(volatile unsigned int*)0x400101c = (x & 0x1ff) | ((y << 0x10) & 0x1ff0000);
}
