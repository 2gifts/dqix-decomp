#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define func_ov025_021e812c func_ov025_021e85cc
#endif

extern int data_ov025_021ef988;

// USA: func_ov025_021e812c  (semantic: Trans_021e812c)
extern "C" ARM unsigned int func_ov025_021e812c(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r1 = (unsigned int)&data_ov025_021ef988;
    r2 = *(unsigned char*)((char*)r0 + 0x8);
    r1 = *(unsigned int*)((char*)r1 + kGlobalHolderInnerOffset);
    r0 = 0x1;
    *(unsigned int*)((char*)r1 + 0x228) = (unsigned int)r2;
    return r0;
}
