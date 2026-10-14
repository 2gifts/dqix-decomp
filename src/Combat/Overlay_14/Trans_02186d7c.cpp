#include <globaldefs.h>

struct Obj0207fcb8;
unsigned int ClearAllBuffers0207fcb8(Obj0207fcb8*);
struct Cont0207fd44;
unsigned int CallFunc0204b04cOverList0x2c(Cont0207fd44*);
struct Obj0207fd00;
unsigned int CallFunc0204c8f0OverEntries0207fd00(Obj0207fd00*);
extern "C" unsigned int func_0207fe80(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" void func_ov014_02186e2c(unsigned int);

// USA: func_ov014_02186d7c  (semantic: Trans_02186d7c)
extern "C" ARM void func_ov014_02186d7c(unsigned int self) {
    if (*(unsigned char*)((char*)self + 0x17a) != 0) {
        ClearAllBuffers0207fcb8((Obj0207fcb8*)(*(unsigned int*)((char*)self + 0xc0)));
        CallFunc0204c8f0OverEntries0207fd00((Obj0207fd00*)(*(unsigned int*)((char*)self + 0xc0)));
        func_0207fe80(*(unsigned int*)((char*)self + 0xc0), 1, 0, 1);
        CallFunc0204b04cOverList0x2c((Cont0207fd44*)(*(unsigned int*)((char*)self + 0xc0)));
        func_ov014_02186e2c(self);
    }
}
