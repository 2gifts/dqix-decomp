#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern int _Z26ResetAndReturnSelf020dfc2cPv;
extern int data_02153680;
extern int data_02153694;
struct SafeAllocator;
unsigned int ResetAndReturnAllocator_020466d0(SafeAllocator*);
extern "C" unsigned int func_0200ee94(unsigned int, unsigned int, unsigned int, unsigned int);

// USA: func_020e68f4  (semantic: Trans_020e68f4)
extern "C" __declspec(initcode) ARM unsigned int __sinit_020e68f4(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int stk[1];
    unsigned int r12 = 0;
    r0 = (unsigned int)&data_02153694;
    r12 = 0x0;
    r3 = (unsigned int)&_Z26ResetAndReturnSelf020dfc2cPv;
    r1 = 0x2;
    r2 = 0x18;
    *(unsigned int*)((char*)stk + 0x0) = (unsigned int)r12;
    r0 = (unsigned int)func_0200ee94(r0, r1, r2, r3);
    r0 = (unsigned int)&data_02153680;
    r0 = (unsigned int)ResetAndReturnAllocator_020466d0((SafeAllocator*)r0);
    return r0;
}
