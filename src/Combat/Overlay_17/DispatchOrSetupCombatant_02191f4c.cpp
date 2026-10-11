#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
void SetFieldndDispatch_021bdb78_021bdb78(int id);
void SetupAndDispatchCombatant_02191e5c(int a, int b, short c, unsigned char d, unsigned short e);

extern "C" void func_ov017_0218f80c(int a, int b);

// JPN: func_ov017_02192b14
// USA: func_ov017_02191f4c
ARM void DispatchOrSetupCombatant_02191f4c(int a, int b) {
#if defined(jpn)
 enum {regionalOffset0=0x180};
#else
 enum {regionalOffset0=0x18c};
#endif
	GameState* battleStruct = GameState::GetInstance();
	GameObject* combatant = battleStruct->GetCombatantByIndex(b);
	if (!combatant) return;
	GameObject* c2 = GetCombatantWithFlag0x100(battleStruct, b);
	if (c2 != NULL && (*(int*)((char*)c2 + regionalOffset0) & 0x40)) {
		SetFieldndDispatch_021bdb78_021bdb78(b);
		return;
	}
	SetupAndDispatchCombatant_02191e5c(a, b, 0x1000, 0, 0);
	int inRange = (b >= 0 && b <= 3);
	if (inRange) {
		func_ov017_0218f80c(a, b);
	}
}
