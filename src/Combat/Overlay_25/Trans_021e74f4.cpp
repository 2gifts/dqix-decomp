#include <globaldefs.h>

#if defined(jpn)
enum { kWorkFlagBase = 0x7000, kWorkFlagOffset = 0x1c4 };
#else
enum { kWorkFlagBase = 0x6000, kWorkFlagOffset = 0xfd4 };
#endif


#if defined(jpn)
#define func_ov025_021e74f4 func_ov025_021e79a4
#endif

extern "C" unsigned int _ZN15LightingManager11GetInstanceEv();
extern "C" unsigned int _Z19GetActiveCombatWorkv();
extern "C" unsigned int _ZN15LightingManager9BeginFadeEst(unsigned int, unsigned int, unsigned int);

// USA: func_ov025_021e74f4  (semantic: Trans_021e74f4)
extern "C" ARM unsigned int func_ov025_021e74f4(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)_ZN15LightingManager11GetInstanceEv();
    r1 = *(short*)((char*)r4 + 0x8);
    r2 = *(unsigned short*)((char*)r4 + 0xa);
    r0 = (unsigned int)_ZN15LightingManager9BeginFadeEst(r0, r1, r2);
    r0 = (unsigned int)_Z19GetActiveCombatWorkv();
    r1 = r0 + kWorkFlagBase;
    r0 = 0x1;
    *(unsigned char*)((char*)r1 + kWorkFlagOffset) = (unsigned char)r0;
    return r0;
}
