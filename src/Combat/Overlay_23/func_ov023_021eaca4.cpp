#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eaca4  (semantic: SetFieldWidth7Offset24_021eaca4)
extern "C" ARM int func_ov023_021eaca4(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown0c_24);
    return 1;
}
