#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_02160004(void *base, void *dst, int flag);
extern "C" void func_ov002_0215fcc0(void *base, void *dst, int flag);
extern "C" void func_ov002_0215f8b8(void *base, void *dst, int flag);
extern "C" void func_0205d304(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);

struct Struct_0205d81c;
struct Elem_0205d81c {
    char pad0[0xaa];
    short faa;
    short fac;
    short fae;
    char pad1[0xc2 - 0xb0];
    short fc2;
};
extern "C" struct Elem_0205d81c *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);
struct Struct0205de24;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);

struct BufOv0215f6a4 {
    char pad[0xbd0];
    char *buf;
};
struct FieldOv0215f6a4 {
    char pad[0xbb8];
    int field;
};

static inline void SetPos0215f6a4(struct Elem_0205d81c *e, short x, short y) {
    e->fac = x;
    e->fae = y;
    e->fc2 = 0;
}

// USA: func_ov002_0215f6a4
extern "C" ARM void func_ov002_0215f6a4(char *base) {
    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0xec8), 0, 3);
    func_ov002_0215be00(base, 0x1b, 0x11, 1);
    memset(((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_02160004(base, ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0);
    func_0205d304(base + 0xec8, ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, 0, 0, 0, 0, 0);

    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0xec8), 0, 3);
    func_ov002_0215be00(base, 0x1a, 1, 1);
    memset(((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_0215fcc0(base, ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0);
    func_0205d304(base + 0xec8, ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);

    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0xec8), 0, 2);
    func_ov002_0215be00(base, ((struct FieldOv0215f6a4 *) (base + 0x1000))->field & 0xff, 1, 1);
    memset(((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_0215f8b8(base, ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0);
    func_0205d304(base + 0xec8, ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);

    struct Elem_0205d81c *elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci(
        (struct Struct_0205d81c *) (base + 0xec8), ((struct FieldOv0215f6a4 *) (base + 0x1000))->field & 0xff);
    if (elem == NULL) return;
    short x = elem->fac;
    short y = elem->fae;
    short h = elem->faa;
    elem    = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (base + 0xec8), 0x1a);
    if (elem != NULL) {
        SetPos0215f6a4(elem, x, y + h);
    }
    elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (base + 0xec8), 0x1b);
    if (elem != NULL) {
        SetPos0215f6a4(elem, 0x11, y + h);
    }
}
