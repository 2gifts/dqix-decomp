#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov004_0215f74c
ARM int HasCombatantWithFlag_0215f74c_0215f74c(int unused, int combatantId) {
	return GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), combatantId) != NULL;
}
