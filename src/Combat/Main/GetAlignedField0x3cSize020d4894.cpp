#include <globaldefs.h>

void* GetBattleContext_020d41d8(void);
extern "C" int func_020d424c(int, int, int);
void InvalidateDataCacheRange(const void* addr, unsigned int size);

struct BattleCtx020d4894 {
    unsigned char pad0[4];
    void* sub;
};

// USA: func_020d4894
ARM int GetAlignedField0x3cSize020d4894(void) {
    struct BattleCtx020d4894* ctx = (struct BattleCtx020d4894*)GetBattleContext_020d41d8();
    if (func_020d424c(2, 7, 8) != 0) return 0;
    InvalidateDataCacheRange((const void*)((int)((char*)ctx->sub + 0xc)), 4);
    if (*(int*)((char*)ctx->sub + 0xc) == 1) return 0;
    InvalidateDataCacheRange((const void*)((int)((char*)ctx->sub + 0x3c)), 4);
    return (*(unsigned short*)((char*)ctx->sub + 0x3c) + 0x1f) & ~0x1f;
}
