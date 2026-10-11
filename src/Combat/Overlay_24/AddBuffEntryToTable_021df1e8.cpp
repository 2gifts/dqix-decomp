#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021eae14(void* obj, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Flag_021df1e8 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021df1e8 { char pad0[0xc]; void* field0xc; void* field0x10; int field0x14; };

// USA: func_ov024_021df1e8
ARM void* AddBuffEntryToTable_021df1e8(struct Obj_021df1e8* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	if (func_ov024_021eae14(obj, id) > 0) {
		obj->field0x14 = obj->field0x14 + 1;
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	struct Flag_021df1e8* fl = (struct Flag_021df1e8*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
