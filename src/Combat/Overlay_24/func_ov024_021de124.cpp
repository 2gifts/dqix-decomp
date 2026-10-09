#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct FlagObj_021de25c;
extern "C" int _Z22IsFlagBit5Set_021de25cP16FlagObj_021de25c(struct FlagObj_021de25c* obj);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
void ClearFlag0x20AndBytes(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct PackedPair_021de124 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Flag_021de124 { unsigned char pad : 7; unsigned char flag : 1; };
struct Bit3b_021de124 { unsigned char bit0 : 1; unsigned char rest : 7; };
struct Obj_021de124 { char pad0[0xc]; void* field0xc; void* field0x10; int field0x14; };
struct Range_021de124 { char pad[0x20]; struct PackedPair_021de124 f20; struct PackedPair_021de124 f24; };

// USA: func_ov024_021de124
extern "C" ARM void* func_ov024_021de124(struct Obj_021de124* obj, int unused, int id, struct Range_021de124* range, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	unsigned short sel;
	if (_Z22IsFlagBit5Set_021de25cP16FlagObj_021de25c((struct FlagObj_021de25c*)c) && flagArg != 0) {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f20.c, range->f24.a);
		ClearFlag0x20AndBytes((void*)c->currentStats_);
		((struct Bit3b_021de124*)((char*)c->currentStats_ + 0x3b))->bit0 = 1;
		func_ov000_02159eac(obj->field0x10, &local, 0x19);
		obj->field0x14++;
	} else {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021de124* fl = (struct Flag_021de124*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, fl->flag != 0);
	return entry;
}
