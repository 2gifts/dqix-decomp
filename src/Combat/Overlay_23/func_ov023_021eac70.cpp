#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eac70  (semantic: SetFieldWidth7Offset17_021eac70)
extern "C" ARM int func_ov023_021eac70(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown0c_17);
    return 1;
}
