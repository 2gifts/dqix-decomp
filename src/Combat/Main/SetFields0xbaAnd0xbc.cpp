#include <globaldefs.h>

struct ShortPair0xba0xbc {
    char pad[0xba];
    short field_ba;
    short field_bc;
};

// USA: func_02032fd0
ARM void SetFields0xbaAnd0xbc_02032fd0(struct ShortPair0xba0xbc* obj, short a, short b) {
    obj->field_ba = a;
    obj->field_bc = b;
}
