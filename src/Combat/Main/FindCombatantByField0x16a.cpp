#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_0200ffe0
ARM GameObject* FindCombatantByField0x16a_0200ffe0(GameState* battleStruct, int id) {
    GameObject* combatant;
    int i;
    if (id < 0) {
        return 0;
    }
    for (i = 0x70; i <= 0x9f; i++) {
        combatant = battleStruct->objects_[i];
        if (combatant != 0 && (combatant->obj3D_.unknown_0_ & 0x20) && id == *(unsigned short*)((char*)combatant + 0x16a)) {
            return combatant;
        }
    }
    return 0;
}
