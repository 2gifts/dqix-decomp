#include <globaldefs.h>

struct S02055080;
extern void* GetField0x4OrNull(struct S02055080* p);

struct GetSubField0x8Data {
    char pad[0x8];
    void* field8;
};

// USA: func_020550c0
ARM void* GetSubField0x8_020550c0(struct S02055080* p) {
    struct GetSubField0x8Data* r = (struct GetSubField0x8Data*)GetField0x4OrNull(p);
    return r == NULL ? NULL : r->field8;
}
