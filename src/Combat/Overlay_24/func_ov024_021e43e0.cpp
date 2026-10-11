#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Obj_021e43e0 { char pad0[0x10]; void* field0x10; };
struct Action_021e43e0 {
	char pad0[0x14];
	unsigned int monsterRate : 7;
	unsigned int partyRate : 7;
	unsigned int rest14 : 18;
	char pad18[0x32 - 0x18];
	short code;
};
struct Stats_021e43e0 {
	char pad0[0x14];
	int flags;
	char pad18[0x22 - 0x18];
	unsigned short low6 : 6;
	unsigned short code : 3;
	unsigned short rest : 7;
	char pad24[0x46 - 0x24];
	unsigned char resistRate;
};

extern "C" int _Z31CheckField0x14Bit0Clear02088840Ph(unsigned char* obj);
extern "C" int func_ov024_021e9198(struct Obj_021e43e0* ctx, int id, short code, int mode);
extern "C" int _Z26IsFlagAllowedMask_021eb4b0iii(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
void SetFlag0x40AndBytes(unsigned char* obj);
struct Obj_021e8ca0;
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

static inline int IsPartyMember(int id) {
	return id >= 0 && id <= 3;
}

// USA: func_ov024_021e43e0
extern "C" ARM unsigned long long func_ov024_021e43e0(struct Obj_021e43e0* obj, int attackerId, int id, struct Action_021e43e0* action, int count) {
	if (count <= 0) return 0;
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int roll = NextRandomMax((struct Random*)obj->field0x10, 100);
	float base;
	if (IsPartyMember(attackerId)) {
		base = action->partyRate;
	} else {
		base = action->monsterRate;
	}
	struct Stats_021e43e0* stats = (struct Stats_021e43e0*)c->currentStats_;
	float chance = base * (stats->resistRate / 100.0f);
	int msg = 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	int code = action->code;
	if (_Z31CheckField0x14Bit0Clear02088840Ph((unsigned char*)c->currentStats_) && roll < chance) {
		msg = func_ov024_021e9198(obj, id, code, 1);
		if (!msg) msg = 0xf5;
		if (_Z26IsFlagAllowedMask_021eb4b0iii((int)obj, ((struct Stats_021e43e0*)c->currentStats_)->flags, 0x40)) {
			func_ov000_02159eac(obj->field0x10, &local, 0x2b);
		}
		SetFlag0x40AndBytes((unsigned char*)c->currentStats_);
		((struct Stats_021e43e0*)c->currentStats_)->code = (unsigned char)code;
	}
	void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((struct Obj_021e8ca0*)obj, msg);
	if (entry) {
		func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
	}
	return 0;
}
