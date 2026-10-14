#include <globaldefs.h>

struct S_10088_inner {
    char unk[0x14];
    int flags;
};

struct S_10088 {
    char unk[0x138];
    struct S_10088_inner* inner;
};

// USA: func_02010088
ARM int IsFlag10088Set_02010088(struct S_10088* obj) {
    return (obj->inner->flags & 1) != 0;
}
