#include <globaldefs.h>

struct CombatCommand {
    char unknown0[8];
    unsigned short argument;
};
struct CombatContext {
    char unknown0[0x74a];
    unsigned short unknown74a;
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

// USA: func_ov025_021e85a8
extern "C" ARM int func_ov025_021e85a8(CombatCommand* command) {
    data_ov025_021ef988.context->unknown74a = command->argument;
    return 1;
}
