#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define SetFieldFromBlocka4_021eaddc func_ov023_021ead40
#endif

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021eaddc
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldFromBlocka4_021eaddc(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.capture.unknown14_22);
    return 1;
}
