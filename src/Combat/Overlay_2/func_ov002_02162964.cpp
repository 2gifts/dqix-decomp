#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205def8;
struct Obj0205eaa0;
struct Obj020d7aa0;
struct S_a0af4;

extern "C" void func_ov002_0215b2c8(char *self);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215c614(char *self);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8 *s, int clear, int key);
void SetElementFieldC2(struct Struct_0205d81c *s, int key, int value);
int TestFlagMask(unsigned short *pad, int mask);
int TestFlag0SetAndFlag1Clear(unsigned short *pad, int buttons);
extern "C" int func_0205df38(void *obj, int key);
extern "C" void func_ov002_0215b458(char *self, int v);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void *obj, int flag);
int GetField0x3acValue(GameState *gs);
extern "C" Obj020d7aa0 *_Z25GetGlobalResetObj020d7a50v();
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(Obj020d7aa0 *obj);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *obj, int a, int b);
extern "C" int _Z29GetFieldC54ArrayValue021573f8Pvi(void *self, int v);
extern "C" int _Z22GetCountByType02157108Pvi(void *self, int type);
unsigned char *GetFieldAt0x150(unsigned char *obj);
void *GetPtrField0x2a04(GameState *gameState);
extern "C" int _Z20FindKeyIndex020a0af4P7S_a0af4i(struct S_a0af4 *s, int key);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *self, int v);
extern "C" void _Z37ResetAllocatorsAndClearFields0215b428Ph(unsigned char *obj);
extern "C" void func_ov002_02156e90(void *obj);

extern "C" unsigned short data_02114e30;
extern "C" char data_02108760;

#define OBJ (self + 0x2c8 + 0xc00)
#define CUR (*(short *) (self + 0x1be6))
#define SEL (*(signed char *) (self + 0x1c20))
#define LAST (*(signed char *) (self + 0x1c73))

// USA: func_ov002_02162964
extern "C" ARM void func_ov002_02162964(char *self) {
    int state = *(int *) (self + 0x1bc0);
    if (state == 0) {
        unsigned int f = *(unsigned int *) (self + 0x247c);
        if (f & 2) {
            return;
        }
        if (!(f & 0x20)) {
            return;
        }
        *(unsigned char *) (self + 0x248d) = 0;
        func_ov002_0215b2c8(self);
        CUR = 0;
        SEL = *(int *) (self + CUR * 4 + 0x1c3c);
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215c614(self);
        *(int *) (self + 0x1bc0) += 1;
    } else if (state == 1) {
        *(short *) (self + 0x1bf0) = -1;
        *(unsigned int *) (self + 0x247c) |= 4;
        short old = CUR;
        CUR       = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) OBJ);
        func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8) & 0xff, 0);
        signed char prev = SEL;
        SEL              = *(signed char *) (self + CUR + 0x1c6e);
        if (CUR == LAST) {
            SEL = 4;
        }
        if (CUR == LAST + 1) {
            SEL = -1;
        }
        if (prev != SEL) {
            func_ov002_0215b9a4(self, 5, 0);
            _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) OBJ, SEL >= 0 ? 1 : 0, 5);
        }
        SetElementFieldC2((struct Struct_0205d81c *) OBJ, 5, 1);
        if (TestFlagMask(&data_02114e30, 0x40)) {
            return;
        }
        if (TestFlagMask(&data_02114e30, 0x80)) {
            return;
        }
        if ((TestFlag0SetAndFlag1Clear(&data_02114e30, 4) || func_0205df38(OBJ, 0x28)) && CUR == LAST) {
            func_ov002_0215b458(self, 0);
            return;
        }
        int pick = 0;
        if (func_0205df38(OBJ, 5) && CUR != LAST + 1) {
            pick = 1;
        }
        if (old != CUR) {
            return;
        }
        int t  = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
        int u  = _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(OBJ, 0x14);
        int ok = (t | u) ? 1 : 0;
        if (ok || pick) {
            *(unsigned char *) (self + 0x1c21) = GetField0x3acValue(GameState::GetInstance());
            _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
            *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
            *(unsigned int *) (self + 0x247c) &= ~4;
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
            if (CUR == LAST + 1) {
                if (LAST != 1) {
                    *(int *) (self + 0x1bb8) = 0xb;
                } else {
                    *(unsigned char *) (self + 0x1c32) = 0;
                    SetElementFieldC2((struct Struct_0205d81c *) OBJ, 4, 1);
                    *(short *) (self + 0x1bf0) = *(unsigned char *) (self + 0x2521) = 1;
                    SEL                                = _Z29GetFieldC54ArrayValue021573f8Pvi(self, 1);
                    *(short *) (self + 0x1c12)         = 0;
                    *(short *) (self + 0x1c28)         = 0x238d;
                    *(short *) (self + 0x1c2a)         = -1;
                    *(int *) (self + 0x1bb8)           = 0x26;
                    *(int *) (self + 0x1bbc)           = 4;
                    *(unsigned char *) (self + 0x1c2e) = 1;
                }
                *(int *) (self + 0x1bc0) = 0;
                return;
            }
            *(int *) (self + 0x1bb8) = 5;
            *(int *) (self + 0x1bc0) = 0;
            if (!_Z22GetCountByType02157108Pvi(self, SEL)) {
                *(short *) (self + 0x1c28) = 0x2369;
                *(short *) (self + 0x1c2a) = -1;
                int in                     = 0;
                if (SEL >= 0 && SEL <= 3) {
                    in = 1;
                }
                if (in) {
                    *(short *) (self + 0x1c28) = 0x235a;
                }
                *(int *) (self + 0x1bb8)           = 0x26;
                *(int *) (self + 0x1bbc)           = 5;
                *(unsigned char *) (self + 0x2478) = 1;
                *(unsigned char *) (self + 0x1c31) = 0;
            }
            *(short *) (self + 0x1be8) = 0;
            if (CUR != LAST) {
                return;
            }
            GameState *gs    = GameState::GetInstance();
            GameObject *hero = gs->GetProtagonist();
            if (!hero) {
                return;
            }
            unsigned char *q = GetFieldAt0x150((unsigned char *) hero);
            *(short *) (self + 0x1be8) =
                _Z20FindKeyIndex020a0af4P7S_a0af4i((struct S_a0af4 *) GetPtrField0x2a04(gs), *(short *) (q + 0x958));
            if (*(short *) (self + 0x1be8) == -1) {
                *(short *) (self + 0x1be8) = 0;
            }
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(self, 1)) {
            _Z37ResetAllocatorsAndClearFields0215b428Ph((unsigned char *) self);
            SEL                                = -1;
            CUR                                = -1;
            *(unsigned char *) (self + 0x2521) = 0;
            func_ov002_02156e90(self);
        }
    }
}
