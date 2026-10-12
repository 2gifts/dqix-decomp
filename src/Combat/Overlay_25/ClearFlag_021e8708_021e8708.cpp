#include <globaldefs.h>

#if defined(jpn)
enum { kWorldFlagOffset = 0x1da };
#else
enum { kWorldFlagOffset = 0x48a };
#endif


#if defined(jpn)
#define ClearFlag_021e8708_021e8708 func_ov025_021e8ba8
#endif

extern "C" void* func_ov017_0218b5b0(void);

// USA: func_ov025_021e8708
#if defined(jpn)
extern "C"
#endif
ARM int ClearFlag_021e8708_021e8708(void) {
    *(unsigned char*)((char*)func_ov017_0218b5b0() + 0x4000 + kWorldFlagOffset) = 0;
    return 1;
}
