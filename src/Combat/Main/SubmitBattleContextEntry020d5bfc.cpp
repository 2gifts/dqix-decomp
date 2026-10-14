#include <globaldefs.h>
#include "System/Cache.h"
#include "System/Memory.h"

void* GetBattleContext_020d41d8(void);
extern "C" int func_020d424c(int a, int b);
void SetBattleContextArrayEntry_020d404c(int index, int value);
extern "C" int func_020d40bc(int a, int b, int c, int d, int e, int f);

struct BattleCtx020d5bfc {
    unsigned char pad0[4];
    void* sub;
};

#pragma optimize_for_size off

// USA: func_020d5bfc
ARM int SubmitBattleContextEntry020d5bfc(int a0, void* a1, void* a2, unsigned int a3) {
    struct BattleCtx020d5bfc* ctx = (struct BattleCtx020d5bfc*)GetBattleContext_020d41d8();
    int rc = func_020d424c(1, 0xb);
    if (rc != 0) return rc;
    InvalidateDataCacheRange((const void*)((int)((char*)ctx->sub + 0x10)), 4);
    if (*(int*)((char*)ctx->sub + 0x10) == 0) return 3;
    if (a3 > 0x5e4) return 6;
    CleanCacheRange(a2, a3);
    SetBattleContextArrayEntry_020d404c(0x12, a0);
    unsigned char buf[8];
    VectorizedInvertedMemcpy(a1, buf, 6);
    int r = func_020d40bc(0x12, 4, *(int*)&buf[0], *(int*)&buf[4], (int)a2, (int)a3);
    return (r == 0) ? 2 : r;
}
