#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct FlagObj_021da998;
int IsFlagBit8388608Set_021da998(struct FlagObj_021da998* obj);
struct FlagObj_021dd260;
int IsFlagBit24Set_021dd260(struct FlagObj_021dd260* obj);

void ClearFlag0x14Bit0x800000AndByte0x24_02088234(void* obj);
void ClearFlag0x1000000AndByte0x24_020881ac(void* obj);
void ClearFlag0x200AndBytes_02088914(unsigned char* obj);
void ClearFlag0x8000000AndBytes_020889b4(void* obj);
void ClearFlag0x10000000AndBytes_02088a04(void* obj);
void ClearFlag0x20000000AndBytes0x64And0x87_02088a54(unsigned char* obj);
void ClearFlag0x100000_02088aa8(unsigned char* obj);
void ClearFlag0x400000AndBytes_02088b34(unsigned char* obj);
void ClearFlag0x4000000AndBytes_02088964(unsigned char* obj);
void ClearFlag0x40000000AndBytes_02088b84(unsigned char* obj);
void ClearFlag0x100AndBytes_020888c4(unsigned char* obj);
void ClearFlag0x200000_02088af0(unsigned char* obj);
void ClearFlag0x80000000AndBytes02088bd4(unsigned char* obj);
struct Obj02088674;
void ResetFlag0x80AndState(struct Obj02088674* obj);
void ClearFlag0x8AndBytes_02088cf4(unsigned char* obj);
void ClearFlag0x10AndBytes_02088d4c(unsigned char* obj);
void ClearFlag0x2AndBytes_02088c38(unsigned char* obj);
void ClearFlag0x4AndBytes_02088c9c(unsigned char* obj);
void ClearFlag0x200ClearByte0x78_020890f4(unsigned char* obj);
void ClearFlag0x400AndBytes79And9c_02089144(unsigned char* obj);
void ClearFlag0x800AndBytes7cAnd9f_02089194(unsigned char* obj);
void ClearFlag0x100AndBytes7dA0_02088d9c(unsigned char* obj);
void ClearBattleFlags0x14And0x5802087838(void* obj);
void ClearBattleFlags0x14And0x580208792c(void* obj);
void ClearBattleFlags0x14And0x5802087a20(void* obj);
void ClearBattleFlags0x14And0x5802087b14(void* obj);
void ClearBattleFlags0x14And0x5802087c08(void* obj);
void ClearBattleFlags0x14And0x58_02087cfc(void* obj);
void ClearFlagsAndBytes_02087df0(void* obj);
void ClearFlags0x14And0x58AndBytes_02087efc(unsigned char* obj);
void ClearBattleFlags0x18And0x58_020880e4(void* obj);
void ClearFlags0x14And0x58_02087ff0(void* obj);

void ApplyCombatantBuffs(int unused, int combatantId);

struct Obj_021e8cfc;
extern "C" void* func_ov024_021e8cfc(struct Obj_021e8cfc* obj, void* c, int kind, int notifyExtra);

struct Obj_021e8ca0;
void* AddEntryToListAndIncCount_021e8ca0(struct Obj_021e8ca0* obj, int id);

extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Obj_021ea85c { char pad0[0x10]; void* field0x10; };

// USA: func_ov024_021ea85c
extern "C" ARM void* func_ov024_021ea85c(struct Obj_021ea85c* obj, int id, int flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	int flagA = IsFlagBit8388608Set_021da998((struct FlagObj_021da998*)c);
	int flagB = IsFlagBit24Set_021dd260((struct FlagObj_021dd260*)c);
	ClearFlag0x14Bit0x800000AndByte0x24_02088234(c->currentStats_);
	ClearFlag0x1000000AndByte0x24_020881ac(c->currentStats_);
	ClearFlag0x200AndBytes_02088914((unsigned char*)c->currentStats_);
	ClearFlag0x8000000AndBytes_020889b4(c->currentStats_);
	ClearFlag0x10000000AndBytes_02088a04(c->currentStats_);
	ClearFlag0x20000000AndBytes0x64And0x87_02088a54((unsigned char*)c->currentStats_);
	ClearFlag0x100000_02088aa8((unsigned char*)c->currentStats_);
	ClearFlag0x400000AndBytes_02088b34((unsigned char*)c->currentStats_);
	ClearFlag0x4000000AndBytes_02088964((unsigned char*)c->currentStats_);
	ClearFlag0x40000000AndBytes_02088b84((unsigned char*)c->currentStats_);
	ClearFlag0x100AndBytes_020888c4((unsigned char*)c->currentStats_);
	ClearFlag0x4000000AndBytes_02088964((unsigned char*)c->currentStats_);
	ClearFlag0x200000_02088af0((unsigned char*)c->currentStats_);
	ClearFlag0x80000000AndBytes02088bd4((unsigned char*)c->currentStats_);
	ResetFlag0x80AndState((struct Obj02088674*)c->currentStats_);
	ClearFlag0x8AndBytes_02088cf4((unsigned char*)c->currentStats_);
	ClearFlag0x10AndBytes_02088d4c((unsigned char*)c->currentStats_);
	ClearFlag0x2AndBytes_02088c38((unsigned char*)c->currentStats_);
	ClearFlag0x4AndBytes_02088c9c((unsigned char*)c->currentStats_);
	ClearFlag0x200ClearByte0x78_020890f4((unsigned char*)c->currentStats_);
	ClearFlag0x400AndBytes79And9c_02089144((unsigned char*)c->currentStats_);
	ClearFlag0x800AndBytes7cAnd9f_02089194((unsigned char*)c->currentStats_);
	ClearFlag0x100AndBytes7dA0_02088d9c((unsigned char*)c->currentStats_);
	ClearBattleFlags0x14And0x5802087838(c->currentStats_);
	ClearBattleFlags0x14And0x580208792c(c->currentStats_);
	ClearBattleFlags0x14And0x5802087a20(c->currentStats_);
	ClearBattleFlags0x14And0x5802087b14(c->currentStats_);
	ClearBattleFlags0x14And0x5802087c08(c->currentStats_);
	ClearBattleFlags0x14And0x58_02087cfc(c->currentStats_);
	ClearFlagsAndBytes_02087df0(c->currentStats_);
	ClearFlags0x14And0x58AndBytes_02087efc((unsigned char*)c->currentStats_);
	ClearBattleFlags0x18And0x58_020880e4(c->currentStats_);
	ClearFlags0x14And0x58_02087ff0(c->currentStats_);
	ApplyCombatantBuffs((int)obj->field0x10, id);
	void* result = 0;
	if (flagA) {
		result = func_ov024_021e8cfc((struct Obj_021e8cfc*)obj, c, 0, flagArg);
	} else if (flagB && !IsFlagBit24Set_021dd260((struct FlagObj_021dd260*)c)) {
		result = func_ov024_021e8cfc((struct Obj_021e8cfc*)obj, c, 8, flagArg);
	}
	if (flagArg != 0 && result == 0) {
		void* entry = AddEntryToListAndIncCount_021e8ca0((struct Obj_021e8ca0*)obj, 0xf1);
		result = entry;
		func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
	}
	return result;
}
