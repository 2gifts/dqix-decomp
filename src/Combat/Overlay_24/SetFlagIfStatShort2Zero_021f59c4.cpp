#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

// USA: func_ov024_021f59c4
ARM int SetFlagIfStatShort2Zero_021f59c4(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	if (*(unsigned short*)((unsigned char*)c->currentStats_ + 2) != 0) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
