#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2(struct S88514* obj);
struct Combatant_2088644;
void ClearFlag0x2AndKind(struct Combatant_2088644* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
struct Obj_021e8ca0;
void* AddEntryToListAndIncCount_021e8ca0(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Obj_021e324c { char pad0[0xc]; void* field0xc; void* field0x10; };

// USA: func_ov024_021e324c
ARM unsigned long long AddBuffEntryToTable_021e324c(struct Obj_021e324c* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (CheckFlag0x2AndKind1((struct Combatant_20885b4*)c->currentStats_) || CheckFlag0x2AndState2((struct S88514*)c->currentStats_)) {
		ClearFlag0x2AndKind((struct Combatant_2088644*)c->currentStats_);
		func_ov000_02159eac(obj->field0x10, &local, 0x11);
		void* entry = AddEntryToListAndIncCount_021e8ca0((struct Obj_021e8ca0*)obj, 0x54);
		if (entry) {
			func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
		}
	}
	return local.v;
}
