#include <globaldefs.h>

// USA: func_020c54a4
#pragma optimize_for_size off
ARM void SetFogState_020c54a4(int enable, unsigned int fogMode, unsigned int fogShift, unsigned short fogOffset) {
    if (enable) {
        *(volatile unsigned short*)0x400035c = fogOffset;
        *(volatile unsigned short*)0x4000060 =
            (fogShift << 8) | (fogMode << 6) | 0x80 | (*(volatile unsigned short*)0x4000060 & ~0x3f40);
    } else {
        *(volatile unsigned short*)0x4000060 &= 0xcf7f;
    }
}
