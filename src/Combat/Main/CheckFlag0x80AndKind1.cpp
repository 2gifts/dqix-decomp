#include <globaldefs.h>

struct S886b0 {
    char unk[0x18];
    unsigned int flags;
    char unk2[6];
    unsigned short pad0 : 9;
    unsigned short kind : 3;
    unsigned short pad1 : 4;
};

// USA: func_020886b0
ARM int CheckFlag0x80AndKind1_020886b0(struct S886b0* obj) {
    if (obj->flags & 0x80) {
        if (obj->kind == 1) {
            return 1;
        }
    }
    return 0;
}
