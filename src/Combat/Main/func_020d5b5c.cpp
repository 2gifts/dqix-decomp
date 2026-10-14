#include <globaldefs.h>

extern "C" int func_020d424c(int a, int b);
extern "C" int func_020d40bc(int a, int b, void* buf, int size);
void SetBattleContextArrayEntry_020d404c(int index, int value);
void* GetBattleContext_020d41d8(void);
void InvalidateDataCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);

struct Inner020d5b5c {
    char pad0[0x10];
    int field10;
};

struct BattleContext020d5b5c {
    char pad0[4];
    struct Inner020d5b5c* field4;
};

// USA: func_020d5b5c
#pragma optimize_for_size off
extern "C" ARM int func_020d5b5c(int index, void* buf, unsigned int size) {
    struct BattleContext020d5b5c* ctx = (struct BattleContext020d5b5c*)GetBattleContext_020d41d8();
    int r = func_020d424c(1, 8);
    if (r != 0) {
        return r;
    }
    InvalidateDataCacheRange((char*)ctx->field4 + 0x10, 4);
    if (ctx->field4->field10 == 1) {
        return 3;
    }
    if (size < 0x10) {
        return 6;
    }
    if (buf == 0) {
        return 6;
    }
    CleanCacheRange(buf, size);
    SetBattleContextArrayEntry_020d404c(0x11, index);
    r = func_020d40bc(0x11, 2, buf, size);
    if (r == 0) {
        r = 2;
    }
    return r;
}
