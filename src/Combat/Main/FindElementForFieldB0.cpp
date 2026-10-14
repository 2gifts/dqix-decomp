#include <globaldefs.h>

struct Elem_0205d81c { char pad0[0xe0]; };

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* field9C;
    char pad1[0xb0 - 0xa0];
    unsigned char fieldB0;
    char pad2[0xb4 - 0xb1];
    unsigned char fieldB4;
};

struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c*, int);

// USA: func_0205d8c4
ARM struct Elem_0205d81c* FindElementForFieldB0_0205d8c4(struct Struct_0205d81c* s) {
    if (s->field98 == 0) return 0;
    if (s->field9C == 0) return 0;
    if (s->fieldB4 == 0) return 0;
    return FindElementByC40205d81c(s, s->fieldB0);
}
