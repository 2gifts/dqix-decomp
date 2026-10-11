#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
struct S_bf3c_021f1440;
int IsBitfield2Set_021f1440(struct S_bf3c_021f1440* obj);
extern "C" int func_ov000_0215eb1c(int a, short* buf, int max, int start);

struct Obj_021f1578 { int field0; };
struct Buf8_021f1578 { short v[8]; };
extern struct Buf8_021f1578 data_ov024_021fef5c;

struct BuffWord_021f1578 {
    signed int attackBuff : 3;
    signed int defenseBuff : 3;
    signed int agilityBuff : 3;
    signed int charmBuff : 3;
    signed int magicalMightBuff : 3;
    signed int magicalMendingBuff : 3;
    signed int unkBuff18 : 3;
    signed int unkBuff21 : 3;
};

// USA: func_ov024_021f1578  (semantic: FindCombatantWithLowUnkBuff21_021f1578)
extern "C" ARM int func_ov024_021f1578(struct Obj_021f1578* obj, short id, int unused2, int* outCount, void* outArr) {
	GameObject* c0 = GetCombatantWithFlag0x400ByID(obj->field0, id);
	if (!c0) return 0;
	if (!IsBitfield2Set_021f1440((struct S_bf3c_021f1440*)c0)) return 0;

	struct Buf8_021f1578 buf = data_ov024_021fef5c;
	int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
	if (count <= 0) return 0;

	int found = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
		if (!c) continue;
		struct BuffWord_021f1578* bw = (struct BuffWord_021f1578*)((char*)c->currentStats_ + 0x58);
		if (bw->unkBuff21 < 2) {
			found = 1;
			break;
		}
	}
	if (!found) return 0;

	*outCount = count;
	memcpy(outArr, buf.v, 0x10);
	return 1;
}
