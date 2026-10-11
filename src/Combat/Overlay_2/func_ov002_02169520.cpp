#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;

extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void *o, int key);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
int TestFlag0SetAndFlag1Clear(unsigned short *flags, int mask);
extern "C" int _Z29GetField110ArrayValue021574d4Pvi(void *self, int idx);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *self, int flag);
extern "C" void func_ov002_02161cf0(void *self);
extern "C" void func_ov002_02160274(void *self);
extern "C" void func_ov002_02156e90(void *self);
extern unsigned short data_02114e30;
extern char data_02108760[];

// USA: func_ov002_02169520
extern "C" ARM void func_ov002_02169520(char *base) {
    int phase = *(int *) (base + 0x1bc0);
    if (phase == 0) {
        *(short *) (base + 0x1c08) = 0;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0xec8), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_02160274(base);
        (*(int *) (base + 0x1bc0))++;
        return;
    }
    if (phase != 1) return;
    *(int *) (base + 0x247c) |= 4;
    short old                  = *(short *) (base + 0x1c08);
    *(short *) (base + 0x1c08) = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (base + 0xec8));
    if (old != *(short *) (base + 0x1c08)) *(int *) (base + 0x1bcc) = 1;
    *(signed char *) (base + 0x1c20) = _Z29GetField110ArrayValue021574d4Pvi(base, *(short *) (base + 0x1c08));
    int pressed                      = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int cancel = (pressed | _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(base + 0xec8, 0x14)) ? 1 : 0;
    if (cancel) {
        *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1bb8);
        *(int *) (base + 0x247c) &= ~4;
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
        int ok                     = 0;
        *(short *) (base + 0x1c12) = ok;
        int sel                    = *(signed char *) (base + 0x1c20);
        if (sel >= 0 && sel <= 3) ok = 1;
        if (!ok) return;
        *(short *) (base + 0x1c28) = sel;
        *(int *) (base + 0x1bb8)   = 0x1e;
        *(int *) (base + 0x1bc0)   = 0;
        return;
    }
    if (_Z29CheckFlagOrThreshold_02161b48Pci(base, 1)) {
        *(short *) (base + 0x1c08)       = -1;
        *(signed char *) (base + 0x1c20) = -1;
        func_ov002_02156e90(base);
    }
}
