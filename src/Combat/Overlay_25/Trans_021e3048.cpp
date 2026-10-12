#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define func_ov025_021e3048 func_ov025_021e3538
#endif

extern int data_ov025_021ef988;
extern "C" unsigned int func_ov025_021e2f54(unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_ov025_021e3084(unsigned int);

// USA: func_ov025_021e3048  (semantic: Trans_021e3048)
extern "C" ARM unsigned int func_ov025_021e3048(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    r0 = (unsigned int)&data_ov025_021ef988;
    r6 = r1;
    r4 = *(unsigned int*)((char*)r0 + kGlobalHolderInnerOffset);
    r5 = r3;
    r0 = r4 + 0x540;
    r0 = (unsigned int)func_ov025_021e3084(r0);
    r1 = r6;
    r2 = r5;
    r0 = r4 + 0x540;
    *(unsigned int*)((char*)r4 + 0x540) = (unsigned int)r6;
    r0 = (unsigned int)func_ov025_021e2f54(r0, r1, r2);
    r0 = 0x1;
    return r0;
}
