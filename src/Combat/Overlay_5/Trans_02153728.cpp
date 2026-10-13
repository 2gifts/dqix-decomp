#include <globaldefs.h>

extern "C" unsigned int func_ov005_021538fc(unsigned int, unsigned int, unsigned int, unsigned int);

// USA: func_ov005_02153728  (semantic: Trans_02153728)
extern "C" ARM unsigned int func_ov005_02153728(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int stk[1];
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    r6 = r0;
    r0 = 0xb33;
    if (r1 == 0) { r1 = 0x1; }
    r4 = r1 * r0;
    r2 = 0xccc;
    r0 = r6;
    r5 = r1 * r2;
    r3 = r4;
    r1 = r6 + 0x18;
    r2 = r6 + 0x28;
    *(unsigned int*)((char*)stk + 0x0) = (unsigned int)r5;
    r0 = (unsigned int)func_ov005_021538fc(r0, r1, r2, r3);
    r0 = r6;
    r3 = r4;
    r1 = r6 + 0x1c;
    r2 = r6 + 0x2c;
    *(unsigned int*)((char*)stk + 0x0) = (unsigned int)r5;
    r0 = (unsigned int)func_ov005_021538fc(r0, r1, r2, r3);
    r0 = r6;
    r3 = r4;
    r1 = r6 + 0x20;
    r2 = r6 + 0x30;
    *(unsigned int*)((char*)stk + 0x0) = (unsigned int)r5;
    r0 = (unsigned int)func_ov005_021538fc(r0, r1, r2, r3);
    r3 = r4;
    r0 = r6;
    r1 = r6 + 0x24;
    r2 = r6 + 0x34;
    *(unsigned int*)((char*)stk + 0x0) = (unsigned int)r5;
    r0 = (unsigned int)func_ov005_021538fc(r0, r1, r2, r3);
    return r0;
}
