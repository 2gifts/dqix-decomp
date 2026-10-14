#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

int CheckField0x14FlagsClear0208824c(unsigned char* obj);
void ResetStateFields0208826c(unsigned char* obj);
struct Ctx_021e9464;
int SelectResultCode_021e9464(struct Ctx_021e9464* ctx, int id, int mode);
struct FlagObj_021da998;
int IsFlagBit8388608Set_021da998(struct FlagObj_021da998* obj);
int IsFlagAllowedMask_021eb4b0(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8cfc;
extern "C" void* func_ov024_021e8cfc(struct Obj_021e8cfc* obj, void* c, int kind, int notifyExtra);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Flag_021ddc80 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021ddc80 { char pad0[0xc]; void* field0xc; void* field0x10; int field0x14; };
struct Move_021ddc80 { int w0; unsigned int id : 12; unsigned int pad4 : 20; };
struct Stats_021ddc80 { char pad[0x14]; int flags; };

// USA: func_ov024_021ddc80
extern "C" ARM void* func_ov024_021ddc80(struct Obj_021ddc80* obj, int unused, int id, struct Move_021ddc80* move, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int mode = 0;
	int clear = CheckField0x14FlagsClear0208824c((unsigned char*)c->currentStats_);
	if (clear != 0 && flagArg != 0) {
		mode = 1;
	}
	unsigned short sel = SelectResultCode_021e9464((struct Ctx_021e9464*)obj, id, mode);
	if (move->id == 0x393) {
		sel = 0;
	}
	int notify = IsFlagBit8388608Set_021da998((struct FlagObj_021da998*)c);
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (mode) {
		if (IsFlagAllowedMask_021eb4b0((int)obj, ((struct Stats_021ddc80*)c->currentStats_)->flags, 8)) {
			func_ov000_02159eac(obj->field0x10, &local, 0x2b);
		}
		ResetStateFields0208826c((unsigned char*)c->currentStats_);
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
		AddEntryAndIncrementCount0215a88c(obj->field0x10, entry, sel);
	}
	struct Flag_021ddc80* fl = (struct Flag_021ddc80*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, fl->flag != 0);
	return entry;
}
