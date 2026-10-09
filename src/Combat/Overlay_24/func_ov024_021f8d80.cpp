#include <globaldefs.h>

extern "C" void __clear(void* dst, int size);

struct Stats_021f8d80 {
	unsigned short currHP;
	char pad2[0x14 - 2];
	unsigned int flags14;
};
struct Unit_021f8d80 {
	char pad0[0x138];
	struct Stats_021f8d80* stats;
};
struct Ctx_021f8d80 {
	char pad0[0x10];
	unsigned int flags10;
};

// USA: func_ov024_021f8d80
extern "C" ARM int func_ov024_021f8d80(void* unused, int* outIndex, struct Ctx_021f8d80* ctx, struct Unit_021f8d80** units, int count, float* hpScale, float* hpThreshold, int scaleMult) {
	int priority[8];
	__clear(priority, sizeof(priority));
	for (int i = 0; i < count; i++) {
		struct Stats_021f8d80* stats = units[i]->stats;
		unsigned int flags = stats->flags14;
		if ((ctx->flags10 & 0x400) && (flags & 0x200)) {
			priority[i] = -1;
		} else if (flags & 8) {
			priority[i] = 1;
		} else if (flags & 0x20) {
			priority[i] = 2;
		} else if (flags & 0x10) {
			priority[i] = 3;
		} else if (stats->currHP <= hpThreshold[i]) {
			priority[i] = 5;
		} else {
			priority[i] = 4;
		}
	}
	int best = 0;
	for (int i = 1; i < count; i++) {
		if (priority[i] > priority[best]) {
			best = i;
		} else if (priority[i] == priority[best]) {
			int hp = units[i]->stats->currHP;
			int bestHp = units[best]->stats->currHP;
			int better = 0;
			int margin = hp - (int)hpScale[i] * scaleMult;
			int bestMargin = bestHp - (int)hpScale[best] * scaleMult;
			if (margin <= 0) {
				if (bestMargin > 0) {
					better = 1;
				} else if (hp > bestHp) {
					better = 1;
				}
			} else if (margin < bestMargin) {
				better = 1;
			}
			if (better) best = i;
		}
	}
	*outIndex = best;
	return priority[best] >= 0;
}
