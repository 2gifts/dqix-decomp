#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define SetFieldWidth8Offset0_021ead0c func_ov023_021eac70
#endif

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ead0c
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldWidth8Offset0_021ead0c(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown14_0);
    return 1;
}
