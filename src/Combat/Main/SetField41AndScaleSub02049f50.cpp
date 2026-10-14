#include <globaldefs.h>
#include "World/Object3D.h"

struct Bits41_37474;

struct Obj02049f50 {
    unsigned char pad1[0x41];
    unsigned char field41;
    unsigned char pad2[0x13c - 0x42];
    unsigned char* sub;
};

#pragma optimize_for_size off
// USA: func_02049f50
ARM void SetField41AndScaleSub02049f50(struct Obj02049f50* obj, int val, int count) {
    if (count <= 0) {
        obj->field41 = (obj->field41 & ~0x1f) | ((unsigned char)val & 0x1f);
    }
    if (obj->sub == NULL) return;
    int x = ((Object3D*)((struct Bits41_37474*)obj))->GetOwnAlpha();
    float f = (float)x;
    ((AlphaTween*)((unsigned short*)(obj->sub + 0x60)))->SetCurrentValue(f);
    ((AlphaTween*)(obj->sub + 0x60))->ConfigureTween(val, count);
}
