#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define RefreshTwoFields_021e7fb4 func_ov025_021e8454
#endif

struct CombatContext;
struct CombatGlobals {
    char unknown0[kGlobalHolderInnerOffset];
    CombatContext* context;
};
extern CombatGlobals data_ov025_021ef988;
extern "C" void func_ov025_021e9d14(void* p);
extern "C" void func_ov025_021e9edc(void* p);

// USA: func_ov025_021e7fb4
#if defined(jpn)
extern "C"
#endif
ARM int RefreshTwoFields_021e7fb4() {
    CombatContext* p = data_ov025_021ef988.context;
    func_ov025_021e9d14(p);
    p = data_ov025_021ef988.context;
    func_ov025_021e9edc(p);
    return 1;
}
