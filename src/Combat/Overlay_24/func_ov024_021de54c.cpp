#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02084a64(unsigned char* obj, int id);
extern "C" void func_02083e28(unsigned char* p, int v);
extern "C" void _Z24CopyPackedFields02089494PcS_S_(char* dst, char* buf, char* src);
void ApplyCombatantBuffs(int world, int id);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021de54c {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Settings_021de54c { char pad0[0x1c]; unsigned char pad1c : 7; unsigned char flag : 1; };
struct Obj_021de54c { char pad0[0xc]; struct Settings_021de54c* field0xc; void* field0x10; int count; };
struct Params_021de54c {
	char pad0[4];
	unsigned int itemId : 12;
	unsigned int pad4hi : 20;
	char pad8[0x18];
	struct PackedPair_021de54c f20;
	struct PackedPair_021de54c f24;
};
struct Combatant_021de54c {
	char pad0[0x130];
	char* field0x130;
	char* baseStats;
	char* currentStats;
#if defined(jpn)
	char pad13c[8];
#else
	char pad13c[0x14];
#endif

	unsigned char* field0x150;
};

// JPN: func_ov024_021dede4
// USA: func_ov024_021de54c
extern "C" ARM void* func_ov024_021de54c(struct Obj_021de54c* obj, int unused, int id, struct Params_021de54c* params) {
	struct Combatant_021de54c* c = (struct Combatant_021de54c*)GetCombatantWithFlag0x100(GameState::GetInstance(), id);
	if (!c) return 0;
	unsigned short sel;
	if (func_02084a64(c->field0x150, params->itemId) > 0) {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, params->f20.c, params->f24.a);
		func_02083e28(c->field0x150, 0);
		_Z24CopyPackedFields02089494PcS_S_(c->currentStats, c->field0x130, c->baseStats);
		ApplyCombatantBuffs((int)obj->field0x10, id);
		obj->count++;
	} else {
		sel = _Z31SelectByIndexRange0to3_021da644iii(id, params->f24.b, params->f24.c);
	}
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, obj->field0xc->flag != 0);
	return entry;
}
