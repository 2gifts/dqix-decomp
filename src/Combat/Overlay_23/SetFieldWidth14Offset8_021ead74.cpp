#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ead74
ARM int SetFieldWidth14Offset8_021ead74(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown14_8);
    return 1;
}
