#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(int* a0);
struct Combatant_20885b4;
struct S88514;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* c);
int CheckFlag0x2AndState2(struct S88514* s);

struct Buf4_021f4b60 { short v[4]; };
extern struct Buf4_021f4b60 data_ov024_021feb4c;

struct Stats_021f4b60 { char pad[0x4d]; unsigned char field0x4d; };

// JPN: func_ov024_021f532c
// USA: func_ov024_021f4b60
extern "C" ARM int func_ov024_021f4b60(int* a0, int a1, int a2, int* outCount, short* outArray) {
	struct Buf4_021f4b60 buf = data_ov024_021feb4c;
	int count = func_ov000_0215e9fc(*a0, buf.v, 4, 1);
	if (count <= 0) return 0;
	if (!func_ov024_021ede2c(a0)) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, buf.v[i]);
		if (!member) continue;
		if (CheckFlag0x2AndKind1((struct Combatant_20885b4*)member->currentStats_)) continue;
		if (CheckFlag0x2AndState2((struct S88514*)member->currentStats_)) continue;
		int value = ((Stats_021f4b60*)member->currentStats_)->field0x4d;
		if (value <= 0) continue;
		int n = *outCount;
		*outCount = n + 1;
		outArray[n] = buf.v[i];
	}
	if (*outCount <= 0) return 0;
	if (*outCount * 3 < count * 2) return 0;

	*outCount = count;
	memcpy(outArray, &buf, 8);
	return 1;
}
