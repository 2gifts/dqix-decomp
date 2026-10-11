#if defined(jpn)
#define func_ov005_02158e04 func_ov005_0215a36c
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"


extern "C" void func_ov005_02158e04(void *combatant, unsigned int scaleCount);

// USA: func_ov005_0215c034
ARM void RunBattleScaleStep0215c034(void *combatant) {
	unsigned int scaleCount = GameState::GetInstance()->GetTickCount();
	if (scaleCount == 0) scaleCount = 1;
	func_ov005_02158e04(combatant, scaleCount);
}
