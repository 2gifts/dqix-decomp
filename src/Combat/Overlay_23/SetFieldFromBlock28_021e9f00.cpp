#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define SetFieldFromBlock28_021e9f00 func_ov023_021e9e64
#endif

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9f00
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldFromBlock28_021e9f00(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.unknown28_22);
    return 1;
}
