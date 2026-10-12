#include <globaldefs.h>

#if defined(jpn)
enum { kWorkHalfBase = 0x7000, kWorkHalfOffset = 0xf4 };
#else
enum { kWorkHalfBase = 0x6f00, kWorkHalfOffset = 0x4 };
#endif


#if defined(jpn)
#define func_ov025_021e6340 func_ov025_021e67f0
#endif

extern int data_02108760;
extern "C" unsigned int _Z19GetActiveCombatWorkv();
extern "C" unsigned int _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(unsigned int, unsigned int, unsigned int, unsigned int);

// USA: func_ov025_021e6340  (semantic: Trans_021e6340)
extern "C" ARM unsigned int func_ov025_021e6340(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)_Z19GetActiveCombatWorkv();
    r1 = r0 + kWorkHalfBase;
    r3 = *(unsigned short*)((char*)r4 + 0x8);
    r0 = (unsigned int)&data_02108760;
    r2 = 0x0;
    *(unsigned short*)((char*)r1 + kWorkHalfOffset) = (unsigned short)r3;
    r1 = *(unsigned short*)((char*)r4 + 0x8);
    r0 = (unsigned int)_Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(r0, r1, r2, r3);
    r0 = 0x1;
    return r0;
}
