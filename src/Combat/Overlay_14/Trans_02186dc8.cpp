#if defined(jpn)
#define R(j,u) (j)
#define _Z27ConfigureSubsystem_021889f8P11Obj021889f8 func_ov008_0218973c
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" unsigned int _Z28CallFunc0204b088OverList0x2cP12Cont0207fd88(unsigned int);
extern "C" unsigned int func_ov014_02185c90(unsigned int);

// USA: func_ov014_02186dc8  (semantic: Trans_02186dc8)
extern "C" ARM unsigned int func_ov014_02186dc8(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = *(unsigned char*)((char*)r4 + 0x17a);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { goto L1c; }
    r0 = *(unsigned int*)((char*)r4 + 0xc0);
    r0 = (unsigned int)_Z28CallFunc0204b088OverList0x2cP12Cont0207fd88(r0);
L1c:;
    r0 = r4;
    r0 = (unsigned int)func_ov014_02185c90(r0);
    return r0;
}
