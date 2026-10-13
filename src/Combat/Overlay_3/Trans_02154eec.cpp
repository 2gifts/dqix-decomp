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
extern "C" ARM unsigned int func_ov003_02154eec(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r5 = r0;
    unsigned int active = *(unsigned char*)((char*)r5 + kRegionValue1F8_1F4);
    if (active == 0) { return active; }
    if (*(unsigned int*)((char*)r5 + kRegionValue204_200) != 0) {
        _Z29InitBuffersIfFlag431_021eb4b8Pv(*(unsigned int*)((char*)r5 + kRegionValue204_200));
    } else {
        unsigned int r4 = *(unsigned int*)((char*)r5 + 0x18);
        if (r4 != 0) {
            _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(r4);
            _Z35CallFunc0204c8f0OverEntries0207fd00P11Obj0207fd00(r4);
            func_0207fe80(r4, 2, 1, 1);
            _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(r4);
        }
    }
    if (*(unsigned int*)((char*)r5 + 0x1c) != 0 && _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(*(unsigned int*)((char*)r5 + 0x1c)) != 0) {
        return _Z27UpdateEntryIfActive020e2794P14Struct020e2794Pv(*(unsigned int*)((char*)r5 + 0x1c), r5 + 0x2c);
    }
    return func_ov003_0215501c(r5);
}
