#include <globaldefs.h>

#if defined(jpn)
enum { kFlagsOffset = 0x57e4 };
#else
enum { kFlagsOffset = 0x55f4 };
#endif

// USA: func_ov000_02160fa8
ARM void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* work, int mask) {
    *(int*)((char*)work + kFlagsOffset) |= mask;
}
