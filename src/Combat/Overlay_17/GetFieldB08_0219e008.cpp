#include <globaldefs.h>

#if defined(jpn)
enum { kStateFieldOffset = 0x8f8 };
#else
enum { kStateFieldOffset = 0xb08 };
#endif

// USA: func_ov017_0219e008
ARM int GetFieldB08_0219e008(void* obj) {
    return *(int*)((char*)obj + 0x2000 + kStateFieldOffset);
}
