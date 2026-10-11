#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087b3c;
struct StatStageStruct02087b90;
int CanAdjustStatStageBit12(struct StatStageStruct02087b3c* p, int decrease);
int SetStatStageBit12(struct StatStageStruct02087b90* p, int delta);
void UpdateCombatantMagicalMight(int unused, int combatantId);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8ca0;
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Obj_021e4158 { char pad0[0xc]; void* field0xc; void* field0x10; };
struct Range_021e4158 { char pad[0x32]; short stageDelta; };

// JPN: func_ov024_021e49f0
// USA: func_ov024_021e4158
extern "C" ARM unsigned long long func_ov024_021e4158(struct Obj_021e4158* obj, int unused, int id, struct Range_021e4158* range) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int delta = range->stageDelta;
	if (delta < -2) delta = -2;
	if (delta > 2) delta = 2;
	int decrease = 0;
	if (delta < 0) decrease = 1;
	int applied = 0;
	int stage = 0;
	if (CanAdjustStatStageBit12((struct StatStageStruct02087b3c*)c->currentStats_, (unsigned char)decrease)) {
		stage = SetStatStageBit12((struct StatStageStruct02087b90*)c->currentStats_, (signed char)delta);
		UpdateCombatantMagicalMight((int)obj->field0x10, id);
		applied = 1;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (applied) {
		int msg;
		if (delta > 0) {
			switch (stage) {
			case 2: msg = 0xd0; break;
			case 0: msg = 0x1b7; break;
			default: msg = 0xd1; break;
			}
		} else {
			switch (stage) {
			case -2: msg = 0x1b6; break;
			case 0: msg = 0x1b7; break;
			default: msg = 0x1b5; break;
			}
		}
		func_ov000_02159eac(obj->field0x10, &local, 0x20);
		void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((struct Obj_021e8ca0*)obj, msg);
		if (entry) {
			func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
