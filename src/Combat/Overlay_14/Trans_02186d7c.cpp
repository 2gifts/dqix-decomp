#include <globaldefs.h>

extern "C" unsigned int _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(unsigned int);
extern "C" unsigned int _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(unsigned int);
extern "C" unsigned int _Z35CallFunc0204c8f0OverEntries0207fd00P11Obj0207fd00(unsigned int);
extern "C" unsigned int func_0207fe80(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_ov014_02186e2c(unsigned int);

// USA: func_ov014_02186d7c  (semantic: Trans_02186d7c)
extern "C" ARM unsigned int func_ov014_02186d7c(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int self = r0;
    unsigned int active = *(unsigned char*)((char*)self + 0x17a);
    if (active != 0) {
        _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(*(unsigned int*)((char*)self + 0xc0));
        _Z35CallFunc0204c8f0OverEntries0207fd00P11Obj0207fd00(*(unsigned int*)((char*)self + 0xc0));
        func_0207fe80(*(unsigned int*)((char*)self + 0xc0), 1, 0, 1);
        _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(*(unsigned int*)((char*)self + 0xc0));
        active = func_ov014_02186e2c(self);
    }
    return active;
}
