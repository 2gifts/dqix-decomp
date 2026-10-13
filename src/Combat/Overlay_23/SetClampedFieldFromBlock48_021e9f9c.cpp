#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define SetClampedFieldFromBlock48_021e9f9c func_ov023_021e9f00
#endif

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9f9c
#if defined(jpn)
extern "C"
#endif
ARM int SetClampedFieldFromBlock48_021e9f9c(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    unsigned int value = record.unknown48;
    if (value > 0x7fffffff) value = 0x7fffffff;
    func_ov017_021d6134(outputReference, value);
    return 1;
}
