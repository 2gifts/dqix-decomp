#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021ea884  (semantic: SetFieldFromBlock20_021ea884)
extern "C" ARM int func_ov023_021ea884(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.unknown20_0);
    return 1;
}
