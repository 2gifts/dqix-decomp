#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, short* table, int count, int flag);
extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
struct RngHolder_021ed9dc;
extern "C" int _Z27CanTargetCombatant_021ed9dcP18RngHolder_021ed9dci(struct RngHolder_021ed9dc* holder, int id);

struct Obj_021f0d28 { int battle; };
struct Buf8_021f0d28 { short v[8]; };
extern struct Buf8_021f0d28 data_ov024_021fee8c;

// USA: func_ov024_021f0d28
extern "C" ARM int func_ov024_021f0d28(struct Obj_021f0d28* obj, int unused1, int unused2, int* outCount, short* outArray) {
	int found = 0;
	struct Buf8_021f0d28 buf = data_ov024_021fee8c;
	int count = func_ov000_0215e9fc(obj->battle, buf.v, 4, 1);
	if (count <= 0) return 0;

	for (int i = 0; i < count; i++) {
		if (_Z27CanTargetCombatant_021ed9dcP18RngHolder_021ed9dci((struct RngHolder_021ed9dc*)obj, buf.v[i])) {
			found = 1;
			break;
		}
	}
	if (!found) return 0;

	memset(&buf, -1, sizeof(buf));
	count = func_ov000_0215eb1c(obj->battle, buf.v, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(obj->battle, buf.v[i]);
		if (!c) continue;
		if (c->currentStats_->unkBuff18 >= 2) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		outArray[idx] = buf.v[i];
	}

	if (*outCount <= 0) return 0;
	*outCount = count;
	memcpy(outArray, &buf, sizeof(buf));
	return 1;
}
