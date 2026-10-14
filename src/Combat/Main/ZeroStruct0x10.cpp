#include <globaldefs.h>

struct Struct0x10 {
    unsigned short a;
    unsigned short b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
};

// USA: func_020a810c
ARM void ZeroStruct0x10_020a810c(struct Struct0x10* obj) {
    obj->a = 0;
    obj->b = 0;
    obj->c = 0;
    obj->d = 0;
    obj->e = 0;
}
