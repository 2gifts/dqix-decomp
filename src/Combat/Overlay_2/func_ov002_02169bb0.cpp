#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Struct_0205d81c;
struct Struct_0205bcdc;
struct ShortArrays0204c610;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(struct Obj_0205da38 *o);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *base, int a);
void SelectCoordsByFlag0x24(unsigned char *p, int *x, int *y);
extern "C" char *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);
void GetFourShortsAtIndex(struct ShortArrays0204c610 *p, int idx, short *a, short *b, short *c, short *d);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(struct Struct_0205bcdc *s, int idx);
extern "C" void _Z25SyncModeIfChanged0215b268Pc(char *base);
extern "C" void func_0205bb04(void *p, int idx);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02160c68(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" unsigned char data_02114e54[];
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

// USA: func_ov002_02169bb0
extern "C" ARM void func_ov002_02169bb0(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(short *) (base + 0x1c00 + 0xe) = 0;
        *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_02160c68(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        *(short *) (base + 0x1c00 + 0xe) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        unsigned char *vals[2];
        vals[0] = (unsigned char *) (base + 0x2c + 0x1c00);
        vals[1] = (unsigned char *) (base + 0x2d + 0x1c00);
        if (data_02114e54[0x55] != 0) {
            int tx, ty;
            short x0, y0, w, h;
            SelectCoordsByFlag0x24(data_02114e54, &tx, &ty);
            char *e = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 0x23);
            if (e != NULL) {
                short key = 3;
                for (unsigned char i = 0; i < 2; i++) {
                    for (unsigned char v = 1; v <= 5; v++) {
                        short ex = *(short *) (e + 0xac);
                        short ey = *(short *) (e + 0xae);
                        GetFourShortsAtIndex((struct ShortArrays0204c610 *) e, key++, &x0, &y0, &w, &h);
                        x0 += (short) (ex * 8);
                        y0 += (short) (ey * 8);
                        if (tx >= x0 && x0 + w > tx && ty >= y0 && y0 + h > ty) {
                            *(short *) (base + 0x1c00 + 0xe) = i;
                            *vals[i]                         = v;
                            int sel                          = *(short *) (base + 0x1c00 + 0xe);
                            char *list                       = base + 0x2c8 + 0xc00;
                            _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((struct Struct_0205bcdc *) (list + 4), sel);
                            func_0205bb04(list + 0x54, sel);
                            func_ov002_0215b9a4(base, 0x23, 0);
                            _Z25SyncModeIfChanged0215b268Pc(base);
                            return;
                        }
                    }
                }
            }
        } else {
            short sel = *(short *) (base + 0x1c00 + 0xe);
            if (sel != 2) {
                unsigned char *p = vals[sel];
                int d            = 0;
                if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x20)) {
                    d = -1;
                } else if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x10)) {
                    d = 1;
                }
                if (d != 0) {
                    *p += d;
                    if (*p == 0) *p = 1;
                    if (*p > 5) *p = 5;
                    func_ov002_0215b9a4(base, 0x23, 0);
                    _Z25SyncModeIfChanged0215b268Pc(base);
                    return;
                }
            }
        }
        int a = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
        int b = ((int (*)(void *, int)) _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38)(base + 0x2c8 + 0xc00, 0x14);
        if (((a | b) ? 1 : 0) && *(short *) (base + 0x1c00 + 0xe) == 2) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(base);
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(base, 1)) {
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(base);
        }
    }
}
