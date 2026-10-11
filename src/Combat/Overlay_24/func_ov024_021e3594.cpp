#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Flag_021e3594 { unsigned char pad : 7; unsigned char flag : 1; };
struct Ctx_021e3594 { char pad0[0x1c]; struct Flag_021e3594 flags; };
struct Obj_021e3594 { char pad0[0xc]; struct Ctx_021e3594* ctx; void* field0x10; };
struct Action_021e3594 {
	char pad0[4];
	unsigned int id : 12;
	unsigned int rest4 : 20;
	char pad8[0x32 - 8];
	short stage;
};
struct Stats_021e3594 { char pad0[0x50]; unsigned char resistRate; };

struct StatStageStruct02087860;
int CanAdjustStatStageBit3(struct StatStageStruct02087860* p, int decrease);
struct StatStageStruct020878b4;
extern "C" int func_020878b4(struct StatStageStruct020878b4* p, int delta);
void UpdateCombatantDefense(int unused, int combatantId);
extern "C" int func_ov024_021e95d4(struct Obj_021e3594* ctx, int id, struct Action_021e3594* params, unsigned char mode, signed char adjustment, unsigned char changed, unsigned char flag);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8ca0;
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

// USA: func_ov024_021e3594
extern "C" ARM unsigned long long func_ov024_021e3594(struct Obj_021e3594* obj, int unused, int id, struct Action_021e3594* action, int count) {
	if (count <= 0) return 0;
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int roll = NextRandomMax((struct Random*)obj->field0x10, 100);
	int stage = action->stage;
	if (stage < -2) stage = -2;
	if (stage > 2) stage = 2;
	int decrease = 0;
	if (stage < 0) {
		if (action->id != 0xad) {
			unsigned char rate = ((struct Stats_021e3594*)c->currentStats_)->resistRate;
			if (rate == 0) return 0;
			if (!obj->ctx->flags.flag) {
				float chance = rate;
				if (roll >= rate) return 0;
			}
		}
		decrease = 1;
	}
	int changed = 0;
	int delta = 0;
	if (CanAdjustStatStageBit3((struct StatStageStruct02087860*)c->currentStats_, (unsigned char)decrease)) {
		delta = func_020878b4((struct StatStageStruct020878b4*)c->currentStats_, (signed char)stage);
		UpdateCombatantDefense((int)obj->field0x10, id);
		changed = 1;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (changed) {
		int msg = func_ov024_021e95d4(obj, id, action, decrease, delta, 1, 1);
		func_ov000_02159eac(obj->field0x10, &local, 0x1e);
		void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((struct Obj_021e8ca0*)obj, msg);
		if (entry) {
			func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
