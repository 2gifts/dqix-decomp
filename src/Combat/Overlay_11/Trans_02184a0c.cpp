#include <globaldefs.h>

struct Trans_02184a0c_Obj {
    char pad[0x1b2];
    unsigned short key;
};

// USA: func_ov011_02184a0c  (semantic: Trans_02184a0c)
extern "C" ARM void func_ov011_02184a0c(Trans_02184a0c_Obj* obj, unsigned short key) {
    obj->key = key;
}
