#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

int CheckField0x14FlagsClear(unsigned char* obj);
struct Ctx_021e9320;
extern "C" int _Z25SelectResultCode_021e9320P12Ctx_021e9320ii(struct Ctx_021e9320* ctx, int id, int mode);
extern "C" int _Z26IsFlagAllowedMask_021eb4b0iii(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
void ResetStateFields0x18(unsigned char* obj);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Flag_021dd828 { unsigned char pad : 7; unsigned char flag : 1; };
struct Stats_021dd828 { char pad[0x14]; int flags; };
struct Obj_021dd828 { char pad0[0xc]; void* field0xc; void* field0x10; int field0x14; char pad18[0x75 - 0x18]; unsigned char field0x75; };

// JPN: func_ov024_021de0d4
// USA: func_ov024_021dd828
extern "C" ARM void* func_ov024_021dd828(struct Obj_021dd828* obj, int unused, int id, int unused1, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int active = 0;
	if (CheckField0x14FlagsClear((unsigned char*)c->currentStats_) && flagArg) {
		active = 1;
	} else {
		obj->field0x75 = 0;
	}
	unsigned short sel = _Z25SelectResultCode_021e9320P12Ctx_021e9320ii((struct Ctx_021e9320*)obj, id, active);
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (active) {
		if (_Z26IsFlagAllowedMask_021eb4b0iii((int)obj, ((struct Stats_021dd828*)c->currentStats_)->flags, 0x20)) {
			func_ov000_02159eac(obj->field0x10, &local, 0x2b);
		}
		ResetStateFields0x18((unsigned char*)c->currentStats_);
		func_ov000_02159eac(obj->field0x10, &local, 0x17);
		obj->field0x14++;
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->field0xc, &sel);
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021dd828* fl = (struct Flag_021dd828*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, fl->flag != 0);
	return entry;
}
