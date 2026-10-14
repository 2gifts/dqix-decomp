#include <globaldefs.h>

// USA: func_0204a804
ARM void SetMainBG0Scroll_0204a804(int h, int v) {
    *(volatile unsigned int*)0x4000010 = (h & 0x1ff) | ((v << 16) & 0x1ff0000);
}
