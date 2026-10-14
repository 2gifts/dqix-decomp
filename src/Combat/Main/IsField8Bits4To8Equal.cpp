#include <globaldefs.h>

struct Field8Bits4To8 {
    unsigned int pad[2];
    unsigned int lowNibble : 4;
    unsigned int value : 5;
};

// USA: func_020de334
ARM int IsField8Bits4To8Equal_020de334(struct Field8Bits4To8* obj, int a1, int a2, int value) {
    return obj->value == value;
}
