#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetSubBG2ScreenBase(void);

// USA: func_ov023_021dcc58
ARM void ConfigureBgSub1AndClear_021dcc58(void* obj) {
#if defined(jpn)
    if (*(signed char*)((char*)obj + 0x6f8) != 1) return;
#else
    if (*(signed char*)((char*)obj + 0x77c) != 1) return;
#endif

    unsigned short* reg = (unsigned short*)0x4001008;
    reg[0] = (reg[0] & 0x43) | 0xf00;
    reg[1] = (reg[1] & 0x43) | 0xe00;
    reg[0] = reg[0] & ~3;
    reg[1] = (reg[1] & ~3) | 1;
    reg[2] = (reg[2] & ~3) | 2;
    reg[3] = (reg[3] & ~3) | 3;
    *(unsigned int*)((char*)reg + 8) = 0;
    *(unsigned int*)((char*)reg + 0xc) = 0;

    memset((void*)GetSubBG0ScreenBase(), 0, 0x800);
    memset((void*)GetSubBG2ScreenBase(), 0, 0x800);

    unsigned int* reg2 = (unsigned int*)0x4001000;
    *reg2 = (*reg2 & ~0x1f00) | 0x1300;
}
