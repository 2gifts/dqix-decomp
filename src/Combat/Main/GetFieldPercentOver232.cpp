#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

// USA: func_020a08a4
ARM int GetFieldPercentOver232(BattleRecordSnapshot* record) {
    unsigned int v = record->unknown14_9;
    unsigned int pct = v * 100 / 232;
    if (pct != 0) {
        return pct;
    }
    if (v != 0) {
        return 1;
    }
    return pct;
}
