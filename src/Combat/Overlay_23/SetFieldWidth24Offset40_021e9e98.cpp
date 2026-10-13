#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9e98  (semantic: SetFieldWidth24Offset40_021e9e98)
extern "C" ARM int func_ov023_021e9e98(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.unknown40_0);
    return 1;
}
