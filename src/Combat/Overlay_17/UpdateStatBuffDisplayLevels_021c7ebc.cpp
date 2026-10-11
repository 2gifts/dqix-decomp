#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(GameState* battleStruct);

struct Ret021c7ebc {
	unsigned char pad0[8];
	unsigned short field8;
	unsigned char pad1[0x20];
	signed char field2a;
};

struct Src021c7ebc {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned short field6;
	unsigned int v1;
	unsigned int v2;
	unsigned char selector;
};

struct StatLevelsLow_021c7ebc {
	unsigned int s0:3, s1:3, s2:3, s3:3, s4:3, s5:3, s6:3, s7:3, s8:3, s9:3;
};

struct StatLevelsHigh_021c7ebc {
	unsigned int s0:3, s1:3, s2:3, s3:3, s4:4;
};

struct StatDisplay_021c7ebc {
	unsigned char levels[15];
};

// USA: func_ov017_021c7ebc
// JPN: func_ov017_021c836c
extern "C" ARM void func_ov017_021c7ebc(int unused0, Src021c7ebc* src, GameState* battleStruct, unsigned char* globalObj) {
	unsigned char* base = globalObj + 0x3000;
#if defined(jpn)
	void* h = *(void**)(base + 0x508);
#else
	void* h = *(void**)(base + 0x718);
#endif
	Ret021c7ebc* r = (Ret021c7ebc*)func_ov017_021b8478(h);
	if (!r) return;
	if (!func_ov017_021b8468(h)) return;
	if (!GetField6b0_021b8470(h)) return;
	int val = GetField0x3acValue(battleStruct);
	if (r->field2a == val) return;
	if (r->field8 != src->field4) return;
	GameObject* c = battleStruct->GetCombatantByIndex(src->field6);
	if (!c) return;
	StatLevelsLow_021c7ebc* low = (StatLevelsLow_021c7ebc*)&src->v1;
	StatLevelsHigh_021c7ebc* high = (StatLevelsHigh_021c7ebc*)&src->v2;
	if (src->selector == 1) {
#if defined(jpn)
		StatDisplay_021c7ebc* out = (StatDisplay_021c7ebc*)((unsigned char*)(*(void**)((unsigned char*)c + 0x138)) + 0x70);
#else
		StatDisplay_021c7ebc* out = (StatDisplay_021c7ebc*)((unsigned char*)c->currentStats_ + 0x70);
#endif
		out->levels[0] = low->s0;
		out->levels[1] = low->s1;
		out->levels[2] = low->s2;
		out->levels[3] = low->s3;
		out->levels[4] = low->s4;
		out->levels[5] = low->s5;
		out->levels[6] = low->s6;
		out->levels[7] = low->s7;
		out->levels[8] = low->s8;
		out->levels[9] = low->s9;
		out->levels[10] = high->s0;
		out->levels[11] = high->s1;
		out->levels[12] = high->s2;
		out->levels[13] = high->s3;
		out->levels[14] = high->s4;
	} else {
#if defined(jpn)
		StatDisplay_021c7ebc* out = (StatDisplay_021c7ebc*)((unsigned char*)(*(void**)((unsigned char*)c + 0x138)) + 0x93);
#else
		StatDisplay_021c7ebc* out = (StatDisplay_021c7ebc*)((unsigned char*)c->currentStats_ + 0x93);
#endif
		out->levels[0] = low->s0;
		out->levels[1] = low->s1;
		out->levels[2] = low->s2;
		out->levels[3] = low->s3;
		out->levels[4] = low->s4;
		out->levels[5] = low->s5;
		out->levels[6] = low->s6;
		out->levels[7] = low->s7;
		out->levels[8] = low->s8;
		out->levels[9] = low->s9;
		out->levels[10] = high->s0;
		out->levels[11] = high->s1;
		out->levels[12] = high->s2;
		out->levels[13] = high->s3;
		out->levels[14] = high->s4;
	}
}
