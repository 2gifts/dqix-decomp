#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct FlagObj_021da9b0;
extern "C" int _Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0(struct FlagObj_021da9b0* obj);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
void ClearFlag0x14Bit0x8AndBytes(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct PackedPair_021dd6f0 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Flag_021dd6f0 { unsigned char pad : 7; unsigned char flag : 1; };
struct Bit3b_021dd6f0 { unsigned char bit0 : 1; unsigned char rest : 7; };
struct Obj_021dd6f0 { char pad0[0xc]; void* field0xc; void* field0x10; int field0x14; };
struct Range_021dd6f0 { char pad[0x20]; struct PackedPair_021dd6f0 f20; struct PackedPair_021dd6f0 f24; };

// JPN: func_ov024_021ddf9c
// USA: func_ov024_021dd6f0
extern "C" ARM void* func_ov024_021dd6f0(struct Obj_021dd6f0* obj, int unused, int id, struct Range_021dd6f0* range, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	unsigned short sel;
	if (_Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0((struct FlagObj_021da9b0*)c) && flagArg != 0) {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f20.c, range->f24.a);
		ClearFlag0x14Bit0x8AndBytes((void*)c->currentStats_);
		func_ov000_02159eac(obj->field0x10, &local, 0x1a);
		((struct Bit3b_021dd6f0*)((char*)c->currentStats_ + 0x3b))->bit0 = 1;
		obj->field0x14++;
	} else {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021dd6f0* fl = (struct Flag_021dd6f0*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, fl->flag != 0);
	return entry;
}
