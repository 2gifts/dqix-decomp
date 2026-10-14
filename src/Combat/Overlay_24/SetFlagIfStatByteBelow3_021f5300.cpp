#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

// USA: func_ov024_021f5300
ARM int SetFlagIfStatByteBelow3_021f5300(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	if (((unsigned char*)c->currentStats_)[0x24] >= 3) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
