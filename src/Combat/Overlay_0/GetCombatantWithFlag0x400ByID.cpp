#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);

// USA: func_ov000_021536f8
ARM GameObject* GetCombatantWithFlag0x400ByID(int unused, int id) {
	return GetCombatantWithFlag0x400(GameState::GetInstance(), id);
}
