#include <globaldefs.h>

struct IntField0x4_0209a670 {
    char pad[0x4];
    int field;
};

#if defined(jpn)
#define GetIntAt0x4 func_0209c3c4
extern "C" ARM int func_0209c3c4(struct IntField0x4_0209a670* obj);
#endif

// USA: func_0209a670
ARM int GetIntAt0x4(struct IntField0x4_0209a670* obj) {
    return obj->field;
}
