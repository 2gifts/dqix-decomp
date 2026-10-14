#include <globaldefs.h>

struct Obj021f8960 {
    char pad[0xc];
    short a;
    short b;
};

// USA: func_ov023_021f8960
ARM void SetOffset100Fields_021f8960(char* base, short a, unsigned short b) {
    struct Obj021f8960 *obj = (struct Obj021f8960 *)(base + 0x100);
    obj->a = a;
    obj->b = b;
}
