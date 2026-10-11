#include <globaldefs.h>

struct BattleWorkHolder02160130 {
    int flag;
    void* work;
};
extern struct BattleWorkHolder02160130 data_ov000_02184220;

// USA: func_ov000_02160130
ARM void* GetActiveCombatWork(void) {
    return data_ov000_02184220.work;
}
