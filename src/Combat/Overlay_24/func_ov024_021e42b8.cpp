#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087954;
int CanAdjustStatStageBit6(struct StatStageStruct02087954* p, int decrease);
extern "C" int func_020879a8(void* p, signed char delta);
void UpdateCombatantAgility(int unused, int id);
extern "C" int func_ov024_021e96e4(void* ctx, int id, void* params, unsigned char mode, signed char result, unsigned char resultFlag, unsigned char specialFlag);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8ca0;
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Obj_021e42b8 { char pad0[0x10]; void* field0x10; };
struct Params_021e42b8 { char pad0[0x32]; short stageDelta; };

// USA: func_ov024_021e42b8
extern "C" ARM unsigned long long func_ov024_021e42b8(struct Obj_021e42b8* obj, int unused, int id, struct Params_021e42b8* params) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int delta = params->stageDelta;
	if (delta < -2) delta = -2;
	if (delta > 2) delta = 2;
	int decrease = 0;
	if (delta < 0) decrease = 1;
	int changed = 0;
	int newStage = 0;
	if (CanAdjustStatStageBit6((struct StatStageStruct02087954*)c->currentStats_, (unsigned char)decrease)) {
		newStage = func_020879a8(c->currentStats_, delta);
		UpdateCombatantAgility((int)obj->field0x10, id);
		changed = 1;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (changed) {
		int msg = func_ov024_021e96e4(obj, id, params, decrease, newStage, 1, 1);
		func_ov000_02159eac(obj->field0x10, &local, 0x1f);
		void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((struct Obj_021e8ca0*)obj, msg);
		if (entry) {
			func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0);
		}
	}
	return local.v;
}
