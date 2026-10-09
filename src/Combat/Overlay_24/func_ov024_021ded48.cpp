#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02088018;
struct StatStageStruct0208806c;
int CanAdjustStatStageBit24(struct StatStageStruct02088018* p, int decrease);
int SetStatStageBit24(struct StatStageStruct0208806c* p, int delta);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021ded48 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Flag_021ded48 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021ded48 { char pad0[0xc]; void* field0xc; void* field0x10; };
struct Range_021ded48 {
	char pad[0x20];
	struct PackedPair_021ded48 f20;
	struct PackedPair_021ded48 f24;
	char pad28[0x8];
	short stageDelta;
};

// USA: func_ov024_021ded48
extern "C" ARM void* func_ov024_021ded48(struct Obj_021ded48* obj, int unused, int id, struct Range_021ded48* range, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int applied = 0;
	if (flagArg != 0) {
		int stage = range->stageDelta;
		if (stage < -2) stage = -2;
		if (stage > 2) stage = 2;
		int decrease = 0;
		if (stage < 0) decrease = 1;
		if (CanAdjustStatStageBit24((struct StatStageStruct02088018*)c->currentStats_, (unsigned char)decrease)) {
			SetStatStageBit24((struct StatStageStruct0208806c*)c->currentStats_, (signed char)stage);
			applied = 1;
		}
	}
	unsigned short sel;
	if (applied) {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f20.c, range->f24.a);
	} else {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021ded48* fl = (struct Flag_021ded48*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
