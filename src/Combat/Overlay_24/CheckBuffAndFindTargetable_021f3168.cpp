#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);
extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
struct RngHolder_021ed9dc;
int CanTargetCombatant_021ed9dc(struct RngHolder_021ed9dc* holder, int id);

extern unsigned short data_ov024_021fed8c;

struct BuffWord_021f3168 {
	signed int attackBuff : 3;
	signed int defenseBuff : 3;
	signed int agilityBuff : 3;
	signed int charmBuff : 3;
	signed int magicalMightBuff : 3;
	signed int magicalMendingBuff : 3;
	signed int unkBuff18 : 3;
	signed int unkBuff21 : 3;
};

// USA: func_ov024_021f3168  (semantic: CheckBuffAndFindTargetable_021f3168)
extern "C" ARM int func_ov024_021f3168(int* a0, int id, int a2, int* outFlag, short* outId) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*a0, id);
	if (!c) return 0;
	if (((struct BuffWord_021f3168*)((char*)c->currentStats_ + 0x58))->unkBuff18 >= 2) return 0;

	unsigned short buf[8];
	unsigned short* d = buf;
	unsigned short* s = &data_ov024_021fed8c;
	int n = 8;
	do {
		unsigned short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
	if (count <= 0) return 0;

	int found = 0;
	for (int i = 0; i < count; i++) {
		if (CanTargetCombatant_021ed9dc((struct RngHolder_021ed9dc*)a0, *(short*)&buf[i])) {
			found = 1;
			break;
		}
	}
	if (!found) return 0;
	*outFlag = 1;
	*outId = (short)id;
	return 1;
}
