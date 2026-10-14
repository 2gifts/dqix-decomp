#include <globaldefs.h>

// USA: func_0204a7dc
ARM void SetMainBG1Scroll_0204a7dc(int h, int v) {
    *(volatile unsigned int*)0x4000014 = (h & 0x1ff) | ((v << 16) & 0x1ff0000);
}
