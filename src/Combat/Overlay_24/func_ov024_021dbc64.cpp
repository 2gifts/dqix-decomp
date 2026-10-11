#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2(struct S88514* obj);
struct Combatant_2088644;
void ClearFlag0x2AndKind(struct Combatant_2088644* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct PackedPair_021dbc64 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Flag_021dbc64 { unsigned char pad : 7; unsigned char flag : 1; };
struct Ctx_021dbc64 { char pad0[0x1c]; struct Flag_021dbc64 flags; };
struct Obj_021dbc64 {
	char pad0[0xc];
	struct Ctx_021dbc64* field0xc;
	void* field0x10;
	int count0x14;
	char pad18[0x75 - 0x18];
	unsigned char field0x75;
};
struct Range_021dbc64 { char pad[0x24]; struct PackedPair_021dbc64 f24; };

// USA: func_ov024_021dbc64
extern "C" ARM void* func_ov024_021dbc64(struct Obj_021dbc64* obj, int unused, int id, struct Range_021dbc64* range, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	int sel;
	if ((CheckFlag0x2AndKind1((struct Combatant_20885b4*)c->currentStats_) || CheckFlag0x2AndState2((struct S88514*)c->currentStats_)) && flagArg != 0) {
		sel = 0x54;
		ClearFlag0x2AndKind((struct Combatant_2088644*)c->currentStats_);
		func_ov000_02159eac(obj->field0x10, &local, 0x11);
		obj->count0x14++;
	} else {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
		obj->field0x75 = 0;
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, obj->field0xc->flags.flag != 0);
	return entry;
}
