#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(struct Obj_0205da38 *o);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
int GetWord0x0(int *p);
extern "C" void _Z31SetNodeFieldsAndInsert_021a120cPhhh(unsigned char *p, unsigned char a, unsigned char b);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *base, int a);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_0215c2c8(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_02012fe4(void);
extern "C" void func_02017c58(void);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

static inline int GetSlot0216257c(char *b, int i) {
    return *(int *) (b + i * 4 + 0x1000 + 0xc54);
}
static inline int InRange0216257c(int v) {
    return (v >= 0 && v <= 3) ? 1 : 0;
}

// USA: func_ov002_0216257c
extern "C" ARM void func_ov002_0216257c(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(short *) (base + 0x1b00 + 0xe2)        = 0;
        *(signed char *) (base + 0x1000 + 0xc20) = GetSlot0216257c(base, *(short *) (base + 0x1b00 + 0xe2));
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215c2c8(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        *(short *) (base + 0x1b00 + 0xe2) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        int a = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
        int b = ((int (*)(void *, int)) _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38)(base + 0x2c8 + 0xc00, 0x14);
        if ((a | b) ? 1 : 0) {
            *(signed char *) (base + 0x1000 + 0xc20) =
                *(signed char *) (base + *(short *) (base + 0x1b00 + 0xe2) + 0x1c00 + 0x6e);
            int v = *(signed char *) (base + 0x1c00 + 0x20);
            if (!InRange0216257c(v)) return;
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
            ((void (*)(unsigned char *, int, int)) _Z31SetNodeFieldsAndInsert_021a120cPhhh)(
                (unsigned char *) GetWord0x0((int *) GameState::GetInstance()), 3, v);
            *(int *) (base + 0x1000 + 0xbb8) = 0x2b;
            *(int *) (base + 0x1000 + 0xbc0) = 0;
            func_02012fe4();
            func_02017c58();
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(base, 1)) {
            *(short *) (base + 0x1b00 + 0xe2) = -1;
            func_ov002_02156e90(base);
        }
    }
}
