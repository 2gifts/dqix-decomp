#include <globaldefs.h>

struct CombatCommand {
    char unknown0[8];
    unsigned char argument;
};
struct CombatContext {
    char unknown0[0x228];
    unsigned int unknown228;
};
struct CombatGlobals {
#if defined(jpn)
    char unknown0[4];
#else
    char unknown0[0xc];
#endif
    CombatContext* context;
};
extern CombatGlobals data_ov025_021ef988;

// USA: func_ov025_021e812c
extern "C" ARM int func_ov025_021e812c(CombatCommand* command) {
    data_ov025_021ef988.context->unknown228 = command->argument;
    return 1;
}
