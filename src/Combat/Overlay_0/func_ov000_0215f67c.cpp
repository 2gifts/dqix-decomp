#include <globaldefs.h>
#include "Util/Random.h"

struct BattleCtx_0215f67c {
    struct Random rng;
    char pad_0x20[0x8df8];
    int* field_0x8e18;
};

extern unsigned short data_ov000_02182bb4[8];

int IsField0xcNonNegative(int* obj);
extern "C" int func_ov000_0215e9fc(struct BattleCtx_0215f67c* ctx, unsigned short* buf, int max, int start);
extern "C" int func_ov000_0215eb1c(struct BattleCtx_0215f67c* ctx, unsigned short* buf, int max, int start);

// USA: func_ov000_0215f67c
extern "C" ARM unsigned short func_ov000_0215f67c(struct BattleCtx_0215f67c* ctx, int kind) {
    int pick = NextRandomMax(&ctx->rng, 2);
    unsigned short table[8];
    int cnt = 8;
    unsigned short* dst = table;
    unsigned short* src = data_ov000_02182bb4;
    do {
        *dst = *src;
        dst++;
        src++;
    } while (--cnt);
    unsigned short list[6] = {0};
    unsigned short* p = list;
    int inRange = (kind >= 0 && kind <= 3);
    int count;
    if (inRange) {
        if (func_ov000_0215e9fc(ctx, table, 4, 1) < 2) {
            pick = 1;
        }
        list[0] = 0xdd;
        list[1] = 0x393;
        list[2] = 0xde;
        list[3] = 0x396;
        count = 4;
    } else {
        if (func_ov000_0215eb1c(ctx, table, 8, 1) < 2) {
            pick = 1;
        }
        list[0] = 0xdd;
        list[1] = 0x393;
        list[2] = 0xde;
        list[3] = 0x394;
        count = 4;
        if (!IsField0xcNonNegative(ctx->field_0x8e18)) {
            list[4] = 0x395;
            count = 5;
        }
    }
    switch (pick) {
    case 0:
        return 0xdb;
    default:
        return p[NextRandomMax(&ctx->rng, count)];
    }
}
