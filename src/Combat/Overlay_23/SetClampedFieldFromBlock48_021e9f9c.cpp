#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9f9c
ARM int SetClampedFieldFromBlock48_021e9f9c(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    unsigned int value = record.unknown48;
    if (value > 0x7fffffff) value = 0x7fffffff;
    func_ov017_021d6134(outputReference, value);
    return 1;
}
