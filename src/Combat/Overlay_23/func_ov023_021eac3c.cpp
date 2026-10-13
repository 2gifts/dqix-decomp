#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define func_ov023_021eac3c func_ov023_021eaba0
#endif

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eac3c  (semantic: SetFieldWidth17Offset0_021eac3c)
extern "C" ARM int func_ov023_021eac3c(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown0c_0);
    return 1;
}
