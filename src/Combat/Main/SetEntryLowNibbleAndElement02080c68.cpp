#include <globaldefs.h>

struct List0207f0ac;
struct Obj2081;

struct Entry02080c68 {
    char pad[0x8];
    short elemKey;
    char pad2[0x12 - 0xa];
    union {
        unsigned char raw;
        struct { unsigned char lo : 4; unsigned char hi : 4; } nib;
    } state;
};

struct Elem02080c68 {
    char pad[0xc2];
    short field0xc2;
};

extern struct Entry02080c68* FindEntryByShortId0207f0ac(struct List0207f0ac* list, int id);
extern struct Elem02080c68* FindElementByByte0xc4_02081da8(struct Obj2081* obj, int key);

// USA: func_02080c68
ARM void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value) {
    struct Entry02080c68* e = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)obj + 0xc), id);
    struct Elem02080c68* elem;
    if (e == NULL) {
        return;
    }
    e->state.raw = (e->state.raw & ~0xf) | (value & 0xf);
    elem = FindElementByByte0xc4_02081da8((struct Obj2081*)obj, e->elemKey);
    if (elem != NULL) {
        elem->field0xc2 = e->state.nib.lo & 0xf;
    }
}
