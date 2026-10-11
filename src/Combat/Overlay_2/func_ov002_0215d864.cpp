#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_02157030(void *base, int type, short *a, short *b, short *c, short *d);
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_0215d950(void *base, void *dst, int flag);
extern "C" int func_0205d304(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);

struct BufOv0215d864 {
    char pad[0xbd0];
    void *buf;
};
struct FieldOv0215d864 {
    char pad[0xbb8];
    int field;
};
struct ListOv0215d864 {
    char pad[0x58];
    int n;
};

// USA: func_ov002_0215d864
extern "C" ARM int func_ov002_0215d864(char *base) {
    struct ListOv0215d864 *l = (struct ListOv0215d864 *) (base + 0x2c8 + 0xc00) + 1;
    l--;
    int many = 0;
    if (l->n > 1) {
        many = 1;
    }
    short s16 = 0, s14 = 0, s12 = 1, s10 = 1;
    func_ov002_02157030(base, 3, &s16, &s14, &s12, &s10);
    s16 = s16 + s12;
    func_ov002_0215be00(base, ((struct FieldOv0215d864 *) (base + 0x1000))->field & 0xff, s16, 1);

    memset(((struct BufOv0215d864 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_0215d950(base, ((struct BufOv0215d864 *) (base + 0x1000))->buf, 0);

    return func_0205d304(base + 0xec8, ((struct BufOv0215d864 *) (base + 0x1000))->buf, 0, 0, many, 1, 0, 0);
}
