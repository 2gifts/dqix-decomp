#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct FlagObj_021da998;
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(struct FlagObj_021da998* obj);
struct FlagObj_021dd260;
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(struct FlagObj_021dd260* obj);
void DecrementCounter0x24UpdateFlag0x14(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8ca0;
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Obj_021e373c { char pad0[0x10]; void* field0x10; };

// JPN: func_ov024_021e3fd4
// USA: func_ov024_021e373c
extern "C" ARM unsigned long long func_ov024_021e373c(struct Obj_021e373c* obj, int unused, int id, int unused2, int turns) {
	if (turns <= 0) return 0;
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	if (!_Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((struct FlagObj_021da998*)c) && !_Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260((struct FlagObj_021dd260*)c)) return 0;
	DecrementCounter0x24UpdateFlag0x14(c->currentStats_);
	int msg = 0;
	int counter = ((unsigned char*)c->currentStats_)[0x24];
	switch (counter) {
	case 0: msg = 0x17f; break;
	case 1: msg = 0x180; break;
	case 2: msg = 0x181; break;
	case 3: msg = 0x259; break;
	}
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	func_ov000_02159eac(obj->field0x10, &local, 0x1d);
	if (counter == 3) {
		func_ov000_02159eac(obj->field0x10, &local, 8);
	}
	void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((struct Obj_021e8ca0*)obj, msg);
	if (entry) {
		func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, 0);
	}
	return local.v;
}
