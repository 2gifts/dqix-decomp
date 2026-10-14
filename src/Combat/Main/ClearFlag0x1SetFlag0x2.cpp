#include <globaldefs.h>

struct FlagSubstruct {
    char unk[0x3f];
    unsigned char flags;
};

struct FlagOwner {
    char unk[4];
    struct FlagSubstruct* sub;
};

// USA: func_020e1cb8
ARM void ClearFlag0x1SetFlag0x2_020e1cb8(struct FlagOwner* obj) {
    obj->sub->flags &= ~1;
    obj->sub->flags |= 2;
}
