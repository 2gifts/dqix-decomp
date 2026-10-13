#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif

struct CombatContext;
struct CombatGlobals {
    char unknown0[kGlobalHolderInnerOffset];
    CombatContext* context;
};
extern CombatGlobals data_ov025_021ef988;

extern "C" void func_ov025_021e8b6c(void* param);

// USA: func_ov025_021e4ee4
ARM int CallWithGlobalPtr021e4ee4(void) {
    func_ov025_021e8b6c(data_ov025_021ef988.context);
    return 1;
}
