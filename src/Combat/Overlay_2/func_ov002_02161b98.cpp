#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
struct Struct_0205c4a8;
struct Struct_0205bb84;
struct Struct_0205bcdc;

extern char data_02114e54;

void SelectCoordsByFlag0x24(unsigned char *obj, int *out1, int *out2);
struct Elem_0205d81c *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
int SelectField0x8Or0x58ByFlags(unsigned char *p);
void AdvanceWrappedAccumulator0205c4a8(struct Struct_0205c4a8 *s, int delta);
int ComputeScaledSum0205bb84(struct Struct_0205bb84 *s);
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc *p, int v);
extern "C" void func_0205bb04(void *p, int v);

// USA: func_ov002_02161b98
extern "C" ARM int func_ov002_02161b98(char *base) {
    int cx;
    int cy;
    short ex;
    short sx;
    char *list;
    struct Elem_0205d81c *elem;
    if (*(unsigned char *) (&data_02114e54 + 0x55) == 0) {
        goto ret0;
    }
    SelectCoordsByFlag0x24((unsigned char *) &data_02114e54, &cx, &cy);
    elem = FindElementByC40205d81c((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00),
                                   *(int *) (base + 0x1000 + 0xbb8) & 0xff);
    if (elem == 0) {
        goto ret0;
    }
    short ey = *(short *) ((char *) elem + 0xae);
    short eh = *(short *) ((char *) elem + 0xaa);
    ex = *(short *) ((char *) elem + 0xac);
    short ew = *(short *) ((char *) elem + 0xa8);
    short sy = ey;
    sx = ex;
    sx += ew;
    sy += eh;
    int cyv = cy;
    int baseY = (short) (sy * 8);
    if (baseY - 16 <= cyv && cyv < baseY) {
        list = base + 0x2c8 + 0xc00;
        if (SelectField0x8Or0x58ByFlags((unsigned char *) list) == 1) {
            return 0;
        }
        int ex8 = (short) (ex * 8);
        if (ex8 <= cx && cx < ex8 + 16) {
            AdvanceWrappedAccumulator0205c4a8((struct Struct_0205c4a8 *) (list + 0x54), -1);
            *(int *) (base + 0x1000 + 0xbc8) = 1;
        }
        int cxv = cx;
        int W = (short) (sx * 8);
        if (W - 16 <= cxv && cxv < W) {
            AdvanceWrappedAccumulator0205c4a8((struct Struct_0205c4a8 *) (list + 0x54), 1);
            *(int *) (base + 0x1000 + 0xbc8) = 1;
        }
        int total = ComputeScaledSum0205bb84((struct Struct_0205bb84 *) (list + 0x54));
        SetIndexIfValid0205bcdc((struct Struct_0205bcdc *) (list + 4), total);
        func_0205bb04(list + 0x54, total);
    }
    return 1;
ret0:
    return 0;
}
