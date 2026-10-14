#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150_02053c6c(unsigned char* obj);

struct FieldWord0x150_021da404 { unsigned int w0; unsigned int val : 10; };

// USA: func_ov024_021da404  (semantic: AverageFallbackWithFieldScale_021da404)
extern "C" ARM int func_ov024_021da404(int a, int id, int b, int c, int d, int fallback) {
	int valid = (unsigned int)id <= 3;
	if (!valid) {
		return fallback;
	}
	GameState* battleStruct = GameState::GetInstance();
	GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battleStruct, id);
	if (!combatant) {
		return fallback;
	}
	struct FieldWord0x150_021da404* fieldPtr = (struct FieldWord0x150_021da404*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
	if (fieldPtr) {
		unsigned int v = fieldPtr->val;
		int scaled = (int)((float)v * 0.25f);
		fallback = scaled + fallback / 2;
	}
	return fallback;
}
