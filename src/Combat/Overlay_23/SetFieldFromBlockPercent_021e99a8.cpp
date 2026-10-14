#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);
int GetFieldPercentOver307_020a0870(BattleRecordSnapshot* p);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e99a8  (semantic: SetFieldFromBlockPercent_021e99a8)
extern "C" ARM int func_ov023_021e99a8(void* obj) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    int pct = GetFieldPercentOver307_020a0870(&record);
    func_ov017_021d6134(obj, pct);
    return 1;
}
