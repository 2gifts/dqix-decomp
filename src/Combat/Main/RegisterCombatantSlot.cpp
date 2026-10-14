#include <globaldefs.h>
#include "GameState/GameState.h"

struct SlotBackRef_fd38 {
    char pad[4];
    unsigned short id;
};

// USA: func_0200fd38
ARM void RegisterCombatantSlot_0200fd38(GameState* battleStruct, int id, GameObject* combatant) {
    battleStruct->objects_[id] = combatant;
    ((struct SlotBackRef_fd38*)combatant)->id = id;
}
