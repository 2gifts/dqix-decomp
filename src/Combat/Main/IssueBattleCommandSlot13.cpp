#include <globaldefs.h>
#include "System/Cache.h"

extern "C" int func_020d424c(int, int, int, int, int, int);
extern "C" int func_020d40bc(int, int, int);
void SetBattleContextArrayEntry_020d404c(int index, int value);
void* GetBattleContext_020d41d8(void);

struct BattleHeader020d559c {
    unsigned short field0;
    unsigned char pad[0x180];
    unsigned short field182;
};

struct BattleCtx020d559c {
    int field0;
    BattleHeader020d559c* field4;
};

#pragma optimize_for_size off

// USA: func_020d559c
ARM int IssueBattleCommandSlot13_020d559c(int a0, unsigned int a1) {
    BattleCtx020d559c* ctx = (BattleCtx020d559c*)GetBattleContext_020d41d8();
    int r = func_020d424c(5, 7, 9, 8, 0xa, 0xb);
    if (r != 0) {
        return r;
    }
    unsigned short headerVal = ctx->field4->field0;
    if (headerVal == 7 || headerVal == 9) {
        if (a1 < 1 || a1 > 0xf) {
            return 6;
        }
        InvalidateDataCacheRange(&ctx->field4->field182, 2);
        if (!(ctx->field4->field182 & (1 << a1))) {
            return 7;
        }
    } else {
        if (a1 != 0) {
            return 6;
        }
    }
    SetBattleContextArrayEntry_020d404c(0xd, a0);
    r = func_020d40bc(0xd, 1, 1 << a1);
    if (r == 0) {
        r = 2;
    }
    return r;
}
