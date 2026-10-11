#include <globaldefs.h>

#if defined(jpn)
enum { kFlagsOffset = 0x57e4 };
#else
enum { kFlagsOffset = 0x55f4 };
#endif

// JPN: func_ov000_02162728
// USA: func_ov000_02160fbc
ARM void ClearCombatWorkFlags0x55f4(void* work, int mask) {
    *(int*)((char*)work + kFlagsOffset) &= ~mask;
}
