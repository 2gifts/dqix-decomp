#include <globaldefs.h>

struct Trans_021f6bc0_Obj {
    char pad[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
};

// USA: func_ov024_021f6bc0  (semantic: Trans_021f6bc0)
extern "C" ARM int func_ov024_021f6bc0(Trans_021f6bc0_Obj* obj) {
    obj->f1c = 0.75f * obj->f14;
    obj->f20 = 0.75f * obj->f18;
    return 1;
}
