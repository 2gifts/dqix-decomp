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
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215c614(char *self);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int clear, int key);
void SetElementFieldC2_0205deb4(struct Struct_0205d81c *s, int key, int value);
int TestFlagMask_02012430(unsigned short *pad, int mask);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short *pad, int buttons);
extern "C" int func_0205df38(void *obj, int key);
extern "C" void func_ov002_0215b458(char *self, int v);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
int GetField0x3acValue_020100a8(GameState *gs);
Obj020d7aa0 *GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(Obj020d7aa0 *obj);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *obj, int a, int b);
int GetFieldC54ArrayValue021573f8(void *self, int v);
int GetCountByType02157108(void *self, int type);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *obj);
void *GetPtrField0x2a04_02010828(GameState *gameState);
int FindKeyIndex020a0af4(struct S_a0af4 *s, int key);
int CheckFlagOrThreshold_02161b48(char *self, int v);
void ResetAllocatorsAndClearFields0215b428(unsigned char *obj);
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
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215c614(self);
        *(int *) (self + 0x1bc0) += 1;
    } else if (state == 1) {
        *(short *) (self + 0x1bf0) = -1;
        *(unsigned int *) (self + 0x247c) |= 4;
        short old = CUR;
        CUR       = GetActiveScaledSum0205d794((struct Struct_0205c570 *) OBJ);
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
            SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) OBJ, SEL >= 0 ? 1 : 0, 5);
        }
        SetElementFieldC2_0205deb4((struct Struct_0205d81c *) OBJ, 5, 1);
        if (TestFlagMask_02012430(&data_02114e30, 0x40)) {
            return;
        }
        if (TestFlagMask_02012430(&data_02114e30, 0x80)) {
            return;
        }
        if ((TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 4) || func_0205df38(OBJ, 0x28)) && CUR == LAST) {
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
        int t  = TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x601);
        int u  = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)OBJ, 0x14);
        int ok = (t | u) ? 1 : 0;
        if (ok || pick) {
            *(unsigned char *) (self + 0x1c21) = GetField0x3acValue_020100a8(GameState::GetInstance());
            TeardownAndResetState020d7aa0(GetGlobalResetObj020d7a50());
            *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
            *(unsigned int *) (self + 0x247c) &= ~4;
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 1, 0);
            if (CUR == LAST + 1) {
                if (LAST != 1) {
                    *(int *) (self + 0x1bb8) = 0xb;
                } else {
                    *(unsigned char *) (self + 0x1c32) = 0;
                    SetElementFieldC2_0205deb4((struct Struct_0205d81c *) OBJ, 4, 1);
                    *(short *) (self + 0x1bf0) = *(unsigned char *) (self + 0x2521) = 1;
                    SEL                                = GetFieldC54ArrayValue021573f8(self, 1);
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
            if (!GetCountByType02157108(self, SEL)) {
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
            unsigned char *q = GetFieldAt0x150_02053c6c((unsigned char *) hero);
            *(short *) (self + 0x1be8) =
                FindKeyIndex020a0af4((struct S_a0af4 *) GetPtrField0x2a04_02010828(gs), *(short *) (q + 0x958));
            if (*(short *) (self + 0x1be8) == -1) {
                *(short *) (self + 0x1be8) = 0;
            }
        } else if (CheckFlagOrThreshold_02161b48(self, 1)) {
            ResetAllocatorsAndClearFields0215b428((unsigned char *) self);
            SEL                                = -1;
            CUR                                = -1;
            *(unsigned char *) (self + 0x2521) = 0;
            func_ov002_02156e90(self);
        }
    }
}
