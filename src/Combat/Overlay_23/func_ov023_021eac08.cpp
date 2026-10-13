#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define func_ov023_021eac08 func_ov023_021eab6c
#endif

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eac08  (semantic: SetFieldWidth7Offset24_021eac08)
extern "C" ARM int func_ov023_021eac08(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown08_24);
    return 1;
}
