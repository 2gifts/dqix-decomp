#include <globaldefs.h>

struct B885cInner {
    char unk[0x8];
    unsigned int pad : 24;
    unsigned int field : 2;
};

struct B885cObj {
    char unk[0x8];
    struct B885cInner* field8;
};

// USA: func_0206885c
ARM int GetField8Bits24And25_0206885c(int unused, struct B885cObj* obj) {
    struct B885cInner* p = obj->field8;
    if (p != 0) {
        return p->field;
    }
    return 0;
}
