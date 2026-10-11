#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern int data_020f0d70;

// USA: func_020e60e0  (semantic: Trans_020e60e0)
extern "C" __declspec(initcode) ARM unsigned int __sinit_020e60e0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = (unsigned int)&data_020f0d70;
    #if defined(jpn)
    r1 = *(unsigned int*)r0;
#else
    r1 = *(unsigned int*)((char*)r0 + 0x14);
#endif
    r1 = r1 + 0xb;
    #if defined(jpn)
    *(unsigned int*)((char*)r0 + 4) = (unsigned int)r1;
#else
    *(unsigned int*)((char*)r0 + 0x18) = (unsigned int)r1;
#endif
    return r0;
}
