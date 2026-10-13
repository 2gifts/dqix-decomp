#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);
extern "C" void func_ov017_0218f5a4(void* ov, int id, int b, int c, int d);

// USA: func_ov017_021b0b4c
ARM int CheckCombatantsAndBit4_021b0b4c(void*) {
	GameState* bs = GameState::GetInstance();
	GameResources* ov = func_ov017_0218b5b0();

	int i;
	for (i = 0; i < 4; i++) {
		GameObject* combatant = bs->GetGameObjectByIndex(i);
		if (combatant) {
			func_ov017_0218f5a4(ov, i, 0, 0, 0);
		}
	}

	return GetBitsInField0((unsigned int*)ov, 0x10) == 0 ? 1 : 0;
}
