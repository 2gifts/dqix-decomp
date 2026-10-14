#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);

void SetGroupShortValues_021919c8(int unusedA, int b, short c);
extern "C" void func_ov017_0218fd34(int a, int b, unsigned short e);
extern "C" void func_ov017_0218f968(int a, int b, unsigned short e);

// USA: func_ov017_02191e5c
ARM void SetupAndDispatchCombatant_02191e5c(int a, int b, short c, unsigned char d, unsigned short e) {
	GameState* battleStruct = GameState::GetInstance();
	int inRange1 = (b >= 0 && b <= 3);
	if (inRange1) {
		if (!battleStruct->GetPartyMemberByIndex(b)) return;
	}
	GameObject* combatant = battleStruct->GetCombatantByIndex(b);
	if (!combatant) return;
	SetGroupShortValues_021919c8(a, b, c);
	*(unsigned short*)((char*)combatant + 0x9c) = e;
	((Object3D*)((unsigned char*)combatant))->SetField9e(d);
	int inRange2 = (b >= 0 && b <= 3);
	if (inRange2) {
		GameObject* c2 = GetCombatantWithFlag0x100(battleStruct, b);
		if (!c2) return;
		if (!CheckField0x56bLowNibble((struct Obj02061bd8*)c2)) {
			func_ov017_0218fd34(a, b, e);
			return;
		}
	}
	func_ov017_0218f968(a, b, e);
}
