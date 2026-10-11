#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int _Z32CheckField0x14FlagsClear0208824cPh(unsigned char* obj);
extern "C" void _Z24ResetStateFields0208826cPh(unsigned char* obj);
struct Ctx_021e9464;
extern "C" int _Z25SelectResultCode_021e9464P12Ctx_021e9464ii(struct Ctx_021e9464* ctx, int id, int mode);
struct FlagObj_021da998;
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(struct FlagObj_021da998* obj);
extern "C" int _Z26IsFlagAllowedMask_021eb4b0iii(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8cfc;
extern "C" void* func_ov024_021e8cfc(struct Obj_021e8cfc* obj, void* c, int kind, int notifyExtra);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Flag_021ddc80 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021ddc80 { char pad0[0xc]; void* field0xc; void* field0x10; int field0x14; };
struct Move_021ddc80 { int w0; unsigned int id : 12; unsigned int pad4 : 20; };
struct Stats_021ddc80 { char pad[0x14]; int flags; };

// JPN: func_ov024_021de52c
// USA: func_ov024_021ddc80
extern "C" ARM void* func_ov024_021ddc80(struct Obj_021ddc80* obj, int unused, int id, struct Move_021ddc80* move, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int mode = 0;
	int clear = _Z32CheckField0x14FlagsClear0208824cPh((unsigned char*)c->currentStats_);
	if (clear != 0 && flagArg != 0) {
		mode = 1;
	}
	unsigned short sel = _Z25SelectResultCode_021e9464P12Ctx_021e9464ii((struct Ctx_021e9464*)obj, id, mode);
	if (move->id == 0x393) {
		sel = 0;
	}
	int notify = _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((struct FlagObj_021da998*)c);
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (mode) {
		if (_Z26IsFlagAllowedMask_021eb4b0iii((int)obj, ((struct Stats_021ddc80*)c->currentStats_)->flags, 8)) {
			func_ov000_02159eac(obj->field0x10, &local, 0x2b);
		}
		_Z24ResetStateFields0208826cPh((unsigned char*)c->currentStats_);
		func_ov000_02159eac(obj->field0x10, &local, 0x18);
		obj->field0x14++;
		if (notify) {
			func_ov024_021e8cfc((struct Obj_021e8cfc*)obj, c, 0, 0);
		}
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->field0xc, &sel);
	if (sel != 0) {
		_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	}
	struct Flag_021ddc80* fl = (struct Flag_021ddc80*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, fl->flag != 0);
	return entry;
}
