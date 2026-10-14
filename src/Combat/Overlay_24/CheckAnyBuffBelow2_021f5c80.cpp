#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

struct Wrapper_021f5c80 {
	int field0;
};

// USA: func_ov024_021f5c80
ARM int CheckAnyBuffBelow2_021f5c80(struct Wrapper_021f5c80* a, int id, int unused2, int* outFlag, short* outId) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(a->field0, id);
	if (!c) return 0;
	int result;
	if (c->currentStats_->attackBuff >= 2 && c->currentStats_->defenseBuff >= 2 && c->currentStats_->agilityBuff >= 2) {
		result = 0;
	} else {
		result = 1;
		*outFlag = result;
		*outId = (short)id;
	}
	return result;
}
