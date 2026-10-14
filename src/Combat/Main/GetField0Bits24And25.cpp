#include <globaldefs.h>

struct B8894Inner {
    char unk[0x8];
    unsigned int pad : 24;
    unsigned int field : 2;
};

struct B8894Obj {
    struct B8894Inner* field0;
};

// USA: func_02068894
ARM int GetField0Bits24And25_02068894(int unused, struct B8894Obj* obj) {
    struct B8894Inner* p = obj->field0;
    if (p != 0) {
        return p->field;
    }
    return 0;
}
