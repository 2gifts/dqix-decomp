#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_ov000_02153e78(int battle, short* out, int max, int group, int flag);
int IsFlag10088Set(struct S_10088* obj);

struct Group_021eecc8 {
	unsigned char pad0;
	unsigned char flags : 4;
	unsigned char groupCount : 2;
	unsigned char pad1 : 2;
	char pad2[4];
	unsigned char ids[8];
	unsigned char memberCount : 4;
	unsigned char weight : 4;
	char padf[0x18 - 0xf];
};
struct Stats_021eecc8 { char pad0[0x18]; unsigned int flags18; };
struct Obj_021eecc8 { int field0; };
struct Buf8_021eecc8 { short v[8]; };
extern struct Buf8_021eecc8 data_ov024_021fecec;

// USA: func_ov024_021eecc8
extern "C" ARM int func_ov024_021eecc8(struct Obj_021eecc8* obj, int unused1, int unused2, int* outCount, short* outArray) {
	struct Group_021eecc8* groups = (struct Group_021eecc8*)((char*)obj->field0 + 0x81b0);
	if (!groups) return 0;
	int weight = 0;
	int alive = 0;
	for (int i = 0; i < groups->groupCount; i++) {
		weight += groups[i].weight;
		struct Buf8_021eecc8 buf = data_ov024_021fecec;
		alive += func_ov000_02153e78(obj->field0, buf.v, 8, i, 0);
	}
	if (weight >= 5) return 0;
	if (alive > 5) alive = 5;
	if (alive < weight * 2) return 0;
	*outCount = 0;
	int spare = alive - weight;
	for (int i = 0; i < groups->groupCount; i++) {
		struct Group_021eecc8* g = &groups[i];
		for (int j = 0; j < g->memberCount; j++) {
			int id = g->ids[j] + 0xc0;
			GameObject* c = GetCombatantByID(obj->field0, (short)id);
			if (!c) continue;
			if (((struct Stats_021eecc8*)c->currentStats_)->flags18 & 0x2000) continue;
			if (IsFlag10088Set((struct S_10088*)c)) {
				if (spare > 0) {
					spare--;
					outArray[(*outCount)++] = id;
				}
			} else {
				outArray[(*outCount)++] = id;
			}
			if (*outCount >= 5) break;
		}
	}
	return 1;
}
