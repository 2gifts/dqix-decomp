#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205def8;
struct Obj0205eaa0;
struct Obj020d7aa0;

int GetWord0x0(int *p);
extern "C" void func_02012fe4(void);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215f3a0(void *base);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8 *s, int clear, int key);
void SetElementFieldC2(struct Struct_0205d81c *s, int key, int value);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
extern "C" char *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);
extern "C" int _Z30IsElementFlagBit40Set_0216197ciP15Struct_0205d81c(int key, struct Struct_0205d81c *s);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
int TestFlag0SetAndFlag1Clear(unsigned short *pad, int buttons);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void *obj, int flag);
extern "C" Obj020d7aa0 *_Z25GetGlobalResetObj020d7a50v();
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(Obj020d7aa0 *obj);
extern "C" void func_ov002_02156080(void *self, short *out, short *outCount);
extern "C" int func_ov002_02161920(void *self);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *obj, int a, int b);
extern "C" void _Z37InitNodeAndInsertAt_021c1798_021c1798P13GameResourcesh(GameResources *res, unsigned char v);
extern "C" void _Z30SetPendingFlagAndSync_0215a878Pc(char *self);
int GetField0x3acValue(GameState *gs);
extern "C" void func_ov017_021bff8c(int a, int b);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *self, int v);
extern "C" void func_ov002_02156e90(void *obj);

extern "C" unsigned short data_02114e30;
extern "C" char data_02108760;

#define OBJ (self + 0x2c8 + 0xc00)

// USA: func_ov002_02166168
extern "C" ARM void func_ov002_02166168(char *self) {
    GameState *gs      = GameState::GetInstance();
    GameResources *res = (GameResources *) GetWord0x0((int *) gs);
    func_02012fe4();
    int state = *(int *) (self + 0x1bc0);
    if (state == 0) {
        *(short *) (self + 0x1bfe) = 0;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215f3a0(self);
        *(int *) (self + 0x1bc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (self + 0x247c) |= 4;
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) OBJ, 1, 0x29);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) OBJ, 1, 1);
        SetElementFieldC2((struct Struct_0205d81c *) OBJ, 0x15, 0);
        short old                  = *(short *) (self + 0x1bfe);
        *(short *) (self + 0x1bfe) = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) OBJ);
        char *e                    = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) OBJ, 0x16);
        if (e != 0) {
            *(short *) (e + 0xc2) = 0;
        }
        if (_Z30IsElementFlagBit40Set_0216197ciP15Struct_0205d81c(*(int *) (self + 0x1bb8) & 0xff,
                                                                  (struct Struct_0205d81c *) OBJ))
        {
            func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8) & 0xff, 0);
        }
        if (old != *(short *) (self + 0x1bfe)) {
            func_ov002_0215b9a4(self, 0x16, 0);
        }
        int t  = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
        int u  = _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(OBJ, 0x14);
        int ok = (t | u) ? 1 : 0;
        if (ok) {
            unsigned int f = *(unsigned int *) (self + 0x247c);
            if (f & 2) {
                return;
            }
            if (!(f & 0x20)) {
                return;
            }
            _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
            short count = 0;
            short list[9];
            func_ov002_02156080(self, list, &count);
            func_ov002_02161920(self);
            switch (list[*(short *) (self + 0x1bfe)]) {
                case 0:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
                    *(unsigned int *) (self + 0x247c) &= ~4;
                    *(int *) (self + 0x1bb8) = 0x17;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 1:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x18;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 2:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
                    *(unsigned int *) (self + 0x247c) &= ~4;
                    *(int *) (self + 0x1bb8) = 0x1f;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 3:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x21;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 4:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    _Z37InitNodeAndInsertAt_021c1798_021c1798P13GameResourcesh(res, 1);
                    _Z30SetPendingFlagAndSync_0215a878Pc(self);
                    *(int *) (self + 0x1bb8) = 0x2b;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 5:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x23;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 7:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x24;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 8: {
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    int id = (signed char) GetField0x3acValue(gs);
                    for (int i = 0; i < *(int *) (self + 0x1c50); i++) {
                        char *c = (char *) GetCombatantWithFlag0x100(gs, *(int *) (self + i * 4 + 0x1c54));
                        if (c != 0 && !(**(int **) (c + 0x130) & 1)) {
                            id = (signed char) ((int *) (self + 0x1c54))[i];
                            break;
                        }
                    }
                    func_ov017_021bff8c((int) res, id);
                    *(int *) (self + 0x1bb8) = 0x2b;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                }
            }
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(self, 1)) {
            *(short *) (self + 0x1bfe) = -1;
            func_ov002_02156e90(self);
        }
    }
}
