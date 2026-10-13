#include <globaldefs.h>

#if defined(jpn)
enum { kStateFieldOffset = 0x8f8 };
#else
enum { kStateFieldOffset = 0xb08 };
#endif

// USA: func_ov017_0219dffc
ARM void SetFieldB08_0219dffc(void* obj, int val) {
    *(int*)((char*)obj + 0x2000 + kStateFieldOffset) = val;
}
