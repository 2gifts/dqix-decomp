#include <globaldefs.h>

#if defined(jpn)
enum { kWorldFlagOffset = 0x1da };
#else
enum { kWorldFlagOffset = 0x48a };
#endif

extern "C" char* func_ov017_0218b5b0(void);

// USA: func_ov025_021e86f0
ARM int SetFlag021e86f0(void) {
    char* p = func_ov017_0218b5b0() + 0x4000;
    p[kWorldFlagOffset] = 1;
    return 1;
}
