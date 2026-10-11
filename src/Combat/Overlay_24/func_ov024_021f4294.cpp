#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(int* a0);
int CheckFlag0x14Bit0x10Set(unsigned char* obj);

struct Stats_021f4294 { char unk[0x47]; unsigned char field_0x47; };

extern unsigned short data_ov024_021fec44;

// JPN: func_ov024_021f4a60
// USA: func_ov024_021f4294
extern "C" ARM int func_ov024_021f4294(int* a0, int a1, int a2, int* outCount, short* outArray) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021fec44;
	int n = 4;
	do {
		short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
	if (count <= 0) return 0;
	if (!func_ov024_021ede2c(a0)) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(*a0, buf[i]);
		if (!c) continue;
		if (CheckFlag0x14Bit0x10Set((unsigned char*)c->currentStats_)) continue;
		int value = ((struct Stats_021f4294*)c->currentStats_)->field_0x47;
		if (value <= 0) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		outArray[idx] = buf[i];
	}
	if (*outCount <= 0) return 0;
	if (*outCount * 3 < count * 2) return 0;

	*outCount = count;
	memcpy(outArray, buf, 8);
	return 1;
}
