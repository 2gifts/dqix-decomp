#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);
int CheckField0x14FiveFlagsClear02088e04(unsigned char* obj);
void SetByte0x7eSetFlag0x1000_02088e48(unsigned char* obj, unsigned char val);
void SetBool0x17fClear0x180_020488ac(unsigned char* obj, int value);
extern "C" void func_ov000_0215a908(void* a0, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Flag_021e1de8 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021e1de8 { char pad0[0xc]; void* field0xc; void* field0x10; };
struct Extra_021e1de8 { char pad[0x28]; unsigned char lo; unsigned char hi; };

// USA: func_ov024_021e1de8
ARM void* AddBuffEntryToTable_021e1de8(struct Obj_021e1de8* obj, short value, int id) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8((int)obj->field0x10, id);
	if (!c) return 0;
	struct Extra_021e1de8* extra = *(struct Extra_021e1de8**)((char*)c + 0x148);
	if (!extra) return 0;
	if (CheckField0x14FiveFlagsClear02088e04((unsigned char*)c->currentStats_)) {
		int rnd = NextRandomBetween((struct Random*)obj->field0x10, extra->lo, extra->hi);
		if (rnd > 0) {
			SetByte0x7eSetFlag0x1000_02088e48((unsigned char*)c->currentStats_, (unsigned char)rnd);
			SetBool0x17fClear0x180_020488ac((unsigned char*)c, 1);
			*(short*)((char*)c->currentStats_ + 0x2e) = value;
			func_ov000_0215a908(obj->field0x10, id);
		}
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	struct Flag_021e1de8* fl = (struct Flag_021e1de8*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
