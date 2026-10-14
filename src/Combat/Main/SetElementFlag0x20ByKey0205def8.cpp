#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c*, int);
struct S_d5b8;
void SetOrClearFlag0x20_0205d5b8(struct S_d5b8*, int);

struct Struct_0205def8 {
    char pad0[0x98];
    int field98;
    int field9C;
};

// USA: func_0205def8
ARM void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8* s, int clear, int key) {
    struct Elem_0205d81c* elem;
    if (s->field98 == 0 || s->field9C == 0) return;
    elem = FindElementByC40205d81c((struct Struct_0205d81c*)s, key);
    if (elem == 0) return;
    SetOrClearFlag0x20_0205d5b8((struct S_d5b8*)elem, clear == 0);
}
