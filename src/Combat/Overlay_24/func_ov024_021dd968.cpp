#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087d24;
struct StatStageStruct02087d78;
int CanAdjustStatStageBit18(struct StatStageStruct02087d24* p, int decrease);
int SetStatStageBit18(struct StatStageStruct02087d78* p, int delta);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Flag_021dd968 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021dd968 { char pad0[0xc]; void* field0xc; void* field0x10; char pad14[0x61]; unsigned char field0x75; };
struct Range_021dd968 { char pad[0x30]; short stageDelta; };

extern "C" int func_ov024_021e97f4(struct Obj_021dd968* ctx, int id, struct Range_021dd968* parameters, unsigned char decrease, signed char value, unsigned char useValue, unsigned char special);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);

// USA: func_ov024_021dd968
extern "C" ARM void* func_ov024_021dd968(struct Obj_021dd968* obj, int unused, int id, struct Range_021dd968* range, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	unsigned char applied = 0;
	int result = 0;
	int decrease = 0;
	int delta = range->stageDelta;
	if (delta < -2) delta = -2;
	if (delta > 2) delta = 2;
	if (delta < 0) decrease = 1;
	if (CanAdjustStatStageBit18((struct StatStageStruct02087d24*)c->currentStats_, (unsigned char)decrease) && flagArg != 0) {
		result = SetStatStageBit18((struct StatStageStruct02087d78*)c->currentStats_, (signed char)delta);
		applied = 1;
	} else {
		obj->field0x75 = 0;
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	unsigned short sel = func_ov024_021e97f4(obj, id, range, decrease, result, applied, flagArg);
	func_ov024_021e8bf0(obj, obj->field0xc, &sel);
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021dd968* fl = (struct Flag_021dd968*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
