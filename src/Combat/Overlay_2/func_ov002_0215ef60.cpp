#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_0215f084(void *base, void *dst, int flag);
extern "C" void func_0205d304(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);

struct Struct_0205d81c;
struct Elem_0205d81c {
    char pad0[0xa8];
    short fa8;
    short faa;
    short fac;
    short fae;
};
extern "C" struct Elem_0205d81c *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);
struct Struct0205de24;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
struct StructA0205d5d0;
extern "C" void _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0 *s, int key, int buf, int a3,
                                                                     unsigned char a4);

struct BufOv0215ef60 {
    char pad[0xbd0];
    void *buf;
};

static inline void SetPos0215ef60(struct Elem_0205d81c *e, short x, short y) {
    e->fac = x;
    e->fae = y;
}

// USA: func_ov002_0215ef60
extern "C" ARM void func_ov002_0215ef60(char *base) {
    short x = 0x17;
    short y = 9;
    short w = 0;
    struct Elem_0205d81c *elem =
        _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (base + 0xec8), 0x10);
    if (elem != NULL) {
        x = elem->fac;
        w = elem->fa8;
        y = elem->fae + elem->faa;
    }
    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0xec8), 0, 2);
    func_ov002_0215be00(base, 0x13, x, y);

    memset(((struct BufOv0215ef60 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_0215f084(base, ((struct BufOv0215ef60 *) (base + 0x1000))->buf, 0);

    func_0205d304(base + 0xec8, ((struct BufOv0215ef60 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0, 0);

    elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (base + 0xec8), 0x13);
    if (elem == NULL) return;
    SetPos0215ef60(elem, x + w - elem->fa8, elem->fae);
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0 *) (base + 0xec8), 0x13,
                                                         (int) ((struct BufOv0215ef60 *) (base + 0x1000))->buf, 1, 0);
}
