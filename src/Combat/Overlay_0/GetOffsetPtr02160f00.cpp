#include <globaldefs.h>

#if defined(jpn)
enum { kFieldOffset = 0xaac };
#else
enum { kFieldOffset = 0xb30 };
#endif

// JPN: func_ov000_02162668
// USA: func_ov000_02160f00
ARM void* GetOffsetPtr02160f00(void* obj) {
    return (char*)obj + kFieldOffset;
}
