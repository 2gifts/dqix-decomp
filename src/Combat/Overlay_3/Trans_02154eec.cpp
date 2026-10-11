#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue1F8_1F4 = 0x1f4 };
enum { kRegionValue204_200 = 0x200 };
#else
enum { kRegionValue1F8_1F4 = 0x1f8 };
enum { kRegionValue204_200 = 0x204 };
#endif


extern "C" unsigned int _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(unsigned int);
extern "C" unsigned int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(unsigned int);
extern "C" unsigned int _Z27UpdateEntryIfActive020e2794P14Struct020e2794Pv(unsigned int, unsigned int);
extern "C" unsigned int _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(unsigned int);
extern "C" unsigned int _Z29InitBuffersIfFlag431_021eb4b8Pv(unsigned int);
extern "C" unsigned int _Z35CallFunc0204c8f0OverEntries0207fd00P11Obj0207fd00(unsigned int);
extern "C" unsigned int func_0207fe80(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_ov003_0215501c(unsigned int);

// USA: func_ov003_02154eec  (semantic: Trans_02154eec)
// JPN: func_ov003_021565d4
extern "C" ARM unsigned int func_ov003_02154eec(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    r5 = r0;
    r0 = *(unsigned char*)((char*)r5 + kRegionValue1F8_1F4);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { return r0; }
    r0 = *(unsigned int*)((char*)r5 + kRegionValue204_200);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { goto L28; }
    r0 = (unsigned int)_Z29InitBuffersIfFlag431_021eb4b8Pv(r0);
    goto L60;
L28:;
    r4 = *(unsigned int*)((char*)r5 + 0x18);
    cc = (int)(r4) - (int)(0x0);
    if (cc == 0) { goto L60; }
    r0 = r4;
    r0 = (unsigned int)_Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(r0);
    r0 = r4;
    r0 = (unsigned int)_Z35CallFunc0204c8f0OverEntries0207fd00P11Obj0207fd00(r0);
    r2 = 0x1;
    r0 = r4;
    r3 = r2;
    r1 = 0x2;
    r0 = (unsigned int)func_0207fe80(r0, r1, r2, r3);
    r0 = r4;
    r0 = (unsigned int)_Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(r0);
L60:;
    r0 = *(unsigned int*)((char*)r5 + 0x1c);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { goto L88; }
    r0 = (unsigned int)_Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(r0);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { goto L88; }
    r0 = *(unsigned int*)((char*)r5 + 0x1c);
    r1 = r5 + 0x2c;
    r0 = (unsigned int)_Z27UpdateEntryIfActive020e2794P14Struct020e2794Pv(r0, r1);
    return r0;
L88:;
    r0 = r5;
    r0 = (unsigned int)func_ov003_0215501c(r0);
    return r0;
}
