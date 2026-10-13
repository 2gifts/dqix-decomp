#include <globaldefs.h>

struct Trans_021eb044_Obj {
    char pad[0x57c];
    unsigned short value;
};

// USA: func_ov025_021eb044  (semantic: Trans_021eb044)
extern "C" ARM void func_ov025_021eb044(Trans_021eb044_Obj* obj, int val) {
    obj->value = val;
}
