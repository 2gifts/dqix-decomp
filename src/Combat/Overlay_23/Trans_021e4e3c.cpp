#include <globaldefs.h>

#if defined(jpn)
enum { kLargeFieldBase = 0x500, kFlagsInBlock = 0x6c, kCounterOffset = 0x56e, kStateInBlock = 0xe2, kPreviousStateOffset = 0x4e3, kStateOffset = 0x4e2, kResetFlagOffset = 0x4e0 };
#else
enum { kLargeFieldBase = 0x600, kFlagsInBlock = 0x34, kCounterOffset = 0x636, kStateInBlock = 0xe6, kPreviousStateOffset = 0x4e7, kStateOffset = 0x4e6, kResetFlagOffset = 0x4e4 };
#endif


#if defined(jpn)
#define func_ov023_021e4e3c func_ov023_021e5030
#endif


// USA: func_ov023_021e4e3c  (semantic: Trans_021e4e3c)
extern "C" ARM unsigned int func_ov023_021e4e3c(unsigned int r0) {
    unsigned int r1, r2, r3;
    int cc = 0;
    r1 = r0 + kLargeFieldBase;
    r1 = *(unsigned short*)((char*)r1 + kFlagsInBlock);
    cc = (int)(r1 & 0x1000);
    if (cc == 0) { return r0; }
    cc = (int)(r1 & 0x2000);
    if (cc != 0) { return r0; }
    r1 = *(unsigned char*)((char*)r0 + kCounterOffset);
    cc = (int)(r1) - (int)(0x0);
    if (cc != 0) { return r0; }
    r1 = r0 + 0x400;
    r3 = *(signed char*)((char*)r1 + kStateInBlock);
    r2 = 0x1;
    r1 = 0x0;
    *(unsigned char*)((char*)r0 + kPreviousStateOffset) = (unsigned char)r3;
    *(unsigned char*)((char*)r0 + kStateOffset) = (unsigned char)r2;
    *(unsigned char*)((char*)r0 + kResetFlagOffset) = (unsigned char)r1;
    r1 = *(unsigned char*)((char*)r0 + kCounterOffset);
    r1 = r1 + 0x1;
    *(unsigned char*)((char*)r0 + kCounterOffset) = (unsigned char)r1;
    return r0;
}
