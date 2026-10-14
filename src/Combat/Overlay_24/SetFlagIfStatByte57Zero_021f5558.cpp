#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

// USA: func_ov024_021f5558
ARM int SetFlagIfStatByte57Zero_021f5558(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	if (((unsigned char*)c->currentStats_)[0x39] != 0) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
