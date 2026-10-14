#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);
extern "C" float func_ov024_021db358(GameObject* obj);

struct Wrapper_021f3688 { int field0; };

// USA: func_ov024_021f3688  (semantic: CheckHPRatioBelowHalfAndOutput_021f3688)
extern "C" ARM int func_ov024_021f3688(struct Wrapper_021f3688* a, int id, int unused2, int* outFlag, short* outId) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(a->field0, id);
	if (!c) return 0;
	int result;
	if (func_ov024_021db358(c) >= 0.5f) {
		result = 0;
	} else {
		result = 1;
		*outFlag = result;
		*outId = (short)id;
	}
	return result;
}
