#include <globaldefs.h>

struct CombatCommand {
    char unknown0[8];
    unsigned short argument;
};
struct CombatDispatchWork {
#if defined(jpn)
    char unknown0[0x70f4];
#else
    char unknown0[0x6f04];
#endif
    unsigned short dispatchedArgument;
};
extern int data_02108760;
CombatDispatchWork* GetActiveCombatWork_ov000_02160130();
void DispatchIfField0xc4NonNeg_0205ebfc(void*, int, int);

// USA: func_ov025_021e6340
extern "C" ARM int func_ov025_021e6340(CombatCommand* command) {
    CombatDispatchWork* work = GetActiveCombatWork_ov000_02160130();
    work->dispatchedArgument = command->argument;
    DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, command->argument, 0);
    return 1;
}
