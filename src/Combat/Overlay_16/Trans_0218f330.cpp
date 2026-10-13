#include <globaldefs.h>

struct Trans_0218f330_Obj {
    char pad[0x88];
    int entries[2];
    int index;
};

// USA: func_ov016_0218f330  (semantic: Trans_0218f330)
extern "C" ARM int func_ov016_0218f330(void* obj) {
    Trans_0218f330_Obj* self = (Trans_0218f330_Obj*)obj;
    return self->entries[self->index];
}
