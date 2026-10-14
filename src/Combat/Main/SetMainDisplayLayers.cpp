#include <globaldefs.h>

// USA: func_020daf3c
ARM void SetMainDisplayLayers_020daf3c(int layers) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | (layers << 8);
}
