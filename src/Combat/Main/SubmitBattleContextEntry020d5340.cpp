#include <globaldefs.h>
#include "System/Memory.h"

extern "C" int func_020d424c(int a, int b, int c, int d);
void SetBattleContextArrayEntry_020d404c(int index, int value);
int CommitBattleContextBuffer020d4168(void* a, unsigned int b);

struct BattleCtx020d5340 {
    int field0;
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned char mid[6];
    unsigned short type;
    unsigned short field0x12;
    unsigned char tail[0x20];
    unsigned short field0x34;
};

struct BattleReqBuf020d5340 {
    unsigned short tag;
    unsigned short field2;
    int field4;
    unsigned short field8;
    unsigned short fielda;
    unsigned char mid[6];
    unsigned short field0x12;
    unsigned short field0x14;
    unsigned char tail[0x20];
    unsigned short field0x36;
    unsigned char pad[4];
};

#pragma optimize_for_size off

// USA: func_020d5340
ARM int SubmitBattleContextEntry020d5340(int a0, struct BattleCtx020d5340* ctx) {
    int r = func_020d424c(3, 2, 3, 5);
    if (r != 0) {
        return r;
    }
    if (ctx == NULL) {
        return 6;
    }
    if (ctx->field0 == 0) {
        return 6;
    }
    if (ctx->field4 > 0x400) {
        return 6;
    }
    if (ctx->field0x12 > 0x20) {
        return 6;
    }
    if (ctx->type != 0 && ctx->type != 1 && ctx->type != 2 && ctx->type != 3) {
        return 6;
    }
    if ((unsigned short)(ctx->type + 0xfffe) <= 1) {
        if (ctx->field0x34 > 0x20) {
            return 6;
        }
    }
    SetBattleContextArrayEntry_020d404c(0x26, a0);
    struct BattleReqBuf020d5340 buf;
    buf.tag = 0x26;
    buf.field2 = ctx->field6;
    buf.field4 = ctx->field0;
    buf.field8 = ctx->field4;
    buf.fielda = ctx->field8;
    VectorizedInvertedMemcpy(ctx->mid, buf.mid, 6);
    buf.field0x12 = ctx->type;
    buf.field0x36 = ctx->field0x34;
    buf.field0x14 = ctx->field0x12;
    VectorizedInvertedMemcpy(ctx->tail, buf.tail, 0x20);
    r = CommitBattleContextBuffer020d4168(&buf, 0x3c);
    return (r == 0) ? 2 : r;
}
