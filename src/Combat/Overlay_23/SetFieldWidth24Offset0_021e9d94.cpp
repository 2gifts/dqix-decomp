#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9d94  (semantic: SetFieldWidth24Offset0_021e9d94)
extern "C" ARM int func_ov023_021e9d94(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.unknown3c_0);
    return 1;
}
