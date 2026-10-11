#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Container020dedd0;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(struct Obj_0205da38 *o);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
extern "C" char *_Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0 *c, int key);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *base, int a);
extern "C" void _Z21InitBattleTag02161798Pc(char *base);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215a7b4(char *base, int actor, short key, int sel, int x);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

// USA: func_ov002_0216bd34
extern "C" ARM void func_ov002_0216bd34(char *base) {
    char *gs  = (char *) GameState::GetInstance();
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(short *) (base + 0x1c00 + 0x14) = 0;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        _Z21InitBattleTag02161798Pc(base);
        *(signed char *) (base + 0x1000 + 0xc20) = *(int *) (base + *(short *) (base + 0x1b00 + 0xe6) * 4 + 0x1000 + 0xc3c);
        if (*(signed char *) (base + 0x1c00 + 0x20) < 0) {
            *(signed char *) (base + 0x1000 + 0xc20) = 4;
        }
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        *(short *) (base + 0x1c00 + 0x14) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        int actor = *(signed char *) (base + 0x1c00 + 0x20);
        int key   = *(short *) (base + 0x1c00 + 0x22);
        int done  = 0;
        int a     = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
        int b     = ((int (*)(void *, int)) _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38)(base + 0x2c8 + 0xc00, 0x14);
        if ((a | b) ? 1 : 0) {
            *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            switch (*(short *) (base + 0x1c00 + 0x14)) {
                case 0:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
                    *(unsigned char *) (base + 0x2000 + 0x487) = 1;
                    if (_Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0 *) (base + 0x3ec + 0x400),
                                                                          (short) key) == NULL)
                        break;
                    *(unsigned short *) (gs + 0x7100 + 0xdc) = key;
                    *(unsigned short *) (gs + 0x7f00 + 0x58) = key;
                    if (key <= 0) break;
                    *(short *) (gs + 0x7100 + 0xde) = actor;
                    if (actor < 0) break;
                    *(short *) (gs + 0x7100 + 0xe0) = *(short *) (base + 0x1b00 + 0xe8);
                    if (*(short *) (base + 0x1b00 + 0xe8) < 0) break;
                    if (*(unsigned char *) (base + 0x2000 + 0x486) != 0) {
                        if (actor >= 0 && actor <= 3) {
                            func_ov002_0215a7b4(base, actor, key, *(short *) (base + 0x1b00 + 0xe8), 0);
                        } else {
                            func_ov002_0215a7b4(base, 4, key, *(short *) (base + 0x1b00 + 0xe8), 0);
                        }
                    }
                    done = 1;
                    break;
                case 1:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
                    *(short *) (base + 0x1c00 + 0x14) = -1;
                    func_ov002_02156e90(base);
                    done = 1;
                    break;
            }
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(base, 1)) {
            *(short *) (base + 0x1c00 + 0x14) = 0;
            done                              = 1;
            func_ov002_02156e90(base);
        }
        if (!done) {
            char *g                                 = (char *) GameState::GetInstance();
            *(unsigned short *) (g + 0x7100 + 0xdc) = 0;
            *(unsigned short *) (g + 0x7f00 + 0x58) = 0;
            *(short *) (g + 0x7100 + 0xde)          = -1;
            *(short *) (g + 0x7100 + 0xe0)          = -1;
        }
    }
}
