#include <globaldefs.h>

#include "System/Graphics.h"

// USA: func_0209378c
ARM int GetDisplayModeCode0209378c(int engine) {
    unsigned int mapping;
    if (engine == 0)
        mapping = DISPCNT & 0x00300010;
    else
        mapping = DISPCNTSUB & 0x00300010;

    int shift = 0;
    switch (mapping) {
        case 0x00000010: shift = 5; break;
        case 0x00100010: shift = 6; break;
        case 0x00200010: shift = 7; break;
    }
    return shift;
}
