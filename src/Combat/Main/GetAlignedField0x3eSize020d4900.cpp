#include <globaldefs.h>

#include "System/Cache.h"

void* GetBattleContext_020d41d8(void);
extern "C" int func_020d424c(int a, int b, int c);

struct BattleCtx020d4900 {
    unsigned char pad0[4];
    void* sub;
};

// USA: func_020d4900
ARM int GetAlignedField0x3eSize020d4900(void) {
    struct BattleCtx020d4900* ctx = (struct BattleCtx020d4900*)GetBattleContext_020d41d8();
    if (func_020d424c(2, 7, 8) != 0) return 0;
    InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0xc), 4);
    if (*(int*)((char*)ctx->sub + 0xc) == 1) return 0;
    InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0x188), 2);
    int flag = (*(unsigned short*)((char*)ctx->sub + 0x188) == 0);
    InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0x3e), 2);
    unsigned short v3e = *(unsigned short*)((char*)ctx->sub + 0x3e);
    if (flag != 1) {
        return ((v3e + 0x51) & ~0x1f) << 1;
    }
    InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0xf8), 2);
    unsigned short vf8 = *(unsigned short*)((char*)ctx->sub + 0xf8);
    return (((v3e + 0xc) * vf8 + 0x29) & ~0x1f) << 1;
}
