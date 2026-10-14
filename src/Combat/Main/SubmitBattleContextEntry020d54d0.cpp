#include <globaldefs.h>
#include "System/Cache.h"
#include "System/Memory.h"

extern "C" int func_020d424c(int a, int b);
void* GetBattleContext_020d41d8(void);
void SetBattleContextArrayEntry_020d404c(int index, int value);
int CommitBattleContextBuffer020d4168(void* a, unsigned int b);

struct LenHeader020d54d0 { unsigned short len; };

struct BattleReqBuf020d54d0 {
    unsigned short tag;
    LenHeader020d54d0* ptr;
    unsigned char mid[0x18];
    int field0x20;
    unsigned char pad0x24[2];
    unsigned short field0x26;
};

#pragma optimize_for_size off

// USA: func_020d54d0  (semantic: SubmitBattleContextEntry020d54d0)
extern "C" ARM int func_020d54d0(int a0, LenHeader020d54d0* a1, const void* a2, int a3, unsigned short a4) {
    int r = func_020d424c(1, 2);
    if (r != 0) {
        return r;
    }
    if (a1 == NULL) {
        return 6;
    }
    CleanCacheRange(a1, a1->len << 1);
    void* ctx = GetBattleContext_020d41d8();
    *(unsigned short*)((char*)ctx + 0x150) = 0;
    *(int*)((char*)ctx + 0x14c) = 0;
    SetBattleContextArrayEntry_020d404c(0xc, a0);
    struct BattleReqBuf020d54d0 buf;
    buf.tag = 0xc;
    buf.ptr = a1;
    if (a2 != NULL) {
        VectorizedInvertedMemcpy(a2, buf.mid, 0x18);
    } else {
        VectorizedMemset(buf.mid, 0, 0x18);
    }
    buf.field0x20 = a3;
    buf.field0x26 = a4;
    r = CommitBattleContextBuffer020d4168(&buf, 0x28);
    return (r == 0) ? 2 : r;
}
