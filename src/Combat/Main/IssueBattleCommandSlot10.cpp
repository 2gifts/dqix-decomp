#include <globaldefs.h>

void* GetBattleContext_020d41d8(void);
extern "C" int func_020d424c(int a, int b, int c, int d);
void SetBattleContextArrayEntry_020d404c(int index, int value);
int CommitBattleContextBuffer020d4168(void* a, unsigned int b);

struct BattleCtx020d5254 {
    int field0;
    unsigned short type;
    unsigned short field6;
    unsigned char b8, b9, ba, bb, bc, bd;
};

struct BattleReqBuf020d5254 {
    unsigned short tag;
    unsigned short type;
    int field0;
    unsigned short field6;
    unsigned char b8, b9, ba, bb, bc, bd;
};

#pragma optimize_for_size off

// USA: func_020d5254
ARM int IssueBattleCommandSlot10(int a0, struct BattleCtx020d5254* ctx) {
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
    if (ctx->type < 1 || ctx->type > 0xe) {
        return 6;
    }
    SetBattleContextArrayEntry_020d404c(0xa, a0);
    struct BattleReqBuf020d5254 buf;
    buf.tag = 0xa;
    buf.type = ctx->type;
    buf.field0 = ctx->field0;
    buf.field6 = ctx->field6;
    buf.b8 = ctx->b8;
    buf.b9 = ctx->b9;
    buf.ba = ctx->ba;
    buf.bb = ctx->bb;
    buf.bc = ctx->bc;
    buf.bd = ctx->bd;
    r = CommitBattleContextBuffer020d4168(&buf, 0x10);
    return (r == 0) ? 2 : r;
}
