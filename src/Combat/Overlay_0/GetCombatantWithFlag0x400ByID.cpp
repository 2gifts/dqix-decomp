#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);

// USA: func_ov000_021536f8
ARM GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id) {
	return GetCombatantWithFlag0x400_0200fea4(GameState::GetInstance(), id);
}
