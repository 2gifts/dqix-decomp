#include <globaldefs.h>
#include "Util/Random.h"

extern "C" void* func_ov000_02153710(void*, short);
extern "C" int func_ov000_02159dbc(void*, short);

struct RngHolder_021d9e60 { struct Random* rng; };

// JPN: func_ov024_021da720
// USA: func_ov024_021d9e60
ARM int RandomScaleField6cSqDiv23Plus100Alt_021d9e60(struct RngHolder_021d9e60* holder, unsigned short category, int unused1, int unused2, int unused3, int fallback) {
#if defined(jpn)
 enum { regionalOffset=0x8b8 };
#else
 enum { regionalOffset=0x950 };
#endif
	int inRange = 0;
	if (category <= 3) {
		inRange = 1;
	}
	float value;
	if (inRange) {
		char* base = (char*)func_ov000_02153710(holder->rng, (short)category);
		if (base == NULL) {
			return fallback;
		}
		int idx = *(int*)(base + regionalOffset);
		unsigned short v = *(unsigned short*)(base + idx * 2 + 0x16c);
		value = v;
	} else {
		int v = func_ov000_02159dbc(holder->rng, (short)category);
		value = v;
	}
	struct Random* rng = holder->rng;
	float sq = 100.0f + value * (value / 23.0f);
	float randomFactor1 = NextRandomFloatBetween(rng, -0.05f, 0.05f);
	float a = sq + sq * randomFactor1;
	float randomFactor2 = NextRandomFloatBetween(rng, 0.9f, 1.1f);
	float b = 217.0f * randomFactor2;
	if (a < b) {
		a = b;
	}
	return (int)a;
}
