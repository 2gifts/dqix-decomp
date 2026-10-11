#include <globaldefs.h>
#include "Util/Random.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" int _Z41PickRandomTableEntryResetCounter_021ed890PP6RandomPiPs(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Obj_021f3c3c { int field0; };
struct Buf8_021f3c3c { short v[8]; };
extern struct Buf8_021f3c3c data_ov024_021feeac;

static inline unsigned short GetMaxMP_021f3c3c(GameObject* c) { return c->currentStats_->primaryStats.maxMP; }

// USA: func_ov024_021f3c3c
extern "C" ARM int func_ov024_021f3c3c(struct Obj_021f3c3c* obj, int id, int unused, int* outCount, short* outArr) {
	GameObject* self = GetCombatantWithFlag0x400ByID(obj->field0, id);
	if (!self) return 0;
	if (self->currentStats_->primaryStats.currMP == 0) return 0;
	struct Buf8_021f3c3c buf = data_ov024_021feeac;
	int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
	if (count <= 0) return 0;
	*outCount = 0;
	for (int i = 0; i < count; i++) {
		if (id == buf.v[i]) continue;
		GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
		if (!c) continue;
		unsigned short maxMP = GetMaxMP_021f3c3c(c);
		if ((float)c->currentStats_->primaryStats.currMP / (float)maxMP >= 1.0f) continue;
		outArr[(*outCount)++] = buf.v[i];
	}
	if (*outCount <= 0) return 0;
	_Z41PickRandomTableEntryResetCounter_021ed890PP6RandomPiPs((struct Random**)obj, outCount, outArr);
	return 1;
}
