#include <globaldefs.h>

// USA: func_0204a660
ARM void SetSubBg0Priority_0204a660(int priority) {
    unsigned short *reg = (unsigned short *)0x4001008;
    *reg = (*reg & ~3) | priority;
}
