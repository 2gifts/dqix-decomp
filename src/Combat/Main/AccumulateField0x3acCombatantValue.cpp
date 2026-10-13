#include <globaldefs.h>
#include "GameState/GameState.h"

static inline BaseCombatStats* GetBaseStats(GameObject* obj) {
    return obj->baseStats_;
}

// USA: func_0206918c
ARM void AccumulateField0x3acCombatantValue(void* unused, int* accum) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetProtagonist();
    if (combatant == NULL) {
        return;
    }
    BaseCombatStats* stats = GetBaseStats(combatant);
    *accum += sprintf((char*)(*accum), (const char*)stats);
}
