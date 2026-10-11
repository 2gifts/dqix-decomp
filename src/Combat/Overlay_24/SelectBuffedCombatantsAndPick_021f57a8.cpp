#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int battle, short* buf, int max, int start);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Buf4_021f57a8 { short v[4]; };
extern struct Buf4_021f57a8 data_ov024_021feb1c;

// USA: func_ov024_021f57a8  (semantic: SelectBuffedCombatantsAndPick_021f57a8)
extern "C" ARM int func_ov024_021f57a8(int* a0, int a1, int a2, int* outCount, short* outArray) {
	struct Buf4_021f57a8 buf = data_ov024_021feb1c;
	int count = func_ov000_0215e9fc(*a0, buf.v, 4, 1);
	if (count <= 0) {
		return 0;
	}

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(*a0, buf.v[i]);
		if (!c) continue;
		if (*((unsigned char*)c->currentStats_ + 0x24) == 0) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		outArray[idx] = buf.v[i];
	}
	if (*outCount <= 0) {
		return 0;
	}
	PickRandomTableEntryResetCounter_021ed890((struct Random**)a0, outCount, outArray);
	return 1;
}
