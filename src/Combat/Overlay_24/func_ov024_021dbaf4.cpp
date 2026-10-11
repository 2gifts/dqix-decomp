#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

int CheckFlag0x1ClearAndFlag0x1000000Clear(unsigned char* obj);
struct Combatant_20885e0;
int CheckFlags0x1And0x1000000ClearAndKindNot2(struct Combatant_20885e0* obj);
struct Ctx_021e939c;
extern "C" int _Z30SelectMessageByFlags2_021e939cP12Ctx_021e939ciii(struct Ctx_021e939c* ctx, int id, int flag1, int flag2);
extern "C" int _Z26IsFlagAllowedMask_021eb4b0iii(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
void ResetAndSetFlag0x2AndBits(unsigned char* obj);
struct Combatant_2088624;
void SetFlag0x2AndKind1(struct Combatant_2088624* obj);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Flag_021dbaf4 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021dbaf4 { char pad0[0xc]; void* field0xc; void* field0x10; };
struct Action_021dbaf4 { char pad[0x30]; short field30; };
struct Stats_021dbaf4 { char pad[0x14]; int field14; };

// JPN: func_ov024_021dc3a0
// USA: func_ov024_021dbaf4
extern "C" ARM void* func_ov024_021dbaf4(struct Obj_021dbaf4* obj, int unused, int id, struct Action_021dbaf4* action, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int apply = 0;
	int full = apply;
	if (action->field30 > 0) {
		if (CheckFlag0x1ClearAndFlag0x1000000Clear((unsigned char*)c->currentStats_) && flagArg) {
			apply = 1;
			full = apply;
		}
	} else {
		if (CheckFlags0x1And0x1000000ClearAndKindNot2((struct Combatant_20885e0*)c->currentStats_) && flagArg) {
			apply = 1;
		}
	}
	unsigned short sel = _Z30SelectMessageByFlags2_021e939cP12Ctx_021e939ciii((struct Ctx_021e939c*)obj, id, full, apply);
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (apply) {
		if (_Z26IsFlagAllowedMask_021eb4b0iii((int)obj, ((struct Stats_021dbaf4*)c->currentStats_)->field14, 2)) {
			func_ov000_02159eac(obj->field0x10, &local, 0x2b);
		}
		if (full) {
			ResetAndSetFlag0x2AndBits((unsigned char*)c->currentStats_);
		} else {
			SetFlag0x2AndKind1((struct Combatant_2088624*)c->currentStats_);
		}
		func_ov000_02159eac(obj->field0x10, &local, 0xf);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->field0xc, &sel);
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021dbaf4* fl = (struct Flag_021dbaf4*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, fl->flag != 0);
	return entry;
}
