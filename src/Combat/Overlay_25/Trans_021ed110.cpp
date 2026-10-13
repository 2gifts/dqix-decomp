#include <globaldefs.h>

struct Trans021ed110Sub {
    char pad0[0x4];
    unsigned short value;
};

struct Trans021ed110Obj {
    char pad0[0x300];
    Trans021ed110Sub sub;

    Trans021ed110Sub* GetSub() { return &sub; }
};

// USA: func_ov025_021ed110  (semantic: Trans_021ed110)
extern "C" ARM void func_ov025_021ed110(Trans021ed110Obj* obj, int value) {
    obj->GetSub()->value = value;
}
