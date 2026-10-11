#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" void func_ov024_021ea85c(void* obj, int id, int a2);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8ca0;
void* AddEntryToListAndIncCount_021e8ca0(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Obj_021e3cec { char pad0[0x10]; void* field0x10; };

// USA: func_ov024_021e3cec
extern "C" ARM unsigned long long func_ov024_021e3cec(struct Obj_021e3cec* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	func_ov024_021ea85c(obj, id, 1);
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	func_ov000_02159eac(obj->field0x10, &local, 0x28);
	void* entry = AddEntryToListAndIncCount_021e8ca0((struct Obj_021e8ca0*)obj, 0);
	if (entry) {
		func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, 0);
	}
	return 0;
}
