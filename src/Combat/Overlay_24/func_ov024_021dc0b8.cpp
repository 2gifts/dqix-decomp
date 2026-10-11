#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct ArrayContainsByteStruct;
int ArrayContainsByte(ArrayContainsByteStruct* s, int val);
void* GetPtrField0x2a04(GameState* gameState);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(unsigned char* battle, int idx);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct PackedPair_021dc0b8 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Params_021dc0b8 {
	char pad0[4];
	unsigned int actionId : 12;
	unsigned int rest4 : 20;
	char pad8[0x20 - 0x8];
	struct PackedPair_021dc0b8 f20;
	struct PackedPair_021dc0b8 f24;
	char pad28[0x32 - 0x28];
	short field0x32;
};

struct Flag_021dc0b8 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021dc0b8 { char pad0[0xc]; char* field0xc; void* field0x10; int field0x14; };

extern "C" unsigned long long func_ov024_021e4b14(struct Obj_021dc0b8* self, int a, int b, struct Params_021dc0b8* rec, int d);
extern "C" unsigned short func_ov024_021e9018(struct Obj_021dc0b8* obj, int id, int value, int mode);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);

// JPN: func_ov024_021dc964
// USA: func_ov024_021dc0b8
extern "C" ARM void* func_ov024_021dc0b8(struct Obj_021dc0b8* obj, int target, int id, struct Params_021dc0b8* params, int unused4, int unused5, unsigned char flagArg) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	unsigned short sel = 0;
	unsigned long long ef = 0;
	int flag = ((struct Flag_021dc0b8*)(obj->field0xc + 0x1c))->flag != 0;
	int handled = 0;
	if (flagArg != 0) {
		ef = func_ov024_021e4b14(obj, target, id, params, 1);
		if (ef != 0) {
			sel = _Z31SelectByIndexRange0to3_021da644iii(id, params->f20.c, params->f24.a);
			void* list = GetPtrField0x2a04(GameState::GetInstance());
			if (flag && ArrayContainsByte((ArrayContainsByteStruct*)list, target) && params->actionId == 0xa9) {
				_Z39IncrementByteCounterCapped0x63_0215a8d4Phi((unsigned char*)obj->field0x10, 5);
			}
			obj->field0x14++;
			handled = 1;
		}
	}
	if (!handled) {
		sel = func_ov024_021e9018(obj, id, params->field0x32, 0);
		if (sel == 0) {
			sel = _Z31SelectByIndexRange0to3_021da644iii(id, params->f24.b, params->f24.c);
		}
	}
	if (params->actionId == 0x20f) sel = 0;
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return 0;
	func_ov024_021e8bf0(obj, obj->field0xc, &sel);
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
	struct Flag_021dc0b8* fl = (struct Flag_021dc0b8*)(obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->field0x10, entry, c, 0, ef, fl->flag != 0);
	return entry;
}
