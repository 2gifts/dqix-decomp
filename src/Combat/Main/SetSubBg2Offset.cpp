#include <globaldefs.h>

// USA: func_0204a714
ARM void SetSubBg2Offset_0204a714(int x, int y) {
    *(volatile unsigned int*)0x4001018 = (x & 0x1ff) | ((y << 0x10) & 0x1ff0000);
}
