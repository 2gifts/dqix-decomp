#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021edf00(int* ctx, int id, short* outIds);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" void func_ov024_021ed8c0(void* context, int id, int recordAddress, int* count, short* ids);

extern unsigned short data_ov024_021feb14;

// JPN: func_ov024_021f4f34
// USA: func_ov024_021f4768
extern "C" ARM int func_ov024_021f4768(int* ctx, int id, int record, int* count, short* ids) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021feb14;
	int n = 4;
	do {
		short* dd = d++;
		*dd = *s++;
	} while (--n);

	int found = func_ov024_021edf00(ctx, id, buf);
	if (found <= 0) {
		found = func_ov000_0215e9fc(*ctx, buf, 4, 1);
		if (found <= 0) return 0;
	}

	*count = 0;
	for (int i = 0; i < found; i++) {
		GameObject* c = GetCombatantByID(*ctx, buf[i]);
		if (!c) continue;
		if (c->currentStats_->primaryStats.currMP < 1) continue;
		int idx = *count;
		*count = idx + 1;
		ids[idx] = buf[i];
	}
	if (*count <= 0) return 0;

	func_ov024_021ed8c0(ctx, id, record, count, ids);
	return 1;
}
