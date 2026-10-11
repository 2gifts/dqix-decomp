#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205def8;
struct Obj0205eaa0;
struct Obj0205dee8;
struct Entry_02165764 {
    int f0;
    unsigned int id : 12;
    unsigned int rest : 20;
};

extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8 *s, int clear, int key);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215eadc(void *obj, int val);
extern "C" void _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(struct Obj0205dee8 *obj, int val);
void SetElementFieldC2(struct Struct_0205d81c *s, int key, int value);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
extern "C" void func_ov002_02161b98(char *self);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
extern "C" int _Z30IsElementFlagBit40Set_0216197ciP15Struct_0205d81c(int key, struct Struct_0205d81c *s);
int TestFlag0SetAndFlag1Clear(unsigned short *pad, int buttons);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void *obj, int flag);
char *GetCombatantChecked(GameState *gs, int id);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *obj, int a, int b);
extern "C" int func_ov002_0215b720(char *self, int id);
extern "C" void func_ov002_02157d40(char *self);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *self, int v);
extern "C" void _Z27ClearMatchingEntry_02156ff0Phi(unsigned char *self, int v);
extern "C" int _Z33CheckAndClearEntryStatus_0215b7d0v();

extern "C" unsigned short data_02114e30;
extern "C" char data_02108760;

#define OBJ (self + 0x2c8 + 0xc00)

// USA: func_ov002_02165764
extern "C" ARM void func_ov002_02165764(char *self) {
    int state = *(int *) (self + 0x1bc0);
    if (state == 0) {
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) OBJ, 0, 0x29);
        *(short *) (self + 0x1bfa) = 0;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215eadc(self, 0);
        _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i((struct Obj0205dee8 *) OBJ, 0x11);
        SetElementFieldC2((struct Struct_0205d81c *) OBJ, 0x11, 0);
        func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8) & 0xff, 0);
        *(int *) (self + 0x1bc0) += 1;
        return;
    }
    if (state == 1) {
        *(unsigned int *) (self + 0x247c) |= 4;
        short old = *(short *) (self + 0x1bfa);
        func_ov002_02161b98(self);
        *(short *) (self + 0x1bfa) = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) OBJ);
        if (old != *(short *) (self + 0x1bfa)) {
            *(int *) (self + 0x1bcc) = 1;
        }
        SetElementFieldC2((struct Struct_0205d81c *) OBJ, 0x12, 0);
        SetElementFieldC2((struct Struct_0205d81c *) OBJ, 0x13, 0);
        if (_Z30IsElementFlagBit40Set_0216197ciP15Struct_0205d81c(*(int *) (self + 0x1bb8) & 0xff,
                                                                  (struct Struct_0205d81c *) OBJ))
        {
            func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8) & 0xff, 0);
        }
        int t  = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
        int u  = _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(OBJ, 0x14);
        int ok = (t | u) ? 1 : 0;
        if (ok) {
            *(unsigned char *) (self + 0x1c84) = 3;
            char *c = GetCombatantChecked(GameState::GetInstance(), *(signed char *) (self + 0x1c20));
            if (c == 0) {
                return;
            }
            if (**(int **) (c + 0x130) & 1) {
                *(short *) (self + 0x1c28) = -1;
                *(short *) (self + 0x1c2a) = -1;
                *(int *) (self + 0x1bb8)   = 0x11;
                return;
            }
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
            *(short *) (self + 0x1c26) = -1;
            short v                    = *(short *) (self + 0x1bfa);
            if (v >= 0 && v < 0x20) {
                *(short *) (self + 0x1c26) = (*(Entry_02165764 **) (self + v * 4 + 0x24a0))->id;
            }
            if (func_ov002_0215b720(self, *(short *) (self + 0x1c26))) {
                *(int *) (self + 0x1bc0) = 2;
                return;
            }
            *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
            *(unsigned int *) (self + 0x247c) &= ~4;
            *(int *) (self + 0x1bc0) = 0;
            func_ov002_02157d40(self);
            return;
        }
        if (_Z29CheckFlagOrThreshold_02161b48Pci(self, 1)) {
            *(short *) (self + 0x1bfa) = -1;
            *(short *) (self + 0x1c26) = -1;
            *(int *) (self + 0x1bb8)   = 0x10;
            _Z27ClearMatchingEntry_02156ff0Phi((unsigned char *) self, 0x11);
            SetElementFieldC2((struct Struct_0205d81c *) OBJ, 0x11, 1);
            _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i((struct Obj0205dee8 *) OBJ, 0x10);
            SetElementFieldC2((struct Struct_0205d81c *) OBJ, 0x10, 0);
            *(int *) (self + 0x1bc0) = 1;
            *(int *) (self + 0x1bb8) = 0x10;
            func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8) & 0xff, 0);
            func_ov002_02161cf0(self);
            _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) OBJ, 1, 0x29);
        }
        return;
    }
    if (state != 2) {
        return;
    }
    int r = _Z33CheckAndClearEntryStatus_0215b7d0v();
    if (r > 0) {
        *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
        *(unsigned int *) (self + 0x247c) &= ~4;
        *(int *) (self + 0x1bc0) = 0;
        func_ov002_02157d40(self);
        return;
    }
    if (r < 0) {
        *(short *) (self + 0x1c28)         = 0x232d;
        *(short *) (self + 0x1c2a)         = -1;
        *(short *) (self + 0x2488)         = 0x232b;
        *(unsigned char *) (self + 0x248a) = 1;
        *(int *) (self + 0x1bb8)           = 0x26;
        *(int *) (self + 0x1bbc)           = 0x11;
        *(int *) (self + 0x1bc0)           = 0;
    }
}
