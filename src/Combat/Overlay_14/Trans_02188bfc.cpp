#if defined(jpn)
#define R(j,u) (j)
#define func_ov014_02188c34 func_ov014_02189a78
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" unsigned int _Z20ResetHandle_02188d10P20HandleState_02188d10();
extern "C" unsigned int _Z24InitHandleState_02188bd0P20HandleState_02188bd0(unsigned int);
extern "C" unsigned int func_ov014_02188c34(unsigned int, unsigned int);

// USA: func_ov014_02188bfc  (semantic: Trans_02188bfc)
extern "C" ARM unsigned int func_ov014_02188bfc(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    r6 = r0;
    r5 = r1;
    r4 = r2;
    r0 = (unsigned int)_Z20ResetHandle_02188d10P20HandleState_02188d10();
    r0 = r6;
    r0 = (unsigned int)_Z24InitHandleState_02188bd0P20HandleState_02188bd0(r0);
    *(unsigned short*)((char*)r6 + 0x14) = (unsigned short)r4;
    r0 = r6;
    *(unsigned int*)((char*)r6 + 0x1c) = (unsigned int)r5;
    r1 = 0x1;
    *(unsigned short*)((char*)r6 + 0x16) = (unsigned short)r1;
    r0 = (unsigned int)func_ov014_02188c34(r0, r1);
    return r0;
}
