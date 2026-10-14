#include <globaldefs.h>

struct Field8Bits0To3 {
    unsigned int pad[2];
    unsigned int value : 4;
};

// USA: func_020de31c
ARM int IsField8Bits0To3Equal_020de31c(struct Field8Bits0To3* obj, int value) {
    return obj->value == value;
}
