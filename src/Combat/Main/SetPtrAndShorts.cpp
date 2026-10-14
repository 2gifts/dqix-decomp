#include <globaldefs.h>

struct StructAA8 {
    int field0;
    short field4;
    short field6;
};

// USA: func_02072aa8
ARM int SetPtrAndShorts_02072aa8(struct StructAA8* obj, int ptr, int value) {
    short v = value;
    obj->field0 = ptr;
    obj->field6 = v;
    obj->field4 = v;
    return 1;
}
