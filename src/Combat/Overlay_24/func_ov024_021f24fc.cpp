#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

struct BuffWord_021f24fc {
	signed int attackBuff : 3;
	signed int defenseBuff : 3;
	signed int agilityBuff : 3;
	signed int charmBuff : 3;
	signed int magicalMightBuff : 3;
	signed int magicalMendingBuff : 3;
	signed int unkBuff18 : 3;
	signed int unkBuff21 : 3;
	signed int unkBuff24 : 3;
};

// USA: func_ov024_021f24fc
extern "C" ARM int func_ov024_021f24fc(int* p0, short id, int unused2, int* outFlag, short* out5) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*p0, id);
	if (!c) return 0;
	struct BuffWord_021f24fc* bw = (struct BuffWord_021f24fc*)((char*)c->currentStats_ + 0x58);
	if (bw->unkBuff24 >= 2) {
		return 0;
	} else {
		*out5 = id;
		*outFlag = 1;
		return 1;
	}
}
