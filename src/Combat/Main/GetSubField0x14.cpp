#include <globaldefs.h>

struct S02055080;
extern void* GetField0x4OrNull(struct S02055080* p);

struct GetSubField0x14Data {
    char pad[0x14];
    void* field14;
};

// USA: func_02055108
ARM void* GetSubField0x14_02055108(struct S02055080* p) {
    struct GetSubField0x14Data* r = (struct GetSubField0x14Data*)GetField0x4OrNull(p);
    return r == NULL ? NULL : r->field14;
}
