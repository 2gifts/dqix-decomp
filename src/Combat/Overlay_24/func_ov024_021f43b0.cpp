#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(void* obj);
struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);

extern unsigned short data_ov024_021fec3c;

struct Obj_43b0 { int field0; };

// USA: func_ov024_021f43b0  (semantic: TryFindNonKind1AndCopyTable_021f43b0)
extern "C" ARM int func_ov024_021f43b0(struct Obj_43b0* obj, int a1, int a2, int* outCount, short* outArray) {
	short buf[4];
	unsigned short* d = (unsigned short*)buf;
	unsigned short* s = &data_ov024_021fec3c;
	int n = 4;
	do {
		unsigned short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(obj->field0, (unsigned short*)buf, 4, 1);
	if (count <= 0) return 0;
	if (!func_ov024_021ede2c(obj)) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(obj->field0, buf[i]);
		if (!c) continue;
		if (CheckFlag0x2AndKind1((struct Combatant_20885b4*)c->currentStats_)) continue;
		int n2 = *outCount;
		*outCount = n2 + 1;
		outArray[n2] = buf[i];
	}
	if (*outCount <= 0) return 0;
	*outCount = count;
	memcpy(outArray, buf, 8);
	return 1;
}
