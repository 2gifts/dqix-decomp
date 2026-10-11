#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(int* a0);

struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2(struct S88514* obj);

extern unsigned short data_ov024_021fea8c;

// USA: func_ov024_021f4a54  (semantic: CollectEligibleAndCopyTable_021f4a54)
extern "C" ARM int func_ov024_021f4a54(int* a0, int a1, int a2, int* a3, short* a4) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021fea8c;
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
		if (c && !CheckFlag0x2AndKind1((struct Combatant_20885b4*)c->currentStats_) &&
		    !CheckFlag0x2AndState2((struct S88514*)c->currentStats_)) {
			int idx = *a3;
			*a3 = idx + 1;
			a4[idx] = buf[i];
		}
	}
	if (*a3 <= 0) return 0;

	*a3 = count;
	memcpy(a4, buf, 8);
	return 1;
}
