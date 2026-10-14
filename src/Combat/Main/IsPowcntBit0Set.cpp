#include <globaldefs.h>

// USA: func_020cede0
ARM int IsPowcntBit0Set_020cede0(void) {
    return (*(volatile unsigned short*)0x4000304 & 1) != 0;
}
