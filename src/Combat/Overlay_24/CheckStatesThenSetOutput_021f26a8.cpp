#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

struct S_state21_021edca4;
int IsState5_021edca4(struct S_state21_021edca4* obj);

struct S_state21_021edc80;
int IsState4_021edc80(struct S_state21_021edc80* obj);

// USA: func_ov024_021f26a8  (semantic: CheckStatesThenSetOutput_021f26a8)
extern "C" ARM int func_ov024_021f26a8(int* p0, short id, int unused2, int* outFlag, short* out5) {
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(*p0, id);
	if (!c) return 0;
	if (IsState5_021edca4((struct S_state21_021edca4*)c)) return 0;
	if (IsState4_021edc80((struct S_state21_021edc80*)c)) return 0;
	*out5 = id;
	*outFlag = 1;
	return 1;
}
