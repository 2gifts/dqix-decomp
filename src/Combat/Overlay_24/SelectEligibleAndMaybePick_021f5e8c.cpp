#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
struct FlagObj_021de25c;
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

extern unsigned short data_ov024_021fea74;

// USA: func_ov024_021f5e8c  (semantic: SelectEligibleAndMaybePick_021f5e8c)
extern "C" ARM int func_ov024_021f5e8c(int* a0, int a1, int a2, int* outCount, short* outArray) {
	unsigned short buf[4];
	unsigned short* s = &data_ov024_021fea74;
	unsigned short* d = buf;
	int n = 4;
	do {
		unsigned short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, *(short*)&buf[i]);
		if (!member) continue;
		if (IsFlagBit5Set_021de25c((struct FlagObj_021de25c*)member)) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		outArray[idx] = *((short*)buf + i);
	}
	if (*outCount > 0) {
		PickRandomTableEntryResetCounter_021ed890((struct Random**)a0, outCount, outArray);
		return 1;
	}
	return 0;
}
