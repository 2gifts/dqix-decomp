#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);

// JPN: func_ov023_021d9760
// USA: func_ov023_021d8ea0  (semantic: InitCaptureRegsOnce_021d8ea0)
extern "C" ARM void func_ov023_021d8ea0(char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x28};
#else
 enum {regionalOffset0=0x5c};
#endif
    unsigned char flag = *(unsigned char*)(obj + 0x11b);
    if (flag == 0xff) return;
    if (flag != 0) return;

    int g = GetGlobalField0x1c020421a0();
    *(int*)(obj + 0x4) = *(int*)((char*)g + regionalOffset0);

    volatile unsigned short* reg = (volatile unsigned short*)0x4001008;
    reg[0] = (reg[0] & ~3) | 1;
    reg[1] = (reg[1] & ~3) | 2;
    reg[2] = (reg[2] & ~3);
    reg[3] = (reg[3] & ~3) | 3;

    volatile unsigned int* reg2 = (volatile unsigned int*)0x4001000;
    *reg2 = (*reg2 & ~0x1f00) | 0x700;

    *(unsigned char*)(obj + 0x11b) = 0xff;
}
