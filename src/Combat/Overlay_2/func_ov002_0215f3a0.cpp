#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_0215f4e8(void *base, void *dst, int flag);
extern "C" void func_0205d304(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
void AppendField0215f644(void *base, char *dst, int);

struct Struct_0205d81c;
struct Elem_0205d81c {
    char pad0[0xa8];
    short fa8;
    short faa;
    short fac;
    short fae;
};
struct Elem_0205d81c *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);

struct BufOv0215f3a0 {
    char pad[0xbd0];
    char *buf;
};
struct FieldOv0215f3a0 {
    char pad[0xbb8];
    int field;
};

static inline void SetPos0215f3a0(struct Elem_0205d81c *e, short x, short y) {
    e->fac = x;
    e->fae = y;
}

// USA: func_ov002_0215f3a0
extern "C" ARM void func_ov002_0215f3a0(char *base) {
    func_ov002_0215be00(base, 0x16, 0x10, 0x14);
    memset(((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0, 0x960);
    AppendField0215f644(base, ((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0);
    func_0205d304(base + 0xec8, ((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0, 0, 0, 0, 0, 0);

    FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0xec8), 0, 2);
    func_ov002_0215be00(base, ((struct FieldOv0215f3a0 *) (base + 0x1000))->field & 0xff, 1, 1);
    memset(((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_0215f4e8(base, ((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0);
    func_0205d304(base + 0xec8, ((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0, 0);

    struct Elem_0205d81c *elem = FindElementByC40205d81c(
        (struct Struct_0205d81c *) (base + 0xec8), ((struct FieldOv0215f3a0 *) (base + 0x1000))->field & 0xff);
    if (elem == NULL) return;
    short x = elem->fac;
    short y = elem->fae;
    short w = elem->fa8;
    elem    = FindElementByC40205d81c((struct Struct_0205d81c *) (base + 0xec8), 0x16);
    if (elem != NULL) {
        SetPos0215f3a0(elem, x + w, y);
    }
}
