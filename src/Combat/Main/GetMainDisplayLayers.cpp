#include <globaldefs.h>

// USA: func_020daf6c
ARM int GetMainDisplayLayers_020daf6c(void) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    return (*dispcnt & 0x1f00) >> 8;
}
