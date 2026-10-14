#include <globaldefs.h>
#include "World/Object3D.h"

struct Obj02041598 {
    char pad_00[0xc4];
    char field_c4;
    char pad_c5[0xb];
    int field_d0;
};

// USA: func_02041598
ARM int SetByteC4AndDispatch02041598(struct Obj02041598* obj, int value, int) {
    obj->field_c4 = value;
    return ((Object3D*)obj)->MaybeSetBCFGAnimation((unsigned char)value, obj->field_d0);
}
