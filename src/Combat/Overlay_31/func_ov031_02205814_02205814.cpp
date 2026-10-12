#include <globaldefs.h>

struct Obj0220527c;
struct Object02205814 {
    char padding_0[0x64];
    void* inner;
    char padding_68[8];
    short flags;
    signed char kind;
    signed char state;
    unsigned short unknown_0x74;
    unsigned short unknown_0x76;
    unsigned int unknown_0x78;
};
struct LookupResult02205814 {
    char padding[0x10];
    unsigned short unknown_0x10;
    unsigned short unknown_0x12;
    unsigned int unknown_0x14;
};
void* SetLookupFields_02205134(void*, void*, int);
int TailCall0220520cField64_0220527c(Obj0220527c*, void*);
extern "C" int func_ov031_0220586c(void*);

// USA: func_ov031_02205814
extern "C" ARM int func_ov031_02205814(Object02205814* object) {
    LookupResult02205814* result = (LookupResult02205814*)SetLookupFields_02205134((void*)func_ov031_0220586c, object, object->kind);
    if (!result) return -33;
    result->unknown_0x10 = object->unknown_0x74;
    result->unknown_0x12 = object->unknown_0x76;
    result->unknown_0x14 = object->unknown_0x78;
    object->flags |= 2;
    return TailCall0220520cField64_0220527c((Obj0220527c*)object, result);
}
