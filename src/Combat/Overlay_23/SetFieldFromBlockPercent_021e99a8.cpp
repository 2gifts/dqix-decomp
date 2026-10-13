#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e99a8 func_ov023_021e990c
#endif

int LoadBattleBlock020ac4c0(void* dst);
int GetFieldPercentOver307(BattleRecordSnapshot* p);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e99a8  (semantic: SetFieldFromBlockPercent_021e99a8)
extern "C" ARM int func_ov023_021e99a8(void* obj) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    int pct = GetFieldPercentOver307(&record);
    func_ov017_021d6134(obj, pct);
    return 1;
}
