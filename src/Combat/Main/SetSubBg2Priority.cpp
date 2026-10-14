#include <globaldefs.h>

// USA: func_0204a628
ARM void SetSubBg2Priority_0204a628(int priority) {
    unsigned short *reg = (unsigned short *)0x400100c;
    *reg = (*reg & ~3) | priority;
}
