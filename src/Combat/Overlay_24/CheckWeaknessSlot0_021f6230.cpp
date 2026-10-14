#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

struct WeaknessBits_021f6230 {
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

struct Sub_021f6230 { char pad[8]; unsigned short field8; char pad2[0x4e]; struct WeaknessBits_021f6230 weak; };

// USA: func_ov024_021f6230  (semantic: CheckWeaknessSlot0_021f6230)
#pragma optimize_for_size off
extern "C" ARM int func_ov024_021f6230(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	struct Sub_021f6230* s = (struct Sub_021f6230*)c->currentStats_;
	if (s->field8 >= 0xffff) goto fail;
	if (s->weak.w0 < 2) goto success;
fail:
	return 0;
success:
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
