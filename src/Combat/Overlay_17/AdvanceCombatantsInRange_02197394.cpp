#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

// USA: func_ov017_02197394
ARM void AdvanceCombatantsInRange_02197394(GameResources*) {
    GameState* bs = GameState::GetInstance();
    int id;
    for (id = 0xa0; id < 0xc0; id++) {
        GameObject* combatant = bs->GetGameObjectByIndex(id);
        if (!combatant) continue;
        if (combatant->obj3D_.GetFlag(0x40000000) != 0) continue;
        combatant->obj3D_.AdvanceEffects();
    }
}
