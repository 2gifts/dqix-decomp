#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct FlagObj_021da998;
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(struct FlagObj_021da998* obj);
struct FlagObj_021dd260;
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(struct FlagObj_021dd260* obj);

void ClearFlag0x14Bit0x800000AndByte0x24(void* obj);
void ClearFlag0x1000000AndByte0x24(void* obj);
void ClearFlag0x200AndBytes(unsigned char* obj);
void ClearFlag0x8000000AndBytes(void* obj);
void ClearFlag0x10000000AndBytes(void* obj);
void ClearFlag0x20000000AndBytes0x64And0x87(unsigned char* obj);
void ClearFlag0x100000(unsigned char* obj);
void ClearFlag0x400000AndBytes(unsigned char* obj);
void ClearFlag0x4000000AndBytes(unsigned char* obj);
void ClearFlag0x40000000AndBytes(unsigned char* obj);
void ClearFlag0x100AndBytes(unsigned char* obj);
void ClearFlag0x200000(unsigned char* obj);
extern "C" void _Z35ClearFlag0x80000000AndBytes02088bd4Ph(unsigned char* obj);
struct Obj02088674;
void ResetFlag0x80AndState(struct Obj02088674* obj);
void ClearFlag0x8AndBytes(unsigned char* obj);
void ClearFlag0x10AndBytes(unsigned char* obj);
void ClearFlag0x2AndBytes(unsigned char* obj);
void ClearFlag0x4AndBytes(unsigned char* obj);
void ClearFlag0x200ClearByte0x78(unsigned char* obj);
void ClearFlag0x400AndBytes79And9c(unsigned char* obj);
void ClearFlag0x800AndBytes7cAnd9f(unsigned char* obj);
void ClearFlag0x100AndBytes7dA0(unsigned char* obj);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087838Pv(void* obj);
extern "C" void _Z35ClearBattleFlags0x14And0x580208792cPv(void* obj);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087a20Pv(void* obj);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087b14Pv(void* obj);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087c08Pv(void* obj);
void ClearBattleFlags0x14And0x58(void* obj);
void ClearFlagsAndBytes(void* obj);
void ClearFlags0x14And0x58AndBytes(unsigned char* obj);
void ClearBattleFlags0x18And0x58(void* obj);
void ClearFlags0x14And0x58(void* obj);

void ApplyCombatantBuffs(int unused, int combatantId);

struct Obj_021e8cfc;
extern "C" void* func_ov024_021e8cfc(struct Obj_021e8cfc* obj, void* c, int kind, int notifyExtra);

struct Obj_021e8ca0;
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(struct Obj_021e8ca0* obj, int id);

extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Obj_021ea85c { char pad0[0x10]; void* field0x10; };

// USA: func_ov024_021ea85c
extern "C" ARM void* func_ov024_021ea85c(struct Obj_021ea85c* obj, int id, int flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int flagA = _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((struct FlagObj_021da998*)c);
	int flagB = _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260((struct FlagObj_021dd260*)c);
	ClearFlag0x14Bit0x800000AndByte0x24(c->currentStats_);
	ClearFlag0x1000000AndByte0x24(c->currentStats_);
	ClearFlag0x200AndBytes((unsigned char*)c->currentStats_);
	ClearFlag0x8000000AndBytes(c->currentStats_);
	ClearFlag0x10000000AndBytes(c->currentStats_);
	ClearFlag0x20000000AndBytes0x64And0x87((unsigned char*)c->currentStats_);
	ClearFlag0x100000((unsigned char*)c->currentStats_);
	ClearFlag0x400000AndBytes((unsigned char*)c->currentStats_);
	ClearFlag0x4000000AndBytes((unsigned char*)c->currentStats_);
	ClearFlag0x40000000AndBytes((unsigned char*)c->currentStats_);
	ClearFlag0x100AndBytes((unsigned char*)c->currentStats_);
	ClearFlag0x4000000AndBytes((unsigned char*)c->currentStats_);
	ClearFlag0x200000((unsigned char*)c->currentStats_);
	_Z35ClearFlag0x80000000AndBytes02088bd4Ph((unsigned char*)c->currentStats_);
	ResetFlag0x80AndState((struct Obj02088674*)c->currentStats_);
	ClearFlag0x8AndBytes((unsigned char*)c->currentStats_);
	ClearFlag0x10AndBytes((unsigned char*)c->currentStats_);
	ClearFlag0x2AndBytes((unsigned char*)c->currentStats_);
	ClearFlag0x4AndBytes((unsigned char*)c->currentStats_);
	ClearFlag0x200ClearByte0x78((unsigned char*)c->currentStats_);
	ClearFlag0x400AndBytes79And9c((unsigned char*)c->currentStats_);
	ClearFlag0x800AndBytes7cAnd9f((unsigned char*)c->currentStats_);
	ClearFlag0x100AndBytes7dA0((unsigned char*)c->currentStats_);
	_Z35ClearBattleFlags0x14And0x5802087838Pv(c->currentStats_);
	_Z35ClearBattleFlags0x14And0x580208792cPv(c->currentStats_);
	_Z35ClearBattleFlags0x14And0x5802087a20Pv(c->currentStats_);
	_Z35ClearBattleFlags0x14And0x5802087b14Pv(c->currentStats_);
	_Z35ClearBattleFlags0x14And0x5802087c08Pv(c->currentStats_);
	ClearBattleFlags0x14And0x58(c->currentStats_);
	ClearFlagsAndBytes(c->currentStats_);
	ClearFlags0x14And0x58AndBytes((unsigned char*)c->currentStats_);
	ClearBattleFlags0x18And0x58(c->currentStats_);
	ClearFlags0x14And0x58(c->currentStats_);
	ApplyCombatantBuffs((int)obj->field0x10, id);
	void* result = 0;
	if (flagA) {
		result = func_ov024_021e8cfc((struct Obj_021e8cfc*)obj, c, 0, flagArg);
	} else if (flagB && !_Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260((struct FlagObj_021dd260*)c)) {
		result = func_ov024_021e8cfc((struct Obj_021e8cfc*)obj, c, 8, flagArg);
	}
	if (flagArg != 0 && result == 0) {
		void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((struct Obj_021e8ca0*)obj, 0xf1);
		result = entry;
		func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
	}
	return result;
}
