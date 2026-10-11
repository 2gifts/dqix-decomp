#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02185a24 func_ov012_02186084
#endif

extern "C" unsigned int _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(unsigned int);
extern "C" unsigned int _Z28CallFunc0204c8f0OverList0x9cP12Cont0205d228(unsigned int);
extern "C" unsigned int _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(unsigned int);
extern "C" unsigned int _Z33UpdateEntryFromDoublePtr_021e6b04Pc(unsigned int);
extern "C" unsigned int _Z37InitBuffersAndConfigureEntry_021e761cPv(unsigned int);
extern "C" unsigned int func_0205da88(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_ov023_021e67f4(unsigned int);
extern "C" unsigned int func_ov023_021e68cc(unsigned int);
extern "C" unsigned int func_ov023_021e6a14(unsigned int);
extern "C" unsigned int func_ov024_021e6a90(unsigned int);

// USA: func_ov012_02185a24  (semantic: Trans_02185a24)
extern "C" ARM unsigned int func_ov012_02185a24(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = r4 + 0x128;
    r0 = r0 + 0xc00;
    r0 = (unsigned int)_Z37InitBuffersAndConfigureEntry_021e761cPv(r0);
    r0 = r4 + 0xac;
    r0 = (unsigned int)_Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(r0);
    r0 = r4 + 0xac;
    r0 = (unsigned int)_Z28CallFunc0204c8f0OverList0x9cP12Cont0205d228(r0);
    r0 = r4 + 0xac;
    r1 = 0x1;
    r2 = 0x2;
    r3 = r1;
    r0 = (unsigned int)func_0205da88(r0, r1, r2, r3);
    r0 = r4 + 0xac;
    r1 = 0x1;
    r2 = 0x3;
    r3 = r1;
    r0 = (unsigned int)func_0205da88(r0, r1, r2, r3);
    r0 = r4 + 0xac;
    r1 = 0x2;
    r2 = 0x3;
    r3 = 0x0;
    r0 = (unsigned int)func_0205da88(r0, r1, r2, r3);
    r0 = r4 + 0xac;
    r0 = (unsigned int)_Z28CallFunc0204b04cOverList0x98P12Cont0205d274(r0);
    r0 = r4;
    r0 = (unsigned int)func_ov023_021e67f4(r0);
    r0 = r4;
    r0 = (unsigned int)func_ov023_021e68cc(r0);
    r0 = r4;
    r0 = (unsigned int)func_ov023_021e6a14(r0);
    r0 = r4;
    r0 = (unsigned int)func_ov024_021e6a90(r0);
    r0 = r4;
    r0 = (unsigned int)_Z33UpdateEntryFromDoublePtr_021e6b04Pc(r0);
    return r0;
}
