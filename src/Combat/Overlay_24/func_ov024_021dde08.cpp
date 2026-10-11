#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087f24;
struct StatStageStruct02087f78;
int CanAdjustStatStageBit27(struct StatStageStruct02087f24* p, int decrease);
int SetStatStageBit27(struct StatStageStruct02087f78* p, int delta);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021dde08 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Flag_021dde08 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021dde08 { char pad0[0xc]; void* field0xc; void* field0x10; };
struct Range_021dde08 {
    char pad[0x20];
    struct PackedPair_021dde08 f20;
    struct PackedPair_021dde08 f24;
    char pad28[0x30 - 0x28];
    short stage;
};

// JPN: func_ov024_021de6b4
// USA: func_ov024_021dde08
extern "C" ARM void* func_ov024_021dde08(struct Obj_021dde08* obj, int unused, int id, struct Range_021dde08* range, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int applied = 0;
	if (flagArg != 0) {
		int stage = range->stage;
		if (stage < -2) stage = -2;
		if (stage > 2) stage = 2;
		int decrease = 0;
		if (stage < 0) decrease = 1;
		if (CanAdjustStatStageBit27((struct StatStageStruct02087f24*)c->currentStats_, (unsigned char)decrease)) {
			SetStatStageBit27((struct StatStageStruct02087f78*)c->currentStats_, (signed char)stage);
			applied = 1;
		}
	}
	unsigned short sel = 0;
	if (applied != 0) {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f20.c, range->f24.a);
	} else {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->field0xc, &sel);
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021dde08* fl = (struct Flag_021dde08*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
