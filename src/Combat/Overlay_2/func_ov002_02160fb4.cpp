#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_02157030(void *base, int type, short *a, short *b, short *c, short *d);
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_021610c4(void *base, void *dst, int flag);
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
extern "C" void _Z23ApplyElemFields0205d904Ph(unsigned char *obj);

struct BufOv02160fb4 {
    char pad[0xbd0];
    void *buf;
};
struct FieldOv02160fb4 {
    char pad[0xbb8];
    int field;
};

static inline void SetPos02160fb4(struct Elem_0205d81c *e, short x, short y) {
    e->fac = x;
    e->fae = y;
}
static inline void SetSize02160fb4(struct Elem_0205d81c *e, short w, short h) {
    e->fa8 = w;
    e->faa = h;
}

// USA: func_ov002_02160fb4
extern "C" ARM void func_ov002_02160fb4(char *base) {
    short s16, s14, s12, s10;
    func_ov002_0215be00(base, ((struct FieldOv02160fb4 *) (base + 0x1000))->field & 0xff, 1, 1);

    memset(((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_021610c4(base, ((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0);

    func_0205d304(base + 0xec8, ((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);

    struct Elem_0205d81c *elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci(
        (struct Struct_0205d81c *) (base + 0xec8), ((struct FieldOv02160fb4 *) (base + 0x1000))->field & 0xff);
    if (elem == NULL) return;

    func_ov002_02157030(base, ((struct FieldOv02160fb4 *) (base + 0x1000))->field & 0xff, &s16, &s14, &s12, &s10);
    s16 = 0x20 - s12;
    s14 = 0xf - s10;
    SetPos02160fb4(elem, s16, s14);
    SetSize02160fb4(elem, s12, s10);
    _Z23ApplyElemFields0205d904Ph((unsigned char *) (base + 0xec8));
}
