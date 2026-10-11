#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087c30;
int CanAdjustStatStageBit15(struct StatStageStruct02087c30* p, int decrease);
struct StatStageStruct02087c84;
int SetStatStageBit15(struct StatStageStruct02087c84* p, int delta);
void UpdateCombatantMagicalMending(int unused, int combatantId);
struct RefStruct_021e9990;
extern "C" unsigned short _Z29CheckPersonalityCode_021e9990P18RefStruct_021e9990iiia(struct RefStruct_021e9990* s, int id, int unused2, int flag, signed char sb);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021dee84 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};
struct Flag_021dee84 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021dee84 { char pad0[0xc]; void* field0xc; void* field0x10; int field0x14; };
struct Action_021dee84 { char pad0[0x24]; struct PackedPair_021dee84 f24; char pad1[0x8]; short field30; };

// JPN: func_ov024_021df71c
// USA: func_ov024_021dee84
extern "C" ARM void* func_ov024_021dee84(struct Obj_021dee84* obj, int unused, int id, struct Action_021dee84* action, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int applied = 0;
	int result = applied;
	int decrease = applied;
	if (flagArg) {
		int stage = action->field30;
		if (stage < -2) stage = -2;
		if (stage > 2) stage = 2;
		if (stage < 0) decrease = 1;
		if (CanAdjustStatStageBit15((struct StatStageStruct02087c30*)c->currentStats_, (unsigned char)decrease)) {
			result = SetStatStageBit15((struct StatStageStruct02087c84*)c->currentStats_, (signed char)stage);
			UpdateCombatantMagicalMending((int)obj->field0x10, id);
			obj->field0x14++;
			applied = 1;
		}
	}
	unsigned short sel = 0;
	if (applied) {
		sel = _Z29CheckPersonalityCode_021e9990P18RefStruct_021e9990iiia((struct RefStruct_021e9990*)obj, id, (int)action, (unsigned char)decrease, result);
	} else {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, action->f24.b, action->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->field0xc, &sel);
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021dee84* fl = (struct Flag_021dee84*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
