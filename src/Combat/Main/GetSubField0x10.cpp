#include <globaldefs.h>

struct S02055080;
extern void* GetField0x4OrNull(struct S02055080* p);

struct GetSubField0x10Data {
    char pad[0x10];
    void* field10;
};

// USA: func_020550f0
ARM void* GetSubField0x10_020550f0(struct S02055080* p) {
    struct GetSubField0x10Data* r = (struct GetSubField0x10Data*)GetField0x4OrNull(p);
    return r == NULL ? NULL : r->field10;
}
