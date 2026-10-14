#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

// USA: func_ov024_021f4120  (semantic: CheckCharmBelow2_021f4120)
extern "C" ARM int func_ov024_021f4120(int* p0, short id, int unused2, int* outFlag, short* out5) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*p0, id);
	if (!c) return 0;
	unsigned short charm = c->currentStats_->primaryStats.charm;
	if (charm >= 2) {
		return 0;
	} else {
		*outFlag = 1;
		*out5 = id;
		return 1;
	}
}
