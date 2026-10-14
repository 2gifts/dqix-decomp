#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);
void SetBool0x17fClear0x180_020488ac(unsigned char* obj, int value);
extern "C" int func_ov024_021eb08c(void* obj, int mode, int id, int a3);
extern "C" void func_ov000_0215a908(void* a0, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct FlagInner_021e05e4 { char unk[0x18]; int flags; };
struct FlagObj_021e05e4 { char unk[0x138]; struct FlagInner_021e05e4* inner; };
int IsFlagBit12Field18Set_021e05e4(struct FlagObj_021e05e4* obj);

struct Flag_021e04e0 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021e04e0 { char pad0[0xc]; void* field0xc; void* field0x10; int field0x14; };

// USA: func_ov024_021e04e0  (semantic: AddBuffEntryToTable_021e04e0)
extern "C" ARM void* func_ov024_021e04e0(struct Obj_021e04e0* obj, short value, int id) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8((int)obj->field0x10, id);
	if (!c) return 0;
	if (IsFlagBit12Field18Set_021e05e4((struct FlagObj_021e05e4*)c)) {
		*(short*)((char*)c->currentStats_ + 0x2e) = value;
		SetBool0x17fClear0x180_020488ac((unsigned char*)c, 1);
		func_ov000_0215a908(obj->field0x10, id);
		*(unsigned char*)((char*)c + 0x182) = 1;
		obj->field0x14++;
	} else if (func_ov024_021eb08c(obj, value, id, 0x12) != 0) {
		func_ov000_0215a908(obj->field0x10, id);
		*(unsigned char*)((char*)c + 0x182) = 1;
		obj->field0x14++;
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	struct Flag_021e04e0* fl = (struct Flag_021e04e0*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
