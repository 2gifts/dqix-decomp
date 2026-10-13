#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea2dc  (semantic: SetFieldWidth10Offset0_021ea2dc)
extern "C" ARM int func_ov023_021ea2dc(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.unknown84_0);
    return 1;
}
