#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" int func_ov000_0215ec80(int battle, unsigned short* table, int count, int flag);
int CheckFlag0x14Bit0x10Set(unsigned char* obj);

struct Table8_021f5db0 { unsigned short v[8]; };
extern struct Table8_021f5db0 data_ov024_021fee1c;

struct TableBuf_021f5db0 {
	int counter;
	struct Table8_021f5db0 table;
};

// USA: func_ov024_021f5db0  (semantic: CountEligibleAndSetIfExactly3_021f5db0)
extern "C" ARM int func_ov024_021f5db0(int* a0, int id, int a2, int* outFlag, short* outId) {
	GameObject* c = GetCombatantWithFlag0x400ByID(*a0, id);
	if (!c) return 0;
	int danger = *((unsigned char*)c + 0x17c);
	if (danger >= 3) return 0;

	struct TableBuf_021f5db0 buf;
	buf.table = data_ov024_021fee1c;
	buf.counter = 1;

	int count = func_ov000_0215ec80(*a0, buf.table.v, 8, danger & 0xff);
	int eligible = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, *(short*)&buf.table.v[i]);
		if (member && !CheckFlag0x14Bit0x10Set((unsigned char*)member->currentStats_)) {
			eligible++;
		}
	}
	if (eligible != 3) return 0;
	*outFlag = 1;
	*outId = (short)id;
	return 1;
}
