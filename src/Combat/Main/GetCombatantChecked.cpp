#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_0200ff94
ARM GameObject* GetCombatantChecked_0200ff94(GameState* battleStruct, int combatantId) {
    GameObject* combatant;
    if (combatantId < 0) {
        return 0;
    }
    if (combatantId >= 0xE9) {
        return 0;
    }
    combatant = battleStruct->objects_[combatantId];
    if (combatant == 0) {
        return 0;
    }
    return combatant;
}
