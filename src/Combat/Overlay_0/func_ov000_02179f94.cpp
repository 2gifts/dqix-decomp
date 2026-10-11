#include <globaldefs.h>


#include "std_library_functions.h"

struct Elem_0205d81c {
    char pad0[0xAA];
    short fieldAA;
    short fieldAC;
    short fieldAE;
    char pad1[0xC2 - 0xB0];
    short fieldC2;
    unsigned char fieldC4;
    char pad2[0xE0 - 0xC5];
};

struct Struct_0205d81c {
    char pad0[0x98];
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

struct Owner_02179f94 {
    char pad0[0x188];
    struct Struct_0205d81c elems;
};

extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" struct Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_0217a19c(struct Owner_02179f94* obj, void* entry);
extern "C" void func_ov000_0217c638(struct Owner_02179f94* obj, int a, int b);
extern "C" void func_ov000_0217a2dc(struct Owner_02179f94* obj, void* entry, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(struct Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void func_0205d304(struct Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e, int f);
#endif

static inline short GetAA(const struct Elem_0205d81c* p) { return p->fieldAA; }
static inline short GetAC(const struct Elem_0205d81c* p) { return p->fieldAC; }
static inline short GetAE(const struct Elem_0205d81c* p) { return p->fieldAE; }

// USA: func_ov000_02179f94
// JPN: func_ov000_0217b308
extern "C" ARM void func_ov000_02179f94(struct Owner_02179f94* obj, void* entry, int a, int b) {
    func_ov000_0217a19c(obj, entry);
    func_ov000_0217c638(obj, a, b);
    struct Struct_0205d81c* s = &obj->elems;
    s->fieldA0 = 0x16;
    s->fieldA2 = 6;
    s->fieldA4 = 5;
#if defined(jpn)
    s->fieldA6 = 6;
#else
    s->fieldA6 = 5;
#endif
    s->fieldA8 = 0xc;
#if defined(jpn)
    s->fieldAA = 0xa;
#else
    s->fieldAA = 8;
#endif
    s->fieldAC = 0xa;
    s->fieldAE = 0xe;
    s->fieldB1 = 0x17;
#if defined(jpn)
    void* buf = *(void**)(_Z26GetGlobalField0x1c020421a0v() + 0x28);
    memset(buf, 0, 0x800);
#else
    void* buf = *(void**)(_Z26GetGlobalField0x1c020421a0v() + 0x5c);
    memset(buf, 0, 0x960);
#endif
    func_ov000_0217a2dc(obj, entry, buf);
#if defined(jpn)
    func_0205d304(s, buf, 0, 1, 0, 1, 0);
#else
    func_0205d304(s, buf, 0, 1, 0, 1, 0, 0);
#endif
    struct Elem_0205d81c* e = _Z23FindElementByC40205d81cP15Struct_0205d81ci(s, 0x18);
    if (e == 0) {
        return;
    }
    e->fieldC2 = 0;
    const struct Elem_0205d81c* ref = _Z23FindElementByC40205d81cP15Struct_0205d81ci(s, 0x17);
    if (ref == 0) {
        return;
    }
    short top = GetAC(ref);
    short bottom = GetAE(ref) + GetAA(ref);
    e->fieldAC = top;
    e->fieldAE = bottom;
}
