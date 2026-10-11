#include <globaldefs.h>

#if defined(jpn)
enum { kIndexOffset = 0x7c8 };
#else
enum { kIndexOffset = 0x5d8 };
#endif

// JPN: func_ov000_02162708
// USA: func_ov000_02160f9c
ARM int GetIntFieldFromOffset5000_02160f9c(void* obj) {
    return *(int*)((char*)obj + 0x5000 + kIndexOffset);
}
