#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021edf00(int* a0, int a1, short* a2);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" void func_ov024_021ed8c0(void* context, int id, int recordAddress, int* count, short* ids);

int CheckFlag0x14Bit0x10Set(unsigned char* obj);

struct FlagInner_021de25c { char unk[0x14]; int flags; };
struct FlagObj_021de25c { char unk[0x138]; struct FlagInner_021de25c* inner; };
extern "C" int _Z22IsFlagBit5Set_021de25cP16FlagObj_021de25c(struct FlagObj_021de25c* obj);

extern unsigned short data_ov024_021fec1c;

// USA: func_ov024_021f1b40
extern "C" ARM int func_ov024_021f1b40(int* a0, int a1, int a2, int* a3, short* a4) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021fec1c;
	int n = 4;
	do {
		short* dd = d++;
		*dd = *s++;
	} while (--n);

	int count = func_ov024_021edf00(a0, a1, buf);
	if (count <= 0) {
		count = func_ov000_0215e9fc(*a0, buf, 4, 1);
		if (count <= 0) return 0;
	}

	*a3 = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(*a0, buf[i]);
		if (!c) continue;
		if (CheckFlag0x14Bit0x10Set((unsigned char*)c->currentStats_)) continue;
		if (_Z22IsFlagBit5Set_021de25cP16FlagObj_021de25c((struct FlagObj_021de25c*)c)) continue;
		int idx = *a3;
		*a3 = idx + 1;
		a4[idx] = buf[i];
	}
	if (*a3 <= 0) return 0;

	func_ov024_021ed8c0(a0, a1, a2, a3, a4);
	return 1;
}
