#include <globaldefs.h>

struct NibbleStruct {
    int unk0;
    int unk4;
    unsigned int nibble : 4;
};

// USA: func_020de34c
ARM int IsField8NibbleInRange_020de34c(struct NibbleStruct* s, int lo, int hi) {
    return lo <= (int)s->nibble && (int)s->nibble <= hi;
}
