#include <globaldefs.h>

struct S_d5b8 {
    char unk[0xc5];
    unsigned char flags;
};

// USA: func_0205d5b8
ARM void SetOrClearFlag0x20_0205d5b8(struct S_d5b8* obj, int cond) {
    if (cond) {
        obj->flags |= 0x20;
    } else {
        obj->flags &= ~0x20;
    }
}
