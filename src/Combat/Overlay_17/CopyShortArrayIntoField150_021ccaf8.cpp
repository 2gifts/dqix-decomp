#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
int GetFieldAt0x150_02053c6c(unsigned char* obj);

struct Src021ccaf8 {
	unsigned short arr[6];
	unsigned short id;
	unsigned char idx;
};

// USA: func_ov017_021ccaf8
ARM void CopyShortArrayIntoField150_021ccaf8(int unused0, char* p1raw, GameState* bs) {
	struct Src021ccaf8* p1 = (struct Src021ccaf8*)(p1raw + 4);

	GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, p1->id);
	if (!c) return;

	int field150 = GetFieldAt0x150_02053c6c((unsigned char*)c);
	if (!field150) return;

	unsigned char idx = p1->idx;
	for (unsigned char i = 0; i < 6; i++) {
		unsigned short v = p1->arr[i];
		short* dst = (short*)((char*)field150 + (i + idx) * 2 + 0x100 + 0x6c);
		*dst = v;
	}
}
