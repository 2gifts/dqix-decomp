#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantByID(int unused, int id);
extern "C" int func_ov024_021eae14(void* obj, int id);
struct Obj_021e8ca0;
void* AddEntryToListAndIncCount_021e8ca0(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Obj_021e40d8 { char pad0[0x10]; void* field0x10; };

// USA: func_ov024_021e40d8
ARM long long AddToTableAfterCheck_021e40d8(struct Obj_021e40d8* obj, int unused, int id) {
	GameObject* combatant = GetCombatantByID((int)obj->field0x10, id);
	if (!combatant) return 0;
	if (func_ov024_021eae14(obj, id) > 0) {
		void* entry = AddEntryToListAndIncCount_021e8ca0((struct Obj_021e8ca0*)obj, 0xcb);
		if (entry) {
			func_ov000_0215cd44(obj->field0x10, entry, combatant, 0, 0, 0, 0);
		}
	}
	return 0;
}
