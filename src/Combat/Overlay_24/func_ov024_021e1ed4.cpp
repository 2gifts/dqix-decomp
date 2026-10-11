#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087860;
struct StatStageStruct02087e18;
struct Obj02087e6c;
int CanAdjustStatStageBit3(StatStageStruct02087860* p, int decrease);
extern "C" int func_020878b4(void* stats, int delta);
int CanAdjustStatStageBit21(StatStageStruct02087e18* p, int decrease);
int ClampAndUpdateField0x58(Obj02087e6c* obj, int delta);
int CanAdjustField0x58(void* stats, int dir);
extern "C" int func_020877c0(void* stats, int delta);
void UpdateCombatantDefense(int random, int combatantId);
void UpdateCombatantAttack(int random, int combatantId);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Params_021e1ed4 {
	char pad[0x24];
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Flag_021e1ed4 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021e1ed4 { char pad0[0xc]; void* field0xc; void* field0x10; };

extern "C" int func_ov024_021e95d4(struct Obj_021e1ed4* ctx, int id, struct Params_021e1ed4* params, int mode, signed char adjustment, unsigned char changed, unsigned char flag);
extern "C" int func_ov024_021e94c4(struct Obj_021e1ed4* ctx, int id, struct Params_021e1ed4* params, int mode, signed char value, unsigned char useValue, unsigned char forceDefault);

// JPN: func_ov024_021e276c
// USA: func_ov024_021e1ed4
extern "C" ARM void* func_ov024_021e1ed4(struct Obj_021e1ed4* obj, int unused, int id, struct Params_021e1ed4* params) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	int changed = 0;
	if (CanAdjustStatStageBit3((StatStageStruct02087860*)c->currentStats_, 0)) {
		changed = 1;
		int delta = func_020878b4(c->currentStats_, 1);
		UpdateCombatantDefense((int)obj->field0x10, id);
		_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, func_ov024_021e95d4(obj, id, params, 0, delta, 1, 1));
	}
	if (CanAdjustStatStageBit21((StatStageStruct02087e18*)c->currentStats_, 0)) {
		changed = 1;
		int result = ClampAndUpdateField0x58((Obj02087e6c*)c->currentStats_, 1);
		int msg;
		switch (result) {
			case 2: msg = 0x1b0; break;
			case 0: msg = 0x1af; break;
			default: msg = 0x1b1; break;
		}
		_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, msg);
	}
	if (CanAdjustField0x58(c->currentStats_, 0)) {
		changed = 1;
		int delta = func_020877c0(c->currentStats_, 1);
		UpdateCombatantAttack((int)obj->field0x10, id);
		_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, func_ov024_021e94c4(obj, id, params, 0, delta, 1, 1));
	}
	if (!changed) {
		_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, (unsigned short)params->b);
	}
	struct Flag_021e1ed4* fl = (struct Flag_021e1ed4*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
