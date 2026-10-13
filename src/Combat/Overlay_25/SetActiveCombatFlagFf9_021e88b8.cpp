#include <globaldefs.h>

#if defined(jpn)
enum { kWorkFlagOffset = 0x71e9 };
#else
enum { kWorkFlagOffset = 0x6ff9 };
#endif

void* GetActiveCombatWork(void);

// USA: func_ov025_021e88b8  (semantic: SetActiveCombatFlagFf9_021e88b8)
extern "C" ARM int func_ov025_021e88b8(void) {
    void* obj = GetActiveCombatWork();
    if (obj) {
        *((char*)obj + kWorkFlagOffset) = 1;
    }
    return 1;
}
