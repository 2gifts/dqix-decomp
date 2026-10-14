#include <globaldefs.h>

struct Obj53dfcInner {
    char unk[0x8];
    int field8;
};

struct Obj53dfc {
#if defined(jpn)
    char unk[0x190];
#else
    char unk[0x19c];
#endif
    struct Obj53dfcInner* field19c;
};

// USA: func_02053dfc
ARM int GetField8FromField19c_02053dfc(struct Obj53dfc* obj) {
    struct Obj53dfcInner* p = obj->field19c;
    if (p != 0) {
        return p->field8;
    }
    return 0;
}
