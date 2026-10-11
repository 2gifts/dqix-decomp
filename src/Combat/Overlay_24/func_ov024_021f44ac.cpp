#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(int* a0);

struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);

struct Stats_021f44ac { char pad[0x4d]; unsigned char field0x4d; };

extern unsigned short data_ov024_021fea94;

// JPN: func_ov024_021f4c78
// USA: func_ov024_021f44ac
extern "C" ARM int func_ov024_021f44ac(int* a0, int a1, int a2, int* a3, short* a4) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021fea94;
	int n = 4;
	do {
		short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, (unsigned short*)buf, 4, 1);
	if (count <= 0) return 0;
	if (!func_ov024_021ede2c(a0)) return 0;

	*a3 = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(*a0, buf[i]);
		if (!c) continue;
		if (CheckFlag0x2AndKind1((struct Combatant_20885b4*)c->currentStats_)) continue;
		short level = ((struct Stats_021f44ac*)c->currentStats_)->field0x4d;
		if (level <= 0) continue;
		int idx = *a3;
		*a3 = idx + 1;
		a4[idx] = buf[i];
	}
	if (*a3 <= 0) return 0;
	if (*a3 * 3 < count * 2) return 0;

	*a3 = count;
	memcpy(a4, buf, 8);
	return 1;
}
