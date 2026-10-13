#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define SetFieldWidth24Offset0_021eada8 func_ov023_021ead0c
#endif

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eada8
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldWidth24Offset0_021eada8(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown18_0);
    return 1;
}
