#include <globaldefs.h>

struct RemapFlagSub {
    char unk[0x26];
    unsigned short flags;
};

struct RemapFlagOwner {
    char unk[0xa00];
    struct RemapFlagSub sub;
};

// USA: func_020d76b8
ARM void SetRemappedBitAt0xa26_020d76b8(struct RemapFlagOwner* obj, int index) {
    if (index >= 0xc0) {
        index -= 0xbc;
    }
    obj->sub.flags |= 1 << index;
}
