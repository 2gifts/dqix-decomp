#include <globaldefs.h>

#if defined(jpn)
enum { kFieldOffset = 0xe20 };
#else
enum { kFieldOffset = 0xea4 };
#endif

// JPN: func_ov000_02164c88
// USA: func_ov000_02163524
ARM int GetField02163524(void* obj) {
    return *(int*)((char*)obj + kFieldOffset);
}
