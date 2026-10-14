#include <globaldefs.h>

struct S02055080;
extern void* GetField0x4OrNull(struct S02055080* p);

struct GetSubField0xCData {
    char pad[0xc];
    void* fieldC;
};

// USA: func_020550d8
ARM void* GetSubField0xC_020550d8(struct S02055080* p) {
    struct GetSubField0xCData* r = (struct GetSubField0xCData*)GetField0x4OrNull(p);
    return r == NULL ? NULL : r->fieldC;
}
