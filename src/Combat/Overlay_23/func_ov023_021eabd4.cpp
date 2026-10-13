#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define func_ov023_021eabd4 func_ov023_021eab38
#endif

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eabd4  (semantic: SetFieldWidth7Offset17_021eabd4)
extern "C" ARM int func_ov023_021eabd4(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown08_17);
    return 1;
}
