#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
struct S_bf3c_021f1440;
int IsBitfield2Set_021f1440(struct S_bf3c_021f1440* obj);
extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Buf8_021f1330 { short v[8]; };
extern struct Buf8_021f1330 data_ov024_021fef3c;

struct BuffWord_021f1330 {
	signed int attackBuff : 3;
	signed int defenseBuff : 3;
	signed int agilityBuff : 3;
	signed int charmBuff : 3;
	signed int magicalMightBuff : 3;
	signed int magicalMendingBuff : 3;
	signed int unkBuff18 : 3;
	signed int unkBuff21 : 3;
};

// USA: func_ov024_021f1330  (semantic: SelectLowUnkBuff21AndMaybePick_021f1330)
extern "C" ARM int func_ov024_021f1330(int* a0, int a1, int a2, int* outCount, short* outArray) {
	GameObject* gate = GetCombatantWithFlag0x400ByID(*a0, a1);
	if (!gate) return 0;
	if (!IsBitfield2Set_021f1440((struct S_bf3c_021f1440*)gate)) return 0;

	struct Buf8_021f1330 buf = data_ov024_021fef3c;

	int count = func_ov000_0215eb1c(*a0, buf.v, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, buf.v[i]);
		if (!member) continue;
		struct BuffWord_021f1330* bw = (struct BuffWord_021f1330*)((char*)member->currentStats_ + 0x58);
		if (bw->unkBuff21 >= 2) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		outArray[idx] = buf.v[i];
	}
	if (*outCount > 0) {
		PickRandomTableEntryResetCounter_021ed890((struct Random**)a0, outCount, outArray);
		return 1;
	}
	return 0;
}
