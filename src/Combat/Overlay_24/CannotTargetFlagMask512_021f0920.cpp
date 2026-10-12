#include <globaldefs.h>

#if defined(jpn)
#define func_ov024_021f0920 func_ov024_021f10ec
#endif
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

int IsCombatantFlagMask512_021eda60(GameObject* combatant);

struct RngHolder_021f0920 { void* field0; };

// USA: func_ov024_021f0920  (semantic: CannotTargetFlagMask512_021f0920)
extern "C" ARM int func_ov024_021f0920(struct RngHolder_021f0920* holder, int id) {
	GameObject* combatant = GetCombatantByID((int)holder->field0, id);
	if (!combatant) return 0;
	int flag = IsCombatantFlagMask512_021eda60(combatant);
	int result = !flag;
	return result;
}
