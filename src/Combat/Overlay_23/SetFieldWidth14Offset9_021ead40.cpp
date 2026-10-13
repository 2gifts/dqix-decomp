#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define SetFieldWidth14Offset9_021ead40 func_ov023_021eaca4
#endif

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ead40
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldWidth14Offset9_021ead40(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown10_9);
    return 1;
}
