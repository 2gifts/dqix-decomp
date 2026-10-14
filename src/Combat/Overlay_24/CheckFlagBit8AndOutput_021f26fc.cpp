#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);
struct S_flag8b;
int IsFlagBit8Set_021f273c(struct S_flag8b* obj);

struct Wrapper_021f26fc { int field0; };

// USA: func_ov024_021f26fc  (semantic: CheckFlagBit8AndOutput_021f26fc)
extern "C" ARM int func_ov024_021f26fc(struct Wrapper_021f26fc* a, int id, int unused2, int* outFlag, short* outId) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(a->field0, id);
	if (!c) return 0;
	int result;
	if (IsFlagBit8Set_021f273c((struct S_flag8b*)c)) {
		result = 0;
	} else {
		result = 1;
		*outId = (short)id;
		*outFlag = result;
	}
	return result;
}
