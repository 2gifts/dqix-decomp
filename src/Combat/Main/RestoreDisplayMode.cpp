#include <globaldefs.h>

extern unsigned short data_020f226c;
extern unsigned short data_02111220;

// USA: func_020c38d4
#pragma optimize_for_size off
ARM void RestoreDisplayMode_020c38d4(void) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    data_020f226c = 1;
    unsigned short v = data_02111220;
    if (v != 0) {
        *dispcnt = (*dispcnt & ~0x30000) | ((unsigned int)v << 16);
        return;
    }
    *dispcnt |= 0x10000;
}
