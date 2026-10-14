#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void func_ov015_0218d50c(void* obj);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);

extern unsigned short data_02114e30;

struct Obj0218e4f8 {
    char pad0[0x24];
    char* ptr24;
    char pad1[0x2c - 0x24 - 4];
    unsigned char flag2c;
    char pad2[0x3a - 0x2c - 1];
    unsigned char flag3a;
};

// USA: func_ov015_0218e4f8  (semantic: ApplyCombatantEffectIfActive)
extern "C" ARM void func_ov015_0218e4f8(struct Obj0218e4f8* obj) {
    unsigned char flag3a;
    unsigned char flag2c = obj->flag2c;
    if (flag2c != 0) {
        func_ov015_0218d50c(obj);
    }
    flag3a = obj->flag3a;
    char* sub;
    int result = 0;
    char* base = obj->ptr24;
    sub = base + 8;
    if (flag3a != 0) {
        if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x100)) result = 1;
    } else {
        result = 1;
    }
    if (!result) return;
    ((Object3D*)base)->AdvanceEffects();
    ((Object3D*)(sub + 0x400))->AdvanceEffects();
    ((Object3D*)(base + 0x35c))->AdvanceEffects();
    ((Object3D*)(base + 0xac))->AdvanceEffects();
}
