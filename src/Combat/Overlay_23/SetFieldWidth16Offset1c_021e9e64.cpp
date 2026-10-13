#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define func_ov023_021e9e64 func_ov023_021e9dc8
#endif

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9e64  (semantic: SetFieldWidth16Offset1c_021e9e64)
extern "C" ARM int func_ov023_021e9e64(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.unknown1c_0);
    return 1;
}
