#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2(struct S88514* obj);
struct FlagObj_021df6ec;
extern "C" int _Z22IsFlagBit6Set_021df6ecP16FlagObj_021df6ec(struct FlagObj_021df6ec* obj);
struct FlagObj_021dd010;
extern "C" int _Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010(struct FlagObj_021dd010* obj);

struct BuffWord_021f3564 {
    signed int attackBuff : 3;
    signed int defenseBuff : 3;
    signed int agilityBuff : 3;
    signed int charmBuff : 3;
    signed int magicalMightBuff : 3;
    signed int magicalMendingBuff : 3;
    signed int unkBuff18 : 3;
    signed int unkBuff21 : 3;
    signed int unkBuff24 : 3;
    signed int unkBuff27 : 3;
};

struct Wrapper_021f3564 { int field0; };

// USA: func_ov024_021f3564
extern "C" ARM int func_ov024_021f3564(struct Wrapper_021f3564* a, int id, int unused2, int* outFlag, short* outId) {
	GameObject* c = GetCombatantWithFlag0x400ByID(a->field0, id);
	if (!c) return 0;
	int n = 0;
	if (CheckFlag0x2AndKind1((struct Combatant_20885b4*)c->currentStats_)) n++;
	if (CheckFlag0x2AndState2((struct S88514*)c->currentStats_)) n++;
	if (_Z22IsFlagBit6Set_021df6ecP16FlagObj_021df6ec((struct FlagObj_021df6ec*)c)) n++;
	if (_Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010((struct FlagObj_021dd010*)c)) n++;
	struct BuffWord_021f3564* bw = (struct BuffWord_021f3564*)((char*)c->currentStats_ + 0x58);
	if (bw->attackBuff < 0) n++;
	if (bw->defenseBuff < 0) n++;
	if (bw->agilityBuff < 0) n++;
	if (bw->charmBuff < 0) n++;
	if (bw->magicalMightBuff < 0) n++;
	if (bw->magicalMendingBuff < 0) n++;
	if (bw->unkBuff18 < 0) n++;
	if (bw->unkBuff21 < 0) n++;
	if (bw->unkBuff27 < 0) n++;
	if (bw->unkBuff24 < 0) n++;
	int result;
	if (n <= 0) {
		result = 0;
	} else {
		result = 1;
		*outFlag = result;
		*outId = (short)id;
	}
	return result;
}
