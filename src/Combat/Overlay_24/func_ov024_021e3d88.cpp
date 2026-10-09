#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct StatStageStruct02087d24;
int CanAdjustStatStageBit18(struct StatStageStruct02087d24* p, int decrease);
struct StatStageStruct02087d78;
int SetStatStageBit18(struct StatStageStruct02087d78* p, int delta);
struct Obj_021e8ca0;
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Flag_021e3d88 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021e3d88 { char pad0[0xc]; void* field0xc; struct Random* field0x10; };
struct Move_021e3d88 { char pad[0x32]; short stageDelta; };
struct Stats_021e3d88 { char pad[0x52]; unsigned char lowerChance; };

// USA: func_ov024_021e3d88
extern "C" ARM unsigned long long func_ov024_021e3d88(struct Obj_021e3d88* obj, int unused, int id, struct Move_021e3d88* move, int count) {
	if (count <= 0) return 0;
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int roll = NextRandomMax(obj->field0x10, 100);
	int delta = move->stageDelta;
	if (delta < -2) delta = -2;
	if (delta > 2) delta = 2;
	int decrease = 0;
	if (delta < 0) {
		unsigned char chance = ((struct Stats_021e3d88*)c->currentStats_)->lowerChance;
		if (chance == 0) return 0;
		struct Flag_021e3d88* fl = (struct Flag_021e3d88*)((char*)obj->field0xc + 0x1c);
		if (!fl->flag) {
			float rate = chance;
			if (roll >= chance) return 0;
		}
		decrease = 1;
	}
	int applied = 0;
	int result = 0;
	if (CanAdjustStatStageBit18((struct StatStageStruct02087d24*)c->currentStats_, (unsigned char)decrease)) {
		result = SetStatStageBit18((struct StatStageStruct02087d78*)c->currentStats_, (signed char)delta);
		applied = 1;
	}
	if (applied) {
		int msg;
		if (delta > 0) {
			switch (result) {
			case 2: msg = 0xab; break;
			case 0: msg = 0xae; break;
			default: msg = 0xac; break;
			}
		} else {
			switch (result) {
			case -2: msg = 0xaf; break;
			case 0: msg = 0xae; break;
			default: msg = 0xad; break;
			}
		}
		void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((struct Obj_021e8ca0*)obj, msg);
		if (entry) {
			func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
		}
	}
	return 0;
}
