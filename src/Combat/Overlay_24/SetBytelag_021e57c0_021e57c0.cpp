#include <globaldefs.h>

#if defined(jpn)
#define SetBytelag_021e57c0_021e57c0 func_ov024_021e6058
#endif
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
// USA: func_ov024_021e57c0
#if defined(jpn)
extern "C"
#endif
ARM void SetBytelag_021e57c0_021e57c0(int* param_1, int id) {
	GameObject* combatant = GetCombatantByID(param_1[4], id);
	if (combatant != NULL) {
		*((char*)combatant->currentStats_ + 0x21) = 1;
	}
}
