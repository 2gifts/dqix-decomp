#include <globaldefs.h>

#include "Combat/DistanceSort.h"

extern "C" void _ZN8Object3D4DrawEb(void* obj, int flag);

struct Obj0205a148 {
    unsigned char pad_ac[0xac];
    int field_ac;
    short field_b0;
    unsigned char pad_b2[0x1a];
    unsigned char field_cc;
};

// USA: func_0205a148
ARM void Dispatch0205a148(struct Obj0205a148* obj) {
    if (obj->field_b0 > 0) return;
    if (obj->field_ac == 0) {
        _ZN8Object3D4DrawEb(obj, ((unsigned int)obj->field_cc << 29) >> 31);
        return;
    }
    ForwardField4To0205765c_0205578c((int*)obj);
}
