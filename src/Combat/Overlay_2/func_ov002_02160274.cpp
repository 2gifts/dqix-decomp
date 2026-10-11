#include "GameState/GameState.h"
#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_02157480(void *obj, int *arr);
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_021605d4(void *base, void *dst, int flag);
extern "C" void func_ov002_0216049c(void *base, void *dst, int flag);
extern "C" void func_ov002_0215b9a4(void *base, int a, int b);
extern "C" void func_0205d304(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
extern "C" unsigned char data_ov002_0216c9f9[];

struct Struct_0205d81c;
struct Struct_0205def8;
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
void SetElementFieldC2(struct Struct_0205d81c *s, int a, int b);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8 *s, int a, int b);

struct BufOv02160274 {
    char pad[0xbd0];
    char *buf;
};
struct FieldOv02160274 {
    char pad[0xbb8];
    int field;
};

static inline int InRange02160274(int v) {
    return (v >= 0 && v <= 3) ? 1 : 0;
}
static inline void SetPos02160274(struct Elem_0205d81c *e, short x, short y) {
    e->fac = x;
    e->fae = y;
}

// USA: func_ov002_02160274
extern "C" ARM void func_ov002_02160274(char *base) {
    int ids[4];
    GameState *gs = GameState::GetInstance();
    func_ov002_02157480(base, ids);
    int n = 0;
    for (int i = 0; i < 4; i++) {
        if (InRange02160274(ids[i]) && GetCombatantWithFlag0x100(gs, ids[i]) != NULL) {
            n++;
        }
    }
    int h = n * 2;
    if (n == 1) h++;
    func_ov002_0215be00(base, 0x20, 0x10, (short) (h + 10));
    memset(((struct BufOv02160274 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_021605d4(base, ((struct BufOv02160274 *) (base + 0x1000))->buf, 0);
    func_0205d304(base + 0xec8, ((struct BufOv02160274 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0, 0);

    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0xec8), 0, 2);
    func_ov002_0215be00(base, ((struct FieldOv02160274 *) (base + 0x1000))->field & 0xff, 0x10, 8);
    memset(((struct BufOv02160274 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_0216049c(base, ((struct BufOv02160274 *) (base + 0x1000))->buf, 0);
    func_0205d304(base + 0xec8, ((struct BufOv02160274 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);

    SetElementFieldC2((struct Struct_0205d81c *) (base + 0xec8), 0x20, 0);
    _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) (base + 0xec8), 0, 0x29);
    struct Elem_0205d81c *elem =
        _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (base + 0xec8), 0x15);
    if (elem != NULL) {
        int x = elem->fac + elem->fa8;
        for (int i = 0; i < 2; i++) {
            struct Elem_0205d81c *e = _Z23FindElementByC40205d81cP15Struct_0205d81ci(
                (struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), data_ov002_0216c9f9[i]);
            if (e != NULL) {
                SetPos02160274(e, x, e->fae);
            }
        }
    }
    func_ov002_0215b9a4(base, ((struct FieldOv02160274 *) (base + 0x1000))->field & 0xff, 0);
}
