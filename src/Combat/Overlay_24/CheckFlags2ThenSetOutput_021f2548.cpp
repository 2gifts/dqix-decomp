#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

struct S_flag100000;
int IsFlagBit1048576Set_021edc20(struct S_flag100000* obj);

struct S_flag200000;
int IsFlagBit2097152Set_021edc38(struct S_flag200000* obj);

// USA: func_ov024_021f2548  (semantic: CheckFlags2ThenSetOutput_021f2548)
extern "C" ARM int func_ov024_021f2548(int* p0, short id, int unused2, int* outFlag, short* out5) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*p0, id);
	if (!c) return 0;
	if (IsFlagBit1048576Set_021edc20((struct S_flag100000*)c)) return 0;
	if (IsFlagBit2097152Set_021edc38((struct S_flag200000*)c)) return 0;
	*out5 = id;
	*outFlag = 1;
	return 1;
}
