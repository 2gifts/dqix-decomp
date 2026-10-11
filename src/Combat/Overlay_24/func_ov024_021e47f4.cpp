#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087c30;
extern "C" int _Z23CanAdjustStatStageBit15P23StatStageStruct02087c30i(struct StatStageStruct02087c30* p, unsigned char decrease);
struct StatStageStruct02087c84;
int SetStatStageBit15(struct StatStageStruct02087c84* p, int delta);
void UpdateCombatantMagicalMending(int random, int combatantId);
struct RefStruct_021e9990;
struct Info_021e47f4;
extern "C" int _Z29CheckPersonalityCode_021e9990P18RefStruct_021e9990iiia(struct RefStruct_021e9990* s, int id, struct Info_021e47f4* info, unsigned char decrease, signed char sb);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8ca0;
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Obj_021e47f4 { char pad0[0x10]; void* field0x10; };
struct Info_021e47f4 { char pad0[0x32]; short stageDelta; };

// JPN: func_ov024_021e508c
// USA: func_ov024_021e47f4
extern "C" ARM unsigned long long func_ov024_021e47f4(struct Obj_021e47f4* obj, int unused, int id, struct Info_021e47f4* info) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int delta = info->stageDelta;
	if (delta < -2) delta = -2;
	if (delta > 2) delta = 2;
	int decrease = 0;
	if (delta < 0) decrease = 1;
	int applied = 0;
	int result = 0;
	if (_Z23CanAdjustStatStageBit15P23StatStageStruct02087c30i((struct StatStageStruct02087c30*)c->currentStats_, decrease)) {
		result = SetStatStageBit15((struct StatStageStruct02087c84*)c->currentStats_, (signed char)delta);
		UpdateCombatantMagicalMending((int)obj->field0x10, id);
		applied = 1;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (applied) {
		int code = _Z29CheckPersonalityCode_021e9990P18RefStruct_021e9990iiia((struct RefStruct_021e9990*)obj, id, info, decrease, result);
		func_ov000_02159eac(obj->field0x10, &local, 0x21);
		void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((struct Obj_021e8ca0*)obj, code);
		if (entry) {
			func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
