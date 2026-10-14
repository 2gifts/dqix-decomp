#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

static inline unsigned short GetMaxMP(GameObject* c) { ModifiableCombatStats* stats = c->currentStats_; return stats->primaryStats.maxMP; }
static inline unsigned short GetCurrMP(GameObject* c) { ModifiableCombatStats* stats = c->currentStats_; return stats->primaryStats.currMP; }

// USA: func_ov024_021f32b4  (semantic: RatioBelow0Point125_021f32b4)
extern "C" ARM int func_ov024_021f32b4(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	float ratio = (float)GetCurrMP(c) / (float)GetMaxMP(c);
	if (ratio > 0.125f) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
