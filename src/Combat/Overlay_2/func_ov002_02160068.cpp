#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_0205d304(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
struct Struct0205de24;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
struct Struct_0205d81c;
void SetElementFieldC2(struct Struct_0205d81c *s, int a, int b);
int AppendCursorTag(char *dst, int cursor);
extern "C" void _Z23AppendFieldTags021601e0PhPc(unsigned char *base, char *dst);

struct BufOv02160068 {
    char pad[0xbd0];
    char *buf;
};
struct FieldOv02160068 {
    char pad[0xbb8];
    int field;
};

// USA: func_ov002_02160068
extern "C" ARM void func_ov002_02160068(char *base) {
    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0xec8), 0, 3);
    func_ov002_0215be00(base, 0x1d, 0x15, 0xb);
    memset(((struct BufOv02160068 *) (base + 0x1000))->buf, 0, 0x960);
    ((void (*)(char *, char *, int)) _Z23AppendFieldTags021601e0PhPc)(base, ((struct BufOv02160068 *) (base + 0x1000))->buf,
                                                                      0);
    func_0205d304(base + 0xec8, ((struct BufOv02160068 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0, 0);

    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0xec8), 0, 3);
    func_ov002_0215be00(base, ((struct FieldOv02160068 *) (base + 0x1000))->field & 0xff, 4, 3);
    memset(((struct BufOv02160068 *) (base + 0x1000))->buf, 0, 0x960);
    AppendCursorTag(((struct BufOv02160068 *) (base + 0x1000))->buf, *(short *) (base + 0x1c06));
    func_0205d304(base + 0xec8, ((struct BufOv02160068 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0, 0);

    SetElementFieldC2((struct Struct_0205d81c *) (base + 0xec8), 0x1d, 0);
}
