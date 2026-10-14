#include <globaldefs.h>

// USA: func_0204a6b4
ARM int SetBg1Priority_0204a6b4(int priority) {
    volatile unsigned short* bg1cnt = (volatile unsigned short*)0x400000a;
    int value = (*bg1cnt & ~3) | priority;
    *bg1cnt = value;
    return value;
}
