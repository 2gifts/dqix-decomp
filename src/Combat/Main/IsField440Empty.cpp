#include <globaldefs.h>

struct CE28Inner {
    char unk[0x8];
    int field8;
};

struct CE28Obj {
    char unk[0x440];
    struct CE28Inner* field440;
};

// USA: func_0205ce28
ARM int IsField440Empty_0205ce28(struct CE28Obj* obj) {
    struct CE28Inner* p = obj->field440;
    if (p != 0) {
        return p->field8 == 0;
    }
    return 1;
}
