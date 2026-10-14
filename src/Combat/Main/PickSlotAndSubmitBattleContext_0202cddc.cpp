#include <globaldefs.h>
#include "System/Memory.h"

void SetField0x48UnlessState9Or10_0202c848(int arg);
int GetSharedHalfwordOrBattleDefault_020d4aa8(void);
unsigned short GetOwnerDataFortuneValue020d4be8(void);

struct BattleCtx020d5340 {
    int field0;
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned char pad_a[6];
    unsigned short type;
    unsigned short field0x12;
};
int SubmitBattleContextEntry020d5340(int a0, struct BattleCtx020d5340* ctx);

extern unsigned char data_021015a0[0xc];
extern struct BattleCtx020d5340 data_02101680;
extern int data_02101b80;
extern unsigned char data_02101694[0x20];
extern "C" void func_0202cefc(void);

// USA: func_0202cddc  (semantic: PickSlotAndSubmitBattleContext_0202cddc)
extern "C" ARM int func_0202cddc(void) {
    int avail = GetSharedHalfwordOrBattleDefault_020d4aa8();
    if (avail == 0x8000) {
        SetField0x48UnlessState9Or10_0202c848(3);
        return 0;
    }
    if (avail == 0) {
        SetField0x48UnlessState9Or10_0202c848(0x16);
        return 0;
    }

    unsigned short slotOverride = *(unsigned short*)(data_021015a0 + 8);
    if (slotOverride == 0) {
        unsigned int v = data_02101680.field6;
        unsigned int t = (~v) & (v - 1);
        unsigned int lz;
        asm {
            clz lz, t
        }
        unsigned int k = 32 - lz;
        int pos = k + 1;
        unsigned int bit;
        do {
            pos = pos + 1;
            if ((unsigned int)pos > 0x10) pos = 1;
            bit = 1 << (pos - 1);
        } while ((avail & bit) == 0);
        data_02101680.field6 = bit;
    } else {
        data_02101680.field6 = (unsigned short)(1 << (slotOverride - 1));
    }

    data_02101680.field8 = GetOwnerDataFortuneValue020d4be8();
    data_02101680.field0 = (int)&data_02101b80;
    data_02101680.field4 = 0x400;
    data_02101680.type = 1;
    data_02101680.field0x12 = 0;
    VectorizedMemset(data_02101694, 0xff, 0x20);

    int r = SubmitBattleContextEntry020d5340((int)func_0202cefc, &data_02101680);
    if (r == 2) return 1;
    SetField0x48UnlessState9Or10_0202c848(r);
    return 0;
}
