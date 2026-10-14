#include <globaldefs.h>
#include "GameState/GameState.h"

static inline BaseCombatStats* GetBaseStats(GameObject* obj) {
    return obj->baseStats_;
}

// USA: func_02069120
ARM void AccumulateFlag0x800CombatantValue_02069120(void* unused, int* accum) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(0);
    if (combatant == NULL) {
        return;
    }
    BaseCombatStats* stats = GetBaseStats(combatant);
    *accum += sprintf((char*)(*accum), stats->unk);
}
