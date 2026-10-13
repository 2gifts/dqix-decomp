#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define func_ov023_021e9b48 func_ov023_021e9aac
#endif

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9b48  (semantic: SetFieldWidth9Offset0_021e9b48)
extern "C" ARM int func_ov023_021e9b48(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.unknown18_0);
    return 1;
}
