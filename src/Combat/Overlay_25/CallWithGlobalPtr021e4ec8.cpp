#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define CallWithGlobalPtr021e4ec8 func_ov025_021e53b8
#endif

struct CombatContext;
struct CombatGlobals {
    char unknown0[kGlobalHolderInnerOffset];
    CombatContext* context;
};
extern CombatGlobals data_ov025_021ef988;

extern "C" void func_ov025_021e8af8(void* param);

// USA: func_ov025_021e4ec8
#if defined(jpn)
extern "C"
#endif
ARM int CallWithGlobalPtr021e4ec8(void) {
    func_ov025_021e8af8(data_ov025_021ef988.context);
    return 1;
}
