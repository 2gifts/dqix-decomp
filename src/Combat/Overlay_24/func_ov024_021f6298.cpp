#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215eb1c(int battle, unsigned short* table, int count, int flag);

extern unsigned short data_ov024_021fedac;

// USA: func_ov024_021f6298  (semantic: SelectEligibleByAttackStatOrCopyTable_021f6298)
#pragma opt_common_subs off
extern "C" ARM int func_ov024_021f6298(int* a0, int a1, int a2, int* outCount, short* outArray) {
	unsigned short buf[8];
	unsigned short* d = buf;
	unsigned short* s = &data_ov024_021fedac;
	int n = 8;
	do {
		unsigned short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov000_0215eb1c(*a0, buf, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, *(short*)&buf[i]);
		if (!member) continue;
		if (member->currentStats_->primaryStats.attack >= 0xffff) continue;
		if (member->currentStats_->attackBuff >= 2) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		outArray[idx] = *(short*)&buf[i];
	}
	if (*outCount <= 0) return 0;

	*outCount = count;
	memcpy(outArray, buf, 0x10);
	return 1;
}
