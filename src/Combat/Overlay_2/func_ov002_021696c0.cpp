#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Struct_0205def8;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8 *s, int a, int b);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(struct Obj_0205da38 *o);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *base, int a);
extern "C" void _Z21CopyByteField0215aa5cPc(char *base);
extern "C" void _Z21CopyByteField0215aa14Pc(char *base);
extern "C" void _Z30ResetAndRebuildEntries02160734Ph(unsigned char *base);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215f3a0(void *base);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

static inline int AnyConfirm021696c0(char *base) {
    int a = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
    int b = ((int (*)(void *, int)) _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38)(base + 0x2c8 + 0xc00, 0x14);
    return (a | b) ? 1 : 0;
}

// USA: func_ov002_021696c0
extern "C" ARM void func_ov002_021696c0(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 0, 1);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 0, 0x29);
        func_ov002_02156e90(base);
        *(int *) (base + 0x1000 + 0xbb8) = 0x21;
        *(int *) (base + 0x1000 + 0xbc0) = 0x32;
    } else if (state == 0x32) {
        _Z21CopyByteField0215aa5cPc(base);
        *(short *) (base + 0x1c00 + 0xa) = 0;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        _Z30ResetAndRebuildEntries02160734Ph((unsigned char *) base);
        *(int *) (base + 0x1000 + 0xbc0) = 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        *(short *) (base + 0x1c00 + 0xa) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (AnyConfirm021696c0(base) && *(short *) (base + 0x1c00 + 0xa) == 7) {
            _Z21CopyByteField0215aa14Pc(base);
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(base);
            *(int *) (base + 0x1000 + 0xbb8) = 0x21;
            *(int *) (base + 0x1000 + 0xbc0) = 0x64;
        } else if (AnyConfirm021696c0(base)) {
            *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
            *(int *) (base + 0x1000 + 0xbb8) = 0x22;
            *(int *) (base + 0x1000 + 0xbc0) = 0;
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(base, 1)) {
            _Z21CopyByteField0215aa14Pc(base);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(base);
            *(int *) (base + 0x1000 + 0xbb8) = 0x21;
            *(int *) (base + 0x1000 + 0xbc0) = 0x64;
        }
    } else if (state == 0x64) {
        *(short *) (base + 0x1c00 + 0xa) = 0;
        *(int *) (base + 0x1000 + 0xbb8) = 0x15;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215f3a0(base);
        *(int *) (base + 0x1000 + 0xbc0) = 1;
    }
}
