#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);
struct FlagObj_021dd260;
int IsFlagBit24Set_021dd260(struct FlagObj_021dd260* obj);

struct Wrapper_021f3524 { int field0; };

// USA: func_ov024_021f3524  (semantic: CheckFlagBit24AndOutput_021f3524)
extern "C" ARM int func_ov024_021f3524(struct Wrapper_021f3524* a, int id, int unused2, int* outFlag, short* outId) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(a->field0, id);
	if (!c) return 0;
	int result;
	if (IsFlagBit24Set_021dd260((struct FlagObj_021dd260*)c)) {
		result = 0;
	} else {
		result = 1;
		*outFlag = result;
		*outId = (short)id;
	}
	return result;
}
