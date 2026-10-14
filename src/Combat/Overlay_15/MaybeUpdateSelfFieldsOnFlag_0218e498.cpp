#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct0218e498 {
    unsigned char pad0[0x24];
    unsigned char* field24;
    unsigned char pad1[0x2c - 0x24 - 4];
    unsigned char flag2c;
    unsigned char pad2[0x3a - 0x2c - 1];
    unsigned char flag3a;
};

extern "C" void func_ov015_0218cc24(struct Struct0218e498* obj);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);

extern unsigned short data_02114e30;

// USA: func_ov015_0218e498  (semantic: MaybeUpdateSelfFieldsOnFlag_0218e498)
extern "C" ARM void func_ov015_0218e498(struct Struct0218e498* obj) {
    if (obj->flag2c != 0) {
        func_ov015_0218cc24(obj);
    }

    unsigned char cond = obj->flag3a;
    unsigned char* p = obj->field24;
    int flag = 0;
    if (cond != 0) {
        if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x100) != 0) {
            flag = 1;
        }
    } else {
        flag = 1;
    }
    if (flag) {
        ((Object3D*)p)->AdvanceEffects();
    }
}
