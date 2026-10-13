#include <globaldefs.h>

#if defined(jpn)
enum { kWorkFlagOffset = 0x71c8 };
#else
enum { kWorkFlagOffset = 0x6fd8 };
#endif

void* GetActiveCombatWork(void);

// USA: func_ov025_021e8898  (semantic: SetActiveCombatFlagFd8_021e8898)
extern "C" ARM int func_ov025_021e8898(void) {
    void* obj = GetActiveCombatWork();
    if (obj) {
        *((char*)obj + kWorkFlagOffset) = 1;
    }
    return 1;
}
