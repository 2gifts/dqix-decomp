#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_0200fd48
ARM void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id) {
    battleStruct->objects_[id] = NULL;
}
