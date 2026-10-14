#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

struct S_flag4000000;
int IsFlagBit67108864Set_021edc08(struct S_flag4000000* obj);

struct S_bf3c_021f1440;
int IsBitfield2Set_021f1440(struct S_bf3c_021f1440* obj);

// USA: func_ov024_021f2064  (semantic: CheckFlagsThenSetOutput_021f2064)
extern "C" ARM int func_ov024_021f2064(int* p0, short id, int unused2, int* outFlag, short* out5) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*p0, id);
	if (!c) return 0;
	if (IsFlagBit67108864Set_021edc08((struct S_flag4000000*)c)) return 0;
	if (!IsBitfield2Set_021f1440((struct S_bf3c_021f1440*)c)) return 0;
	*out5 = id;
	*outFlag = 1;
	return 1;
}
