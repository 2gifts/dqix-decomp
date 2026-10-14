#include <globaldefs.h>

extern "C" int func_020d40bc(int, int, int, int, int, int);
int InitBattleModeF00_020d3dcc(int a, int b);
void SetBattleContextArrayEntry_020d404c(int index, int value);
void* GetBattleContext_020d41d8(void);

struct BattleCtx020d4fa4 {
    int field0;
    int field4;
    unsigned char pad8[8];
    int field10;
};

#pragma optimize_for_size off

// USA: func_020d4fa4
ARM int IssueBattleCommandSlot0_020d4fa4(int a0, int a1, int a2, int a3) {
    int r = InitBattleModeF00_020d3dcc(a0, a2);
    if (r != 0) {
        return r;
    }
    SetBattleContextArrayEntry_020d404c(0, a1);
    struct BattleCtx020d4fa4* ctx = (struct BattleCtx020d4fa4*)GetBattleContext_020d41d8();
    r = func_020d40bc(0, 4, ctx->field0, ctx->field4, ctx->field10, a3);
    if (r == 0) {
        r = 2;
    }
    return r;
}
