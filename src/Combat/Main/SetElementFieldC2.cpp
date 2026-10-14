#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xc2];
    unsigned short fieldC2;
    char pad1[0xe0 - 0xc4];
};

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* field9C;
    char pad1[0xe0 - 0xa0];
};

struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c*, int);

// USA: func_0205deb4
ARM void SetElementFieldC2_0205deb4(struct Struct_0205d81c* s, int key, int value) {
    struct Elem_0205d81c* e;
    if (s->field98 == 0 || s->field9C == 0) return;
    e = FindElementByC40205d81c(s, key);
    if (e != 0) {
        unsigned short nibble = value & 0xf;
        e->fieldC2 = nibble & 0xf;
    }
}
