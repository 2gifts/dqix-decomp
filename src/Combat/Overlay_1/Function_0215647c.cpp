#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);

#if defined(jpn)
enum { kOwnerFlag = 0xf8, kGlobalFlag = 0x40c2 };
#else
enum { kOwnerFlag = 0xfc, kGlobalFlag = 0x42e2 };
#endif

// KEEP-NAME
// USA: func_ov001_0215647c
ARM int Function_0215647c(void* ctx) {
    if (*((unsigned char*)ctx + kOwnerFlag) != 0) return 0xa;
    if (*((unsigned char*)func_ov017_0218b5b0() + kGlobalFlag) != 0) return 0xa;
    return *(unsigned short*)((char*)ctx + 0xa);
}
