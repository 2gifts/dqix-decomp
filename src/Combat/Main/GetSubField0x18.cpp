#include <globaldefs.h>

struct S02055080;
extern void* GetField0x4OrNull(struct S02055080* p);

struct GetSubField0x18Data {
    char pad[0x18];
    void* field18;
};

// USA: func_02055120
ARM void* GetSubField0x18_02055120(struct S02055080* p) {
    struct GetSubField0x18Data* r = (struct GetSubField0x18Data*)GetField0x4OrNull(p);
    return r == NULL ? NULL : r->field18;
}
