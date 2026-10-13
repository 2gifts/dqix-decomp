#include <globaldefs.h>

#if defined(jpn)
enum { kWorldFlagOffset = 0x1d8 };
#else
enum { kWorldFlagOffset = 0x488 };
#endif

extern "C" void* func_ov017_0218b5b0(void);

// USA: func_ov025_021e861c
ARM int ClearFlag_021e861c_021e861c(void) {
    *(unsigned char*)((char*)func_ov017_0218b5b0() + 0x4000 + kWorldFlagOffset) = 0;
    return 1;
}
