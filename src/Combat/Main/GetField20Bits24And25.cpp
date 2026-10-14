#include <globaldefs.h>

struct B8840Inner {
    char unk[0x8];
    unsigned int pad : 24;
    unsigned int field : 2;
};

struct B8840Obj {
    char unk[0x20];
    struct B8840Inner* field20;
};

// USA: func_02068840
ARM int GetField20Bits24And25_02068840(int unused, struct B8840Obj* obj) {
    struct B8840Inner* p = obj->field20;
    if (p != 0) {
        return p->field;
    }
    return 0;
}
