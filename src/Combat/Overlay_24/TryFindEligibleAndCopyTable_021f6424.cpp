#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(int* a0);
int CheckFlag0x14Bit0x10Set(unsigned char* obj);

extern unsigned short data_ov024_021feb04;

// USA: func_ov024_021f6424  (semantic: TryFindEligibleAndCopyTable_021f6424)
extern "C" ARM int func_ov024_021f6424(int* a0, int a1, int a2, int* outCount, void* outArray) {
	unsigned short buf[4];
	unsigned short* d = buf;
	unsigned short* s = &data_ov024_021feb04;
	int n = 4;
	do {
		unsigned short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
	if (count <= 0) return 0;
	if (!func_ov024_021ede2c(a0)) return 0;

	int found = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, *(short*)&buf[i]);
		if (member && !CheckFlag0x14Bit0x10Set((unsigned char*)member->currentStats_)) {
			found = 1;
			break;
		}
	}
	if (!found) return 0;

	*outCount = count;
	memcpy(outArray, buf, 8);
	return 1;
}
