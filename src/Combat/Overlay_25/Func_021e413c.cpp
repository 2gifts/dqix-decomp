#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif

#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov025_021eb0f4(void* context);
struct CombatContext;
struct CombatGlobals {
    char unknown0[kGlobalHolderInnerOffset];
    CombatContext* context;
};
extern CombatGlobals data_ov025_021ef988;

// USA: func_ov025_021e413c  (semantic: Func_021e413c)
extern "C" ARM int func_ov025_021e413c(void) {
    if (BackgroundLoader::GetInstance()->GetFlag0() == 0) {
        return 0;
    }
    return func_ov025_021eb0f4(data_ov025_021ef988.context);
}
