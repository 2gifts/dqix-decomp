#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02053f7c;
void SetField0x1b2IfMatchOrFlag02053f7c(Obj02053f7c* obj, unsigned short a, int b);

// USA: func_ov017_021c98f4
ARM void SetFieldForMatchingCombatant_021c98f4(int target, int flag) {
#if defined(jpn)
 enum {regionalOffset0=0x1a6};
#else
 enum {regionalOffset0=0x1b2};
#endif
	GameState* bs = GameState::GetInstance();
	int i;
	for (i = 0; i < 4; i++) {
		GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, i);
		if (!c) {
			continue;
		}
		unsigned short val = *(unsigned short*)((char*)c + regionalOffset0);
		if (target != val) {
			continue;
		}
		SetField0x1b2IfMatchOrFlag02053f7c((struct Obj02053f7c*)c, 0, flag);
	}
}
