#include <globaldefs.h>

#if defined(jpn)
enum { kFlagsOffset = 0x57e4 };
#else
enum { kFlagsOffset = 0x55f4 };
#endif

// JPN: func_ov000_02162740
// USA: func_ov000_02160fd4
ARM int GetCombatWorkFlags0x55f4(void* work, int mask) {
    return *(int*)((char*)work + kFlagsOffset) & mask;
}
