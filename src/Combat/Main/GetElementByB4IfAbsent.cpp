#include <globaldefs.h>

struct Elem_0205e00c { char pad0[0xe0]; };

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205e00c* field9C;
    char pad1[0xb4 - 0xa0];
    unsigned char fieldB4;
};

struct Elem_0205e00c* FindElementByC40205d81c(struct Struct_0205d81c*, int);

// USA: func_0205e00c
ARM struct Elem_0205e00c* GetElementByB4IfAbsent_0205e00c(struct Struct_0205d81c* s, int key) {
    if (FindElementByC40205d81c(s, key) != 0) return 0;
    return &s->field9C[s->fieldB4];
}
