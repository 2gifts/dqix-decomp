#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021edf00(int* a0, int a1, short* a2);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" void func_ov024_021ed8c0(void* context, int id, int recordAddress, int* count, short* ids);

struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2(struct S88514* obj);
struct FlagInner_021da9b0 { char unk[0x14]; int flags; };
struct FlagObj_021da9b0 { char unk[0x138]; struct FlagInner_021da9b0* inner; };
extern "C" int _Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0(struct FlagObj_021da9b0* obj);

extern unsigned short data_ov024_021fec24;

// JPN: func_ov024_021f21d8
// USA: func_ov024_021f1a0c
extern "C" ARM int func_ov024_021f1a0c(int* a0, int a1, int a2, int* a3, short* a4) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021fec24;
	int n = 4;
	do {
		short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov024_021edf00(a0, a1, buf);
	if (count <= 0) {
		count = func_ov000_0215e9fc(*a0, buf, 4, 1);
		if (count <= 0) return 0;
	}

	*a3 = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(*a0, buf[i]);
		if (!c) continue;
		if (!CheckFlag0x2AndKind1((struct Combatant_20885b4*)c->currentStats_) &&
		    !CheckFlag0x2AndState2((struct S88514*)c->currentStats_) &&
		    !_Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0((struct FlagObj_021da9b0*)c)) continue;
		int idx = *a3;
		*a3 = idx + 1;
		a4[idx] = buf[i];
	}
	if (*a3 <= 0) return 0;

	func_ov024_021ed8c0(a0, a1, a2, a3, a4);
	return 1;
}
