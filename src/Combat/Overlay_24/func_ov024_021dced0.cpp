#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int _Z31CheckField0x14Bit0Clear02088890Ph(unsigned char* obj);
struct FlagObj_021dd010;
extern "C" int _Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010(struct FlagObj_021dd010* obj);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
void SetFlag0x100AndBytes(unsigned char* obj);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021dced0 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Flag_021dced0 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021dced0 { char pad0[0xc]; void* field0xc; void* field0x10; char pad14[0x75 - 0x14]; unsigned char field0x75; };
struct Range_021dced0 { char pad[0x20]; struct PackedPair_021dced0 f20; struct PackedPair_021dced0 f24; };

// JPN: func_ov024_021dd77c
// USA: func_ov024_021dced0
extern "C" ARM void* func_ov024_021dced0(struct Obj_021dced0* obj, int unused, int id, struct Range_021dced0* range, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	unsigned short sel = 0;
	if (_Z31CheckField0x14Bit0Clear02088890Ph((unsigned char*)c->currentStats_) && flagArg) {
		if (_Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010((struct FlagObj_021dd010*)c)) {
			sel = _Z31SelectByIndexRange0to3_021da644iii(id, 0x19, 0x1a);
		} else {
			sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f20.c, range->f24.a);
		}
		SetFlag0x100AndBytes((unsigned char*)c->currentStats_);
	} else {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
		obj->field0x75 = 0;
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->field0xc, &sel);
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021dced0* fl = (struct Flag_021dced0*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
