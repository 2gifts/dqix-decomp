#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

struct WeaknessBits_021f40c8 {
    signed int w0:3;
    signed int w1:3;
    signed int w2:3;
    signed int w3:3;
    signed int w4:3;
    signed int w5:3;
    signed int w6:3;
    signed int w7:3;
    signed int w8:3;
    signed int w9:3;
    signed int pad:2;
};

// USA: func_ov024_021f40c8  (semantic: CheckWeaknessSlot4And5_021f40c8)
extern "C" ARM int func_ov024_021f40c8(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	struct WeaknessBits_021f40c8* w = (struct WeaknessBits_021f40c8*)((char*)c->currentStats_ + 0x58);
	if (w->w4 >= 2 || w->w5 >= 2) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
