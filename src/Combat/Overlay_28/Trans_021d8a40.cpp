#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" unsigned int func_0204c684();

// USA: func_ov028_021d8a40  (semantic: Trans_021d8a40)
extern "C" ARM unsigned int func_ov028_021d8a40(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    r5 = r0;
    r4 = r1;
    r0 = (unsigned int)func_0204c684();
    *(unsigned int*)((char*)r5 + 0x8) = (unsigned int)r4;
    r1 = 0x0;
    *(unsigned short*)((char*)r5 + 0xac) = (unsigned short)r1;
    *(unsigned short*)((char*)r5 + 0xae) = (unsigned short)r1;
    r0 = 0x20;
    *(unsigned short*)((char*)r5 + 0xa8) = (unsigned short)r0;
    *(unsigned short*)((char*)r5 + 0xaa) = (unsigned short)r0;
    *(unsigned int*)((char*)r5 + 0xa0) = (unsigned int)r1;
    return r0;
}
