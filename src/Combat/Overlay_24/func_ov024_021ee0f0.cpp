#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021edf00(int* a0, int a1, short* a2);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" void func_ov024_021ed8c0(void* context, int id, int recordAddress, int* count, short* ids);
extern "C" int _Z31IsCombatantFlagMask512_021eda60P10GameObject(GameObject* combatant);

extern unsigned short data_ov024_021fea84;

// USA: func_ov024_021ee0f0
extern "C" ARM int func_ov024_021ee0f0(int* a0, int a1, int a2, int* a3, short* a4) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021fea84;
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
		if (_Z31IsCombatantFlagMask512_021eda60P10GameObject(c)) continue;
		a4[*a3] = buf[i];
		(*a3)++;
	}
	if (*a3 <= 0) return 0;

	func_ov024_021ed8c0(a0, a1, a2, a3, a4);
	return *a4 >= 0 ? 1 : 0;
}
