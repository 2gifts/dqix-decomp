#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" float func_ov024_021db358(GameObject* obj);
extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" int _Z41PickRandomTableEntryResetCounter_021ed890PP6RandomPiPs(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Obj_021f2754 { int field0; };
struct Buf8_021f2754 { short v[8]; };
extern struct Buf8_021f2754 data_ov024_021feccc;

// JPN: func_ov024_021f2f20
// USA: func_ov024_021f2754
extern "C" ARM int func_ov024_021f2754(struct Obj_021f2754* obj, int selfId, int unused, int* outCount, short* outArr) {
	GameObject* self = GetCombatantWithFlag0x400ByID(obj->field0, selfId);
	if (!self) return 0;
	if (func_ov024_021db358(self) < 0.5f) return 0;
	struct Buf8_021f2754 buf = data_ov024_021feccc;
	int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
	if (count <= 0) return 0;
	*outCount = 0;
	for (int i = 0; i < count; i++) {
		if (selfId == buf.v[i]) continue;
		GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
		if (!c) continue;
		if (*(short*)((char*)c->currentStats_ + 0x2c) >= 0) continue;
		int n = *outCount;
		*outCount = n + 1;
		outArr[n] = buf.v[i];
	}
	if (*outCount <= 0) return 0;
	_Z41PickRandomTableEntryResetCounter_021ed890PP6RandomPiPs((struct Random**)obj, outCount, outArr);
	return 1;
}
