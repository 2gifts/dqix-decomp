#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021eb08c(void* obj, int mode, int id, int a3);
extern "C" void func_ov000_0215a908(void* a0, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Flag_021e0b48 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021e0b48 { char pad0[0xc]; void* field0xc; void* field0x10; };

// USA: func_ov024_021e0b48
ARM void* AddBuffEntryToTable_021e0b48(struct Obj_021e0b48* obj, int mode, int id) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	if (func_ov024_021eb08c(obj, mode, id, 0x11) != 0) {
		func_ov000_0215a908(obj->field0x10, id);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	struct Flag_021e0b48* fl = (struct Flag_021e0b48*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
