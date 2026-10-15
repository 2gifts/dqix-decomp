#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087c30;
int CanAdjustStatStageBit15(StatStageStruct02087c30*, unsigned char);
struct StatStageStruct02087c84;
int SetStatStageBit15(struct StatStageStruct02087c84* p, int delta);
void UpdateCombatantMagicalMending(int random, int combatantId);
struct RefStruct_021e9990;
struct Info_021e47f4;
int CheckPersonalityCode_021e9990(RefStruct_021e9990*, int, int, unsigned char, signed char);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8ca0;
void* AddEntryToListAndIncCount_021e8ca0(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Obj_021e47f4 { char pad0[0x10]; void* field0x10; };
struct Info_021e47f4 { char pad0[0x32]; short stageDelta; };

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
	if (CanAdjustStatStageBit15((struct StatStageStruct02087c30*)c->currentStats_, decrease)) {
		result = SetStatStageBit15((struct StatStageStruct02087c84*)c->currentStats_, (signed char)delta);
		UpdateCombatantMagicalMending((int)obj->field0x10, id);
		applied = 1;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (applied) {
		int code = CheckPersonalityCode_021e9990((struct RefStruct_021e9990*)obj, id, (int)info, decrease, result);
		func_ov000_02159eac(obj->field0x10, &local, 0x21);
		void* entry = AddEntryToListAndIncCount_021e8ca0((struct Obj_021e8ca0*)obj, code);
		if (entry) {
			func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
