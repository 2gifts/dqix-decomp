#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Obj_021dfe9c { char pad0[0xc]; void* field0xc; void* field0x10; int field0x14; };
struct Flag_021dfe9c { unsigned char pad : 7; unsigned char flag : 1; };

// USA: func_ov024_021dfe9c  (semantic: AddBuffEntryToTable_021dfe9c)
extern "C" ARM void* func_ov024_021dfe9c(struct Obj_021dfe9c* obj, int unused, int id) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8((int)obj->field0x10, id);
	if (!c) return 0;
	void* extra = *(void**)((char*)c + 0x148);
	if (!extra) return 0;
	*(unsigned char*)((char*)c + 0x17e) = 1;
	obj->field0x14 += 1;
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	struct Flag_021dfe9c* fl = (struct Flag_021dfe9c*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
