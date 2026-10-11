#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Combat/Main/BattleList.h"
#include "GameState/GameState.h"

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
void ResetFields14And18KeepFlag0x4(unsigned char* obj, unsigned short val);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" float func_ov024_021db358(GameObject* obj);
extern "C" short _Z20ApplyHPDelta0215a16cPviiPs(void* unused, int id, int delta, short* outApplied);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Flag_021de868 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021de868 { char pad0[0xc]; void* field0xc; void* field0x10; };
struct StatsFlags_021de868 {
	char pad0[0x3a];
	unsigned char byte0x3a;
	unsigned char bit0 : 1;
	unsigned char rest : 7;
};

// USA: func_ov024_021de868
extern "C" ARM void* func_ov024_021de868(struct Obj_021de868* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	short applied = 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	int msg;
	if (IsFlag10088Set((struct S_10088*)c)) {
		ResetFields14And18KeepFlag0x4((unsigned char*)c->currentStats_, c->currentStats_->primaryStats.maxHP);
		func_ov000_02159eac(obj->field0x10, &local, 3);
		((struct StatsFlags_021de868*)c->currentStats_)->bit0 = 1;
		msg = 0x20;
		int inRange = (id >= 0 && id <= 3);
		if (inRange) {
			GameObject* member = GetCombatantWithFlag0x100(GameState::GetInstance(), id);
			if (member) {
				((struct StatsFlags_021de868*)member->currentStats_)->byte0x3a = 1;
			}
		}
	} else if (func_ov024_021db358(c) < 1.0f) {
		_Z20ApplyHPDelta0215a16cPviiPs(obj->field0x10, id, c->currentStats_->primaryStats.maxHP, &applied);
		func_ov000_02159eac(obj->field0x10, &local, 0x25);
		msg = 0x16;
	} else {
		msg = 0x1f;
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, msg);
	struct Flag_021de868* fl = (struct Flag_021de868*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, (short)-applied, local.v, fl->flag != 0);
	return entry;
}
