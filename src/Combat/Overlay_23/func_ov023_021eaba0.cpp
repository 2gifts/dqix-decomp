#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eaba0  (semantic: SetFieldWidth17Offset0_021eaba0)
extern "C" ARM int func_ov023_021eaba0(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown08_0);
    return 1;
}
