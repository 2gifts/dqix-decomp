#include <globaldefs.h>


#include "std_library_functions.h"

struct Elem_0205d81c {
    char pad0[0xC2];
    short fieldC2;
    unsigned char fieldC4;
    char pad1[0xE0 - 0xC5];
};

struct Struct_0205d81c {
    char pad0[0x54];
    char field54[0x98 - 0x54];
    int field98;
    struct Elem_0205d81c* field9C;
    short fieldA0;
    short fieldA2;
    short fieldA4;
    short fieldA6;
    short fieldA8;
    short fieldAA;
    short fieldAC;
    short fieldAE;
    char padB0;
    unsigned char fieldB1;
    char padB2;
    unsigned char fieldB3;
    unsigned char fieldB4;
};

struct Owner_02179018 {
    char pad0[0x188];
    struct Struct_0205d81c elems;
};

struct Entry_02179018 {
    char pad0[0x44];
    int x;
    int y;
};

extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" int _Z18GetField0_0205bafcPv(void* obj);
extern "C" struct Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_02179194(struct Owner_02179018* obj, struct Entry_02179018* entry);
extern "C" void func_ov000_0217ab8c(struct Entry_02179018* entry, int a, int b);
extern "C" void func_ov000_0217936c(struct Owner_02179018* obj, struct Entry_02179018* entry, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(struct Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void func_0205d304(struct Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e, int f);
#endif
extern "C" void func_ov000_02176210(struct Struct_0205d81c* s, int a, int key);

// USA: func_ov000_02179018
// JPN: func_ov000_0217a474
extern "C" ARM void func_ov000_02179018(struct Owner_02179018* obj, struct Entry_02179018* entry, int a, int b) {
    func_ov000_02179194(obj, entry);
    int x = entry->x;
    int y = entry->y;
    func_ov000_0217ab8c(entry, a, b);
    struct Struct_0205d81c* s = &obj->elems;
#if defined(jpn)
    s->fieldA0 = 0xe;
#else
    s->fieldA0 = 0x10;
#endif
    s->fieldA2 = 9;
#if defined(jpn)
    s->fieldA4 = (x >> 3) + 9;
#else
    s->fieldA4 = (x >> 3) + 0x10;
#endif
    s->fieldA6 = y >> 3;
    s->fieldA8 = 0xc;
    s->fieldAA = 8;
    s->fieldAC = 0xa;
    s->fieldAE = 0xc;
    s->fieldB1 = 0x10;
    int many = 0;
    if (_Z18GetField0_0205bafcPv(s->field54) > 4) {
        many = 1;
    }
#if defined(jpn)
    void* buf = *(void**)(_Z26GetGlobalField0x1c020421a0v() + 0x28);
    memset(buf, 0, 0x800);
#else
    void* buf = *(void**)(_Z26GetGlobalField0x1c020421a0v() + 0x5c);
    memset(buf, 0, 0x960);
#endif
    func_ov000_0217936c(obj, entry, buf);
#if defined(jpn)
    func_0205d304(s, buf, 0, 0, many, 1, 0);
#else
    func_0205d304(s, buf, 0, 0, many, 1, 0, 0);
#endif
    struct Elem_0205d81c* e = _Z23FindElementByC40205d81cP15Struct_0205d81ci(s, 0x23);
    if (e != 0) {
        e->fieldC2 = 0;
    }
    func_ov000_02176210(&obj->elems, 0x10, 0x23);
}
