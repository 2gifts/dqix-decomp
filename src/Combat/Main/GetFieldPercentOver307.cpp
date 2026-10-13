#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>


// USA: func_020a0870
ARM int GetFieldPercentOver307(BattleRecordSnapshot* record) {
    unsigned int v = record->unknown14_0;
    unsigned int pct = v * 100 / 307;
    if (pct != 0) {
        return pct;
    }
    if (v != 0) {
        return 1;
    }
    return pct;
}
