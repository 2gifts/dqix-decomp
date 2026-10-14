#include <globaldefs.h>

struct B8824Inner {
    char unk[0x8];
    unsigned int pad : 24;
    unsigned int field : 2;
};

struct B8824Obj {
    char unk[0x18];
    struct B8824Inner* field18;
};

// USA: func_02068824
ARM int GetBits24And25_02068824(int unused, struct B8824Obj* obj) {
    struct B8824Inner* p = obj->field18;
    if (p != 0) {
        return p->field;
    }
    return 0;
}
