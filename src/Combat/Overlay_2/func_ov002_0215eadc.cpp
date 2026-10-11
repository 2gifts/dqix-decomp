#include "std_library_functions.h"
#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);
struct Struct0205de24;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
void SetElementFieldC2(struct Struct_0205d81c *s, int key, int value);
extern "C" void _Z21InitBattleTag0215ee04Pc(char *base);

extern "C" void func_ov002_0215ef60(void *base);
extern "C" void func_ov002_02157030(void *base, int type, short *a, short *b, short *c, short *d);
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_0215ec4c(void *base, void *dst, int flag);
extern "C" void func_0205d304(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);

struct BufOv0215eadc {
    char pad[0xbd0];
    void *buf;
};
struct FieldOv0215eadc {
    char pad[0xbb8];
    int field;
};
struct CountOv0215eadc {
    char pad[0x58];
    int count;
};

// USA: func_ov002_0215eadc
extern "C" ARM void func_ov002_0215eadc(char *base, int refresh) {
    struct CountOv0215eadc *l = (struct CountOv0215eadc *) (base + 0x2c8 + 0xc00) + 1;
    l--;
    int many = 0;
    if (l->count > 1) many = 1;
    if (refresh == 0) {
        _Z21InitBattleTag0215ee04Pc(base);
        func_ov002_0215ef60(base);
    }
    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0xec8), 0, 2);
    short s16 = 0, s14 = 0, s12 = 1, s10 = 1;
    func_ov002_02157030(base, 0x10, &s16, &s14, &s12, &s10);
    s16    = s16 + s12;
    int id = ((struct FieldOv0215eadc *) (base + 0x1000))->field & 0xff;
    if (refresh != 0) id = 0x11;
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (base + 0xec8), id) == 0) {
        func_ov002_0215be00(base, id, s16, s14);
        memset(((struct BufOv0215eadc *) (base + 0x1000))->buf, 0, 0x960);
        func_ov002_0215ec4c(base, ((struct BufOv0215eadc *) (base + 0x1000))->buf, 0);
        func_0205d304(base + 0xec8, ((struct BufOv0215eadc *) (base + 0x1000))->buf, 0, 0, many, 1, 0, 0);
    }
    if (refresh == 0) {
        SetElementFieldC2((struct Struct_0205d81c *) (base + 0xec8), 0x12, 0);
        SetElementFieldC2((struct Struct_0205d81c *) (base + 0xec8), 0x13, 0);
    }
}
