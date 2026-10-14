#include <globaldefs.h>
#include "GameState/GameState.h"

struct Bits40_37464;

// USA: func_020243b8
ARM int CheckCombatantReadyForAction020243b8(void* unused, int combatantId) {
    if (combatantId < 0) {
        return 1;
    }
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), combatantId);
    if (combatant == NULL) {
        return 1;
    }
    if (((Object3D*)((struct Bits40_37464*)combatant))->GetInheritedAlpha() == 0) {
        return 0;
    }
    if (((Object3D*)((unsigned char*)combatant))->GetAlphaScaleFactor() == 0) {
        return 0;
    }
    return ((Object3D*)((unsigned char*)combatant))->IsVisible() != 0;
}
