#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
struct FlagObj_021e05e4;
extern "C" int _Z30IsFlagBit12Field18Set_021e05e4P16FlagObj_021e05e4(struct FlagObj_021e05e4* obj);
struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
extern "C" int func_ov024_021edf00(int* a0, int a1, short* a2);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
struct FlagObj_021da998;
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(struct FlagObj_021da998* obj);
struct FlagObj_021dd260;
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(struct FlagObj_021dd260* obj);
extern "C" void func_ov024_021ed8c0(void* context, int id, int recordAddress, int* count, short* ids);

struct Stats_021f2ab4 { char pad0[0x2e]; short targetId; };

extern unsigned short data_ov024_021feb5c;

// JPN: func_ov024_021f3280
// USA: func_ov024_021f2ab4
extern "C" ARM int func_ov024_021f2ab4(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = GetCombatantWithFlag0x400ByID(*a0, a1);
	if (!c) return 0;
	if (_Z30IsFlagBit12Field18Set_021e05e4P16FlagObj_021e05e4((struct FlagObj_021e05e4*)c)) {
		GameObject* target = GetCombatantByID(*a0, ((struct Stats_021f2ab4*)c->currentStats_)->targetId);
		if (target && !IsFlag10088Set((struct S_10088*)target)) {
			*a3 = 1;
			a4[0] = ((struct Stats_021f2ab4*)c->currentStats_)->targetId;
			return 1;
		}
	}

	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021feb5c;
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
		GameObject* m = GetCombatantByID(*a0, buf[i]);
		if (m && (_Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((struct FlagObj_021da998*)m) || _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260((struct FlagObj_021dd260*)m))) {
			int idx = *a3;
			*a3 = idx + 1;
			a4[idx] = buf[i];
		}
	}
	if (*a3 <= 0) return 0;

	func_ov024_021ed8c0(a0, a1, a2, a3, a4);
	return 1;
}
