#include <globaldefs.h>

// USA: func_020e2bac
ARM int GetEngineBDispcntWindowBits_020e2bac() {
    return (*(volatile unsigned int *)0x4001000 & 0xe000) >> 13;
}
