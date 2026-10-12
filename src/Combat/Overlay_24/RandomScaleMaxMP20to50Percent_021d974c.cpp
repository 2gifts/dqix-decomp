#include <globaldefs.h>

#if defined(jpn)
#define RandomScaleMaxMP20to50Percent_021d974c func_ov024_021da00c
#endif
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

// USA: func_ov024_021d974c
#if defined(jpn)
extern "C"
#endif
ARM int RandomScaleMaxMP20to50Percent_021d974c(struct Random** rngPtr, int id, int a2, int a3, int a4, int val) {
	GameObject* c = GetCombatantByID((int)*rngPtr, (short)id);
	if (!c) return val;
	unsigned short maxMP = c->currentStats_->primaryStats.maxMP;
	struct Random* rng = *rngPtr;
	float f = NextRandomFloatBetween(rng, 0.2f, 0.5f);
	return (int)((float)maxMP * f);
}
