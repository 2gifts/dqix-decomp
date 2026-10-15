#include <globaldefs.h>
#include "GameState/GameState.h"

void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);

// USA: func_02057db8
ARM void ClearCombatantSlotIfValidId02057db8(void* unused, int id) {
    if (id < 0xd0) return;
    if (id > 0xdf) return;
    ClearCombatantSlot_0200fd48(GameState::GetInstance(), id);
}
