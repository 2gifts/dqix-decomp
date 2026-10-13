#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define func_ov023_021e9d60 func_ov023_021e9cc4
#endif

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9d60  (semantic: SetFieldWidth24Offset0_021e9d60)
extern "C" ARM int func_ov023_021e9d60(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.unknown38_0);
    return 1;
}
