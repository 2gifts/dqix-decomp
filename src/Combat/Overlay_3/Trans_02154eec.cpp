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
extern "C" ARM void func_ov003_02154eec(unsigned int self) {
    if (*(unsigned char*)((char*)self + kRegionValue1F8_1F4) == 0) { return; }
    if (*(unsigned int*)((char*)self + kRegionValue204_200) != 0) {
        _Z29InitBuffersIfFlag431_021eb4b8Pv(*(unsigned int*)((char*)self + kRegionValue204_200));
    } else {
        unsigned int obj = *(unsigned int*)((char*)self + 0x18);
        if (obj != 0) {
            _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(obj);
            _Z35CallFunc0204c8f0OverEntries0207fd00P11Obj0207fd00(obj);
            func_0207fe80(obj, 2, 1, 1);
            _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(obj);
        }
    }
    if (*(unsigned int*)((char*)self + 0x1c) != 0 && _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(*(unsigned int*)((char*)self + 0x1c)) != 0) {
        _Z27UpdateEntryIfActive020e2794P14Struct020e2794Pv(*(unsigned int*)((char*)self + 0x1c), self + 0x2c);
        return;
    }
    func_ov003_0215501c(self);
}
