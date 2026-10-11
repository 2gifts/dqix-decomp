#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
struct FlagObj_021df6ec;
int IsFlagBit6Set_021df6ec(struct FlagObj_021df6ec* obj);

extern unsigned short data_ov024_021fea5c;

// USA: func_ov024_021f4ed4  (semantic: SelectEligibleByStatOrCopyTable_021f4ed4)
#pragma opt_common_subs off
extern "C" ARM int func_ov024_021f4ed4(int* a0, int a1, int a2, int* outCount, short* outArray) {
	unsigned short buf[4];
	unsigned short* d = buf;
	unsigned short* s = &data_ov024_021fea5c;
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
		if (IsFlagBit6Set_021df6ec((struct FlagObj_021df6ec*)member)) continue;
		int val = *((unsigned char*)member->currentStats_ + 0x46);
		if (val <= 0) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		outArray[idx] = *(short*)&buf[i];
	}
	if (*outCount <= 0) return 0;
	if (*outCount * 3 < count * 2) return 0;

	*outCount = count;
	memcpy(outArray, buf, 8);
	return 1;
}
