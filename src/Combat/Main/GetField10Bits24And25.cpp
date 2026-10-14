#include <globaldefs.h>

struct B88b0Inner {
    char unk[0x8];
    unsigned int pad : 24;
    unsigned int field : 2;
};

struct B88b0Obj {
    char unk[0x10];
    struct B88b0Inner* field10;
};

// USA: func_020688b0
ARM int GetField10Bits24And25_020688b0(int unused, struct B88b0Obj* obj) {
    struct B88b0Inner* p = obj->field10;
    if (p != 0) {
        return p->field;
    }
    return 0;
}
