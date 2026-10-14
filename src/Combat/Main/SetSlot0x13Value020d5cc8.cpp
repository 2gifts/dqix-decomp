#include <globaldefs.h>

void* GetBattleContext_020d41d8(void);
extern "C" int func_020d424c(int, int);
void InvalidateDataCacheRange(const void* addr, unsigned int size);
void SetBattleContextArrayEntry_020d404c(int index, int value);
extern "C" int func_020d40bc(int, int);

struct BattleCtx020d5cc8 {
    unsigned char pad0[4];
    void* sub;
};

// USA: func_020d5cc8
ARM int SetSlot0x13Value020d5cc8(int value) {
    struct BattleCtx020d5cc8* ctx = (struct BattleCtx020d5cc8*)GetBattleContext_020d41d8();
    int rc = func_020d424c(1, 0xb);
    if (rc != 0) return rc;
    InvalidateDataCacheRange((const void*)((int)((char*)ctx->sub + 0x10)), 4);
    if (*(int*)((char*)ctx->sub + 0x10) == 0) return 3;
    SetBattleContextArrayEntry_020d404c(0x13, value);
    int r = func_020d40bc(0x13, 0);
    return (r == 0) ? 2 : r;
}
