#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define SetFieldWidth9Offset0_021eacd8 func_ov023_021eac3c
#endif

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eacd8
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldWidth9Offset0_021eacd8(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown10_0);
    return 1;
}
