#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02086aec;
short SumCombatantKeyMatches02086aec(struct Obj02086aec* obj, int key);
extern "C" void func_ov011_021848a0(void* a, int b);

// USA: func_ov004_02167e28
ARM int DispatchTauntState_02167e28(void* obj) {
	if (SumCombatantKeyMatches02086aec((struct Obj02086aec*)GetPtrField0x2a04_02010828(GameState::GetInstance()), 0x5617) > 0) {
		func_ov011_021848a0(obj, 0x14);
	} else {
		func_ov011_021848a0(obj, 0x3);
	}
	return 0;
}
