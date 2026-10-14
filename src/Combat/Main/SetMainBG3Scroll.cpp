#include <globaldefs.h>

// USA: func_0204a78c
ARM void SetMainBG3Scroll_0204a78c(int h, int v) {
    *(volatile unsigned int*)0x400001c = (h & 0x1ff) | ((v << 16) & 0x1ff0000);
}
