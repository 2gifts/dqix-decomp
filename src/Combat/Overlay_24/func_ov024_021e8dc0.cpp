#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

int TestBit2At0x2f4(unsigned char* obj);
extern "C" int _Z28RollChanceFromTable_021564ccP6Randomi(struct Random* rand, int id);

struct Ctx_021e8dc0 {
	char pad0[0x10];
	struct Random* random;
	char pad14[0x78 - 0x14];
	unsigned char field0x78;
	unsigned char pad79;
	unsigned char field0x7a;
};

struct Params_021e8dc0 {
	char pad0[4];
	unsigned int actionId : 12;
	unsigned int rest4 : 20;
	char pad8[0x10 - 0x8];
	unsigned int flags10;
	char pad14[0x1c - 0x14];
	unsigned int low1c : 14;
	unsigned int repeatType : 5;
	unsigned int high1c : 13;
};

struct Combatant_021e8dc0 {
	char pad0[0x150];
	unsigned char* field150;
};

struct Bits2f4_021e8dc0 {
	unsigned int bit0 : 1;
	unsigned int bit1 : 1;
	unsigned int rest : 30;
};

struct ShortBuf_021e8dc0 {
	short v[32];
};

extern struct ShortBuf_021e8dc0 data_ov024_021fe930;

static inline int IsPartyMember(int id) {
	return id >= 0 && id <= 3;
}

// USA: func_ov024_021e8dc0
extern "C" ARM int func_ov024_021e8dc0(struct Ctx_021e8dc0* ctx, int id, struct Params_021e8dc0* params, short* list, int num) {
	struct Random* random = ctx->random;
	int count = 1;
	switch (params->repeatType) {
		case 1: count = 2; break;
		case 2: count = (int)NextRandomFloatBetween(random, 3.0f, 4.0f); break;
		case 6: count = 4; break;
		case 9: count = 5; break;
	}
	if (count > 1) ctx->field0x7a = 1;
	if (IsPartyMember(id)) {
		struct Combatant_021e8dc0* c = (struct Combatant_021e8dc0*)GetCombatantWithFlag0x100(GameState::GetInstance(), id);
		if (c && (params->flags10 & 0x100000) && TestBit2At0x2f4(c->field150)) {
			ctx->field0x7a = 1;
			count *= 2;
		}
		if (params->actionId == 1) {
			struct Bits2f4_021e8dc0* w = (struct Bits2f4_021e8dc0*)(c->field150 + 0x2f4);
			if (!w) return count;
			if (!w->bit1 && !w->bit0 && _Z28RollChanceFromTable_021564ccP6Randomi(ctx->random, id)) {
				ctx->field0x78 = 1;
				ctx->field0x7a = 1;
				count++;
			}
		}
	}
	struct ShortBuf_021e8dc0 buf = data_ov024_021fe930;
	short n = 0;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < num; j++) {
			buf.v[n++] = list[j];
		}
	}
	memcpy(list, &buf, n * 2);
	return n;
}
