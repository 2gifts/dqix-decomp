#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" float func_ov024_021db358(GameObject* obj);
extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
extern "C" int _Z41PickRandomTableEntryResetCounter_021ed890PP6RandomPiPs(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Buf8_021f286c { short v[8]; };
extern struct Buf8_021f286c data_ov024_021fecfc;

struct Stats_021f286c { char pad[0x2c]; short field0x2c; };
struct Obj_021f286c { int field0; };

// JPN: func_ov024_021f3038
// USA: func_ov024_021f286c
extern "C" ARM int func_ov024_021f286c(Obj_021f286c* obj, int id, int unused, int* outCount, short* outArray) {
	GameObject* self = GetCombatantWithFlag0x400ByID(obj->field0, id);
	if (!self) return 0;
	if (func_ov024_021db358(self) < 0.5f) return 0;

	struct Buf8_021f286c buf = data_ov024_021fecfc;
	int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		if (id == buf.v[i]) continue;
		GameObject* member = GetCombatantByID(obj->field0, buf.v[i]);
		if (!member) continue;
		if (((Stats_021f286c*)member->currentStats_)->field0x2c >= 0) continue;
		if (func_ov024_021db358(member) >= 0.5f) continue;
		int n = *outCount;
		*outCount = n + 1;
		outArray[n] = buf.v[i];
	}
	if (*outCount <= 0) return 0;
	_Z41PickRandomTableEntryResetCounter_021ed890PP6RandomPiPs((struct Random**)obj, outCount, outArray);
	return 1;
}
