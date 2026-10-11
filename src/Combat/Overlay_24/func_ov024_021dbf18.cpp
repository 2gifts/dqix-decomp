#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct PackedPair_021dbf18 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Flag_021dbf18 { unsigned char pad : 7; unsigned char flag : 1; };
struct Ctx_021dbf18 { char pad0[0x1c]; struct Flag_021dbf18 flags; };
struct Obj_021dbf18 { char pad0[0xc]; struct Ctx_021dbf18* ctx; void* field0x10; int field0x14; };
struct Range_021dbf18 { char pad[0x20]; struct PackedPair_021dbf18 f20; struct PackedPair_021dbf18 f24; };
struct Stats_021dbf18 { char pad[0x3b]; unsigned char bit0 : 1; unsigned char rest : 7; };

extern "C" unsigned long long func_ov024_021e4b14(struct Obj_021dbf18* obj, int a1, int id, struct Range_021dbf18* range, int mode);
int CheckFlag0x14Bit0x10Set(unsigned char* obj);
void ClearBattleFlag0x14Bit4(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" int func_ov000_02159f18(void* a0, unsigned long long mask, int kind);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long e, int g);

// JPN: func_ov024_021dc7c4
// USA: func_ov024_021dbf18
extern "C" ARM void* func_ov024_021dbf18(struct Obj_021dbf18* obj, int a1, int id, struct Range_021dbf18* range, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int msg = 0;
	int counted = 0;
	unsigned long long mask = 0;
	if (flagArg) {
		mask = func_ov024_021e4b14(obj, a1, id, range, 1);
		if (CheckFlag0x14Bit0x10Set((unsigned char*)c->currentStats_)) {
			msg = 0x40;
			ClearBattleFlag0x14Bit4(c->currentStats_);
			if (mask == 0) {
				func_ov000_02159eac(obj->field0x10, &mask, 0x10);
			}
			((struct Stats_021dbf18*)c->currentStats_)->bit0 = 1;
			counted = 1;
			obj->field0x14++;
		}
	}
	if (func_ov000_02159f18(obj->field0x10, mask, 0x19)) {
		if (!counted) {
			obj->field0x14++;
			counted = 1;
		}
		msg = 0x173;
	}
	if (!counted) {
		msg = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, msg);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, mask, obj->ctx->flags.flag != 0);
	return entry;
}
