#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021edf00(int* a0, int a1, short* a2);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" void func_ov024_021ed8c0(void* context, int id, int recordAddress, int* count, short* ids);

struct FlagObj_021df6ec;
extern "C" int _Z22IsFlagBit6Set_021df6ecP16FlagObj_021df6ec(struct FlagObj_021df6ec* obj);

extern unsigned short data_ov024_021feb2c;

// USA: func_ov024_021edfa0
extern "C" ARM int func_ov024_021edfa0(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* self = GetCombatantByID(*a0, a1);
	if (!self) return 0;
	if (_Z22IsFlagBit6Set_021df6ecP16FlagObj_021df6ec((struct FlagObj_021df6ec*)self)) return 0;

	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021feb2c;
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
		if (self->currentStats_->primaryStats.attack * 2 <= c->currentStats_->primaryStats.defense) continue;
		a4[*a3] = buf[i];
		(*a3)++;
	}
	if (*a3 <= 0) return 0;

	func_ov024_021ed8c0(a0, a1, a2, a3, a4);
	return a4[0] >= 0;
}
