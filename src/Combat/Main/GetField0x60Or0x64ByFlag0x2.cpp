#include <globaldefs.h>

struct Struct_203ce00 {
    char pad[0x5c];
    unsigned int flags;
    int field60;
    int field64;
};

// USA: func_0203ce00
ARM int GetField0x60Or0x64ByFlag0x2_0203ce00(struct Struct_203ce00* obj) {
    if (obj->flags & 0x2) {
        return obj->field64;
    }
    return obj->field60;
}
