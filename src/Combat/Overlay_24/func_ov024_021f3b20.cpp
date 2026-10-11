#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" float func_ov024_021db358(GameObject* obj);
extern "C" int _Z41PickRandomTableEntryResetCounter_021ed890PP6RandomPiPs(struct Random** rngPtr, int* maxAndFlag, short* table);

extern unsigned short data_ov024_021fee6c;

// JPN: func_ov024_021f42ec
// USA: func_ov024_021f3b20
extern "C" ARM int func_ov024_021f3b20(int* a0, int id, int a2, int* outCount, short* outArray) {
	GameObject* self = GetCombatantWithFlag0x400ByID(*a0, id);
	if (!self) return 0;
	if (self->currentStats_->primaryStats.currHP <= 1) return 0;

	short buf[8];
	short* d = buf;
	unsigned short* s = &data_ov024_021fee6c;
	int n = 8;
	do {
		short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov000_0215eb1c(*a0, buf, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		if (id == buf[i]) continue;
		GameObject* c = GetCombatantByID(*a0, buf[i]);
		if (!c) continue;
		if (func_ov024_021db358(c) >= 1.0f) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		outArray[idx] = buf[i];
	}
	if (*outCount <= 0) return 0;

	_Z41PickRandomTableEntryResetCounter_021ed890PP6RandomPiPs((struct Random**)a0, outCount, outArray);
	return 1;
}
