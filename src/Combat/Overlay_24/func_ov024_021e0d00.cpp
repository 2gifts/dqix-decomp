#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02088f68;
GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
void* GetActiveCombatWork(void);
extern "C" void func_ov000_02161e30(void* work, int id, int msg, int a3);
extern "C" void* func_ov000_0215e958(void* a0);
void ZeroWorkBlock0x20(void* obj);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void _Z15InitObj02088f68P11Obj02088f68(struct Obj02088f68* obj);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Obj_021e0d00 { char pad0[0xc]; void* field0xc; void* field0x10; };

struct Action_021e0d00 {
	char pad0[4];
	unsigned int skillId : 12;
	unsigned int : 20;
	char pad8[0x24 - 0x8];
	unsigned int resultMsg : 10;
	unsigned int : 22;
};

struct Combatant_021e0d00 {
	GameObject base;
	char pad13c[0x188 - 0x13c];
	unsigned short field0x188;
	unsigned short field0x18a;
};

struct Entry_021e0d00 {
	char pad0[0xe];
	unsigned short field0xe;
	unsigned short field0x10;
	unsigned short field0x12;
	unsigned short field0x14;
	char pad16[0x20 - 0x16];
	int field0x20;
};

// USA: func_ov024_021e0d00
extern "C" ARM void* func_ov024_021e0d00(struct Obj_021e0d00* obj, int userId, int id, struct Action_021e0d00* action) {
	struct Combatant_021e0d00* c = (struct Combatant_021e0d00*)GetCombatantWithFlag0x400ByID((int)obj->field0x10, id);
	if (!c) return 0;
	if (userId == id) {
		int msg = -1;
		if (action->skillId == 0x153) msg = 0xb3;
		if (action->skillId == 0x31a) msg = 0x4b;
		func_ov000_02161e30(GetActiveCombatWork(), id, msg, 1);
		struct Entry_021e0d00* entry = (struct Entry_021e0d00*)func_ov000_0215e958(obj->field0x10);
		if (!entry) return 0;
		ZeroWorkBlock0x20(entry);
		entry->field0x20 = 0;
		entry->field0xe = c->field0x188;
		entry->field0x10 = c->field0x18a;
		entry->field0x12 = c->field0x188;
		entry->field0x14 = c->field0x18a;
		_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, (unsigned short)action->resultMsg);
		return entry;
	}
	c->base.currentStats_->primaryStats.currHP = 0;
	_Z15InitObj02088f68P11Obj02088f68((struct Obj02088f68*)c->base.currentStats_);
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
	return entry;
}
