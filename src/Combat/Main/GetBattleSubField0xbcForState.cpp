#include <globaldefs.h>

void* GetBattleContext_020d41d8(void);
int GetBattleStateCode_020d41e8(void);
void InvalidateDataCacheRange(const void* addr, unsigned int size);

struct BattleCtx020d4ac8 {
    unsigned char pad0[4];
    void* sub;
};

// USA: func_020d4ac8
#pragma optimize_for_size off
ARM int GetBattleSubField0xbcForState_020d4ac8(void) {
    struct BattleCtx020d4ac8* ctx = (struct BattleCtx020d4ac8*)GetBattleContext_020d41d8();
    if (GetBattleStateCode_020d41e8() != 0) return 0;

    InvalidateDataCacheRange((const void*)ctx->sub, 2);
    unsigned short code = *(unsigned short*)ctx->sub;

    if (code != 9) {
        if (code != 10 && code != 11) goto return_zero;
    } else {
        InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0x182), 2);
        if (*(unsigned short*)((char*)ctx->sub + 0x182) == 0) return 0;
    }

    InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0xbc), 2);
    return *(unsigned short*)((char*)ctx->sub + 0xbc);
return_zero:
    return 0;
}
