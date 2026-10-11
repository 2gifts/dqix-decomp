#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct FlagObj_021da9b0;
int IsFlagBit8Set_021da9b0(struct FlagObj_021da9b0* obj);
void ClearFlag0x14Bit0x8AndBytes(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8ca0;
void* AddEntryToListAndIncCount_021e8ca0(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Obj_021e32f4 { char pad0[0xc]; void* field0xc; void* field0x10; };
struct Bit3b_021e32f4 { unsigned char bit0 : 1; unsigned char rest : 7; };

// USA: func_ov024_021e32f4
ARM unsigned long long AddBuffEntryToTable_021e32f4(struct Obj_021e32f4* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (IsFlagBit8Set_021da9b0((struct FlagObj_021da9b0*)c)) {
		ClearFlag0x14Bit0x8AndBytes((void*)c->currentStats_);
		func_ov000_02159eac(obj->field0x10, &local, 0x1a);
		((struct Bit3b_021e32f4*)((char*)c->currentStats_ + 0x3b))->bit0 = 1;
		void* entry = AddEntryToListAndIncCount_021e8ca0((struct Obj_021e8ca0*)obj, 0x1f9);
		if (entry) {
			func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
