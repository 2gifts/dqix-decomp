#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue6FC_4EC = 0x4ec };
enum { kRegionValue734_524 = 0x524 };
enum { kRegionValue400_200 = 0x200 };
enum { kRegionValueA2_CA = 0xca };
enum { kRegionValueCD_C9 = 0xc9 };
enum { kRegionValueCE_CA = 0xca };
enum { kRegionValueCF_CB = 0xcb };
enum { kRegionValue4A3_2CB = 0x2cb };
enum { kRegionValue464_28C = 0x28c };
#else
enum { kRegionValue6FC_4EC = 0x6fc };
enum { kRegionValue734_524 = 0x734 };
enum { kRegionValue400_200 = 0x400 };
enum { kRegionValueA2_CA = 0xa2 };
enum { kRegionValueCD_C9 = 0xcd };
enum { kRegionValueCE_CA = 0xce };
enum { kRegionValueCF_CB = 0xcf };
enum { kRegionValue4A3_2CB = 0x4a3 };
enum { kRegionValue464_28C = 0x464 };
#endif


extern "C" unsigned int _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" unsigned int _Z18CheckField0NonZeroPi(unsigned int, unsigned int);
extern "C" unsigned int _Z19SetFlag320_02195530Ph(unsigned int);
extern "C" unsigned int _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c();
extern "C" unsigned int func_02012fe4();
extern "C" unsigned int func_0202ae18();
extern "C" unsigned int func_0202c508(unsigned int);
extern "C" unsigned int func_ov003_02161480();
extern "C" unsigned int func_ov017_021bbae4(unsigned int, unsigned int, unsigned int);

// USA: func_ov003_02163d7c  (semantic: Trans_02163d7c)
// JPN: func_ov003_02163d94
extern "C" ARM unsigned int func_ov003_02163d7c(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    unsigned int r7 = 0;
    unsigned int r8 = 0;
    unsigned int r9 = 0;
    r9 = r0;
    r0 = (unsigned int)func_ov003_02161480();
    r0 = (unsigned int)GameState::GetInstance();
    r5 = r0;
    r0 = (unsigned int)func_02012fe4();
    r4 = r0;
    r0 = (unsigned int)((unsigned int)func_ov017_0218b5b0());
    r6 = r0;
    r1 = r6 + 0x3000;
    r7 = *(unsigned int*)((char*)r1 + kRegionValue6FC_4EC);
    r8 = *(unsigned int*)((char*)r1 + kRegionValue734_524);
    r1 = r9 + kRegionValue400_200;
    r1 = *(signed char*)((char*)r1 + kRegionValueA2_CA);
    r0 = r5;
    r0 = (unsigned int)((GameState*)r0)->GetGameObjectByIndex(r1);
    r0 = (unsigned int)_Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c();
    r5 = r0;
    r0 = (unsigned int)func_0202ae18();
    r1 = *(unsigned int*)((char*)r4 + 0x8);
    r4 = r0;
    r0 = r8;
    r2 = 0x1;
    r0 = (unsigned int)func_ov017_021bbae4(r0, r1, r2);
    r1 = r9 + kRegionValue400_200;
    r3 = *(signed char*)((char*)r1 + kRegionValueA2_CA);
    r0 = r7;
    r2 = 0x0;
    *(unsigned char*)((char*)r8 + kRegionValueCD_C9) = (unsigned char)r3;
    r3 = *(unsigned char*)((char*)r5 + 0x14);
    r1 = r8;
    r3 = r3 << 0x1f;
    r3 = r3 >> 0x1f;
    *(unsigned char*)((char*)r8 + kRegionValueCE_CA) = (unsigned char)r3;
    *(unsigned char*)((char*)r8 + kRegionValueCF_CB) = (unsigned char)r2;
    r0 = (unsigned int)_Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(r0, r1, r2, r3);
    r0 = 0x10;
    *(unsigned char*)((char*)r9 + kRegionValue4A3_2CB) = (unsigned char)r0;
    r1 = *(unsigned int*)((char*)r9 + kRegionValue464_28C);
    r0 = r4;
    r1 = r1 & ~0x8000;
    *(unsigned int*)((char*)r9 + kRegionValue464_28C) = (unsigned int)r1;
    r0 = (unsigned int)_Z18CheckField0NonZeroPi(r0, r1);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { return r0; }
    r0 = r4;
    r0 = (unsigned int)func_0202c508(r0);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { return r0; }
    r0 = r6;
    r0 = (unsigned int)_Z19SetFlag320_02195530Ph(r0);
    return r0;
}
