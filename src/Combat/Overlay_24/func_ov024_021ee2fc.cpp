#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct RngHolder_021ee2fc { void* field0; };

static inline int GetMaxHP(GameObject* c) { int v = c->currentStats_->primaryStats.maxHP; return v; }
static inline int GetCurrHP(GameObject* c) { int v = c->currentStats_->primaryStats.currHP; return v; }

// USA: func_ov024_021ee2fc
extern "C" ARM int func_ov024_021ee2fc(struct RngHolder_021ee2fc* holder, int id, int unused, int* outPtr) {
	GameObject* combatant = GetCombatantByID((int)holder->field0, id);
	if (!combatant) return 0;
	if (GetCurrHP(combatant) * 3 <= GetMaxHP(combatant)) {
		*outPtr = 0;
		return 1;
	}
	return 0;
}
