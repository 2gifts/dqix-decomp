#include <globaldefs.h>
#include "World/Object3D.h"

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);

extern unsigned short data_02114e30;

struct S0218e5c0 {
    char pad0x24[0x24];
    void* field0x24;
    char pad0x28[0x12];
    unsigned char field0x3a;
};

// USA: func_ov015_0218e5c0  (semantic: CheckFlagAndDispatch_0218e5c0)
extern "C" ARM void func_ov015_0218e5c0(struct S0218e5c0* obj) {
    int ok = 0;
    if (obj->field0x3a != 0) {
        if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x100) != 0) {
            ok = 1;
        }
    } else {
        ok = 1;
    }
    if (ok == 0) {
        return;
    }
    ((Object3D*)obj->field0x24)->AdvanceEffects();
}
