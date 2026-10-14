#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* FindCombatantByField16a_021a278c(void* unused, int val);
extern "C" void func_02076a8c(void* c);

// USA: func_ov017_021a23b0  (semantic: MaybeSetFlag6cForCombatant_021a23b0)
extern "C" ARM void func_ov017_021a23b0(void* self, int val) {
	GameState::GetInstance();
	GameObject* c = FindCombatantByField16a_021a278c(self, val);
	if (!c) return;
	func_02076a8c(c);
	((Object3D*)((unsigned char*)c))->MakeHidden();
}
