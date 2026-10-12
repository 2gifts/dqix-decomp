#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);

static inline unsigned short GetMaxMP(GameObject* c) { ModifiableCombatStats* stats = c->currentStats_; return stats->primaryStats.maxMP; }
static inline unsigned short GetCurrMP(GameObject* c) { ModifiableCombatStats* stats = c->currentStats_; return stats->primaryStats.currMP; }

// USA: func_ov024_021f3248  (semantic: RatioBelow0Point1_021f3248)
extern "C" ARM int func_ov024_021f3248(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = GetCombatantWithFlag0x400ByID(*a0, a1);
	if (!c) return 0;
	float ratio = (float)GetCurrMP(c) / (float)GetMaxMP(c);
	if (ratio > 0.1f) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
