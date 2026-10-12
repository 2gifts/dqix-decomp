#include <globaldefs.h>

#if defined(jpn)
#define func_ov024_021ee33c func_ov024_021eeb08
#endif
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct RngHolder_021ee33c { void* field0; };

// USA: func_ov024_021ee33c  (semantic: CheckHPBelowHalfAndClear_021ee33c)
extern "C" ARM int func_ov024_021ee33c(struct RngHolder_021ee33c* holder, int id, int unused, int* outPtr) {
	GameObject* combatant = GetCombatantByID((int)holder->field0, id);
	if (!combatant) return 0;
	unsigned short currHP = combatant->currentStats_->primaryStats.currHP;
	unsigned short maxHP = combatant->currentStats_->primaryStats.maxHP;
	if ((currHP << 1) <= maxHP) {
		*outPtr = 0;
		return 1;
	}
	return 0;
}
