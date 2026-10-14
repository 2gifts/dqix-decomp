#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02053f7c;
void SetField0x1b2IfMatchOrFlag02053f7c(Obj02053f7c* obj, unsigned short a, int b);

// USA: func_ov017_02192594
ARM void SetFlag1ForFlagombatants_02192594_02192594(unsigned char* base) {
	GameState* bs = GameState::GetInstance();
	int i;
	for (i = 0; i < 4; i++) {
		GameObject* c = bs->GetPartyMemberByIndex(i);
		if (c) {
			SetField0x1b2IfMatchOrFlag02053f7c((struct Obj02053f7c*)c, 0, 1);
		}
	}
}
