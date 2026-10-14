#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x3acValue_020100a8(GameState* battleStruct);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea7e0
ARM int SumClampedField_021ea7e0(void *obj) {
	GameState *bs = GameState::GetInstance();
	int id = GetField0x3acValue_020100a8(bs);
	void *combatant = (void*)GetCombatantWithFlag0x100_0200ff1c(bs, id);
	int sum = 0;
	if (combatant) {
		int val150 = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
		int *arr = (int*)(val150 + 0x138);
		for (int i = 0; i < 13; i++) {
			sum += arr[i];
			if ((unsigned int)sum > 0x7fffffffu) {
				sum = 0x7fffffff;
				break;
			}
		}
	}
	func_ov017_021d6134(obj, sum);
	return 1;
}
