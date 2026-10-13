#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov023_021e9e30
extern "C" ARM int func_ov023_021e9e30(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.unknown28_0);
    return 1;
}
