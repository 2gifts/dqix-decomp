#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

int CheckField0x14Bit0Clear02088b00(unsigned char* obj);
void SetFlag0x400000AndBytes(unsigned char* obj);
unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021deff8 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Flag_021deff8 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021deff8 { char pad0[0xc]; void* field0xc; void* field0x10; };
struct Range_021deff8 { char pad[0x20]; struct PackedPair_021deff8 f20; struct PackedPair_021deff8 f24; };

// USA: func_ov024_021deff8
ARM void* AddBuffEntryToTable_021deff8(struct Obj_021deff8* obj, int unused, int id, struct Range_021deff8* range, int unused2, int unused3, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int active = CheckField0x14Bit0Clear02088b00((unsigned char*)c->currentStats_);
	unsigned short sel;
	if (active != 0 && flagArg != 0) {
		SetFlag0x400000AndBytes((unsigned char*)c->currentStats_);
		sel = SelectByIndexRange0to3_021da644(id, range->f20.c, range->f24.a);
	} else {
		sel = SelectByIndexRange0to3_021da644(id, range->f24.b, range->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	AddEntryAndIncrementCount0215a88c(obj->field0x10, entry, sel);
	struct Flag_021deff8* fl = (struct Flag_021deff8*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
