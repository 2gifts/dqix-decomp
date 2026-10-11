#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087a48;
struct StatStageStruct02087a9c;
int CanAdjustStatStageBit9(struct StatStageStruct02087a48* p, int decrease);
int SetStatStageBit9(struct StatStageStruct02087a9c* p, int delta);
void UpdateCombatantCharm(int unused, int combatantId);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021e0380 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Flag_021e0380 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021e0380 { char pad0[0xc]; void* field0xc; void* field0x10; };
struct Range_021e0380 { char pad[0x24]; struct PackedPair_021e0380 f24; char pad28[0x8]; short stageDelta; };

// JPN: func_ov024_021e0c18
// USA: func_ov024_021e0380
extern "C" ARM void* func_ov024_021e0380(struct Obj_021e0380* obj, int unused, int id, struct Range_021e0380* range, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int applied = 0;
	int stage = 0;
	if (flagArg != 0) {
		int delta = range->stageDelta;
		if (delta < -2) delta = -2;
		if (delta > 2) delta = 2;
		int decrease = 0;
		if (delta < 0) decrease = 1;
		if (CanAdjustStatStageBit9((struct StatStageStruct02087a48*)c->currentStats_, (unsigned char)decrease)) {
			stage = SetStatStageBit9((struct StatStageStruct02087a9c*)c->currentStats_, (signed char)delta);
			UpdateCombatantCharm((int)obj->field0x10, id);
			applied = 1;
		}
	}
	unsigned short sel = 0;
	if (applied) {
		if (range->stageDelta > 0 && stage == 2) sel = 0xf7;
	} else {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->field0xc, &sel);
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021e0380* fl = (struct Flag_021e0380*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
