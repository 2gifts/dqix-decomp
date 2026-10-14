#include <globaldefs.h>

// USA: func_0204a7b4
ARM void SetMainBG2Scroll_0204a7b4(int h, int v) {
    *(volatile unsigned int*)0x4000018 = (h & 0x1ff) | ((v << 16) & 0x1ff0000);
}
