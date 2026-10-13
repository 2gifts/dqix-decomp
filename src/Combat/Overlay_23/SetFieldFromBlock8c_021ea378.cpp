#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define func_ov023_021ea378 func_ov023_021ea2dc
#endif

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021ea378  (semantic: SetFieldFromBlock8c_021ea378)
extern "C" ARM int func_ov023_021ea378(void* outputReference) {
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);
    func_ov017_021d6134(outputReference, record.unknown8c_0);
    return 1;
}
