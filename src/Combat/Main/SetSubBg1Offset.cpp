#include <globaldefs.h>

// USA: func_0204a73c
ARM void SetSubBg1Offset_0204a73c(int x, int y) {
    *(volatile unsigned int*)0x4001014 = (x & 0x1ff) | ((y << 0x10) & 0x1ff0000);
}
