#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern unsigned short data_ov024_021fe6c8;

// USA: func_ov024_021da47c  (semantic: SumEligibleAttackWithRandomFactor_021da47c)
extern "C" ARM int func_ov024_021da47c(int* a0, unsigned short category, int unused1, int unused2, int unused3, int fallback) {
	int inRange = (category <= 3) ? 1 : 0;
	if (!inRange) {
		return fallback;
	}

	GameState* battle = GameState::GetInstance();

	int sum = 0;
	unsigned short buf[4];
	unsigned short* s = &data_ov024_021fe6c8;
	unsigned short* d = buf;
	int n = 4;
	do {
		unsigned short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battle, *(short*)&buf[i]);
		if (c) {
			sum += c->currentStats_->primaryStats.attack;
		}
	}

	float randomFactor = NextRandomFloatBetween(*(struct Random**)a0, 0.95f, 1.5f);
	return (int)(sum * randomFactor);
}
