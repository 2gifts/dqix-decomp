#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>

struct Outer020e28dc;
struct Obj020e25e8;
struct FlagWord02046708;
struct FlagWord020466f4;

int GetWord0x0_0200fb8c(int *);
char *GetGlobalField0x1c020421a0();
void ReinitController02043204(char *);
int GetInnerFlagBit0020e28dc(struct Outer020e28dc *);
void ResetSelectionState020e25e8(struct Obj020e25e8 *);
void SetSubBrightness(GameResources *, int, int);
int IsSubBrightnessTransitionActive(GameResources *);
extern "C" void func_ov023_021dca88(char *);
void SetCombatModeFromCase020dc2d0(int);
extern "C" void func_ov023_021e7340(char *);
void InitFlags_021eb414(char *);
extern "C" void func_ov023_021eb26c(char *);
extern "C" void func_ov013_02186fa0(char *);
extern "C" void func_ov013_021846a0(char *);
void *GetDataPtr02114e04_020d6c00();
int TestFlags02046708(struct FlagWord02046708 *, unsigned int);
void ClearFlags020466f4(struct FlagWord020466f4 *, unsigned int);
void PopStack1AndTrigger_020a1f4c(int);

#define S32(o) (*(int *) (self + (o)))

// USA: func_ov002_0216c654
extern "C" ARM void func_ov002_0216c654(char *self) {
    GameResources *res = (GameResources *) GetWord0x0_0200fb8c((int *) GameState::GetInstance());
    int state          = S32(0x1bc0);
    if (state == 0) {
        ReinitController02043204(GetGlobalField0x1c020421a0());
        if (S32(4) != 0 && GetInnerFlagBit0020e28dc((struct Outer020e28dc *) S32(4))) {
            ResetSelectionState020e25e8((struct Obj020e25e8 *) S32(4));
        }
        *(short *) (self + 0x1c14) = 0;
        if ((S32(0x247c) & 1) || *(unsigned char *) (self + 0x1cc3) != 0 || *(unsigned char *) (self + 0x2472) != 0) {
            SetSubBrightness(res, -16, 0);
        }
        S32(0x1bc0) = 1;
    } else if (state == 1) {
        if (S32(0x247c) & 1) {
            func_ov023_021dca88(self + 0x50);
        }
        if (*(unsigned char *) (self + 0x1cc3) != 0 || *(unsigned char *) (self + 0x2472) != 0 ||
            *(unsigned char *) (self + 0x2456) != 0)
        {
            SetSubBrightness(res, -16, 0);
            if (*(unsigned char *) (self + 0x1cc3) != 0) S32(0x1bc0) = 2;
            if (*(unsigned char *) (self + 0x2472) != 0) S32(0x1bc0) = 3;
            if (*(unsigned char *) (self + 0x2456) != 0) S32(0x1bc0) = 6;
        } else {
            S32(0x1bc0) = 7;
        }
    } else if (state == 2) {
        if (IsSubBrightnessTransitionActive(res)) return;
        SetCombatModeFromCase020dc2d0(0);
        func_ov023_021e7340(self + 0xb4 + 0x800);
        *(unsigned char *) (self + 0x1cc3) = 0;
        S32(0x1bc0)                        = 7;
    } else if (state == 3) {
        if (IsSubBrightnessTransitionActive(res)) return;
        S32(0x1bc0) = 5;
        if (S32(0x2468) == 0) return;
        InitFlags_021eb414((char *) S32(0x2468));
        S32(0x1bc0) = 4;
    } else if (state == 4) {
        if (*(unsigned short *) (S32(0x2468) + 0x400 + 0x38) & 4) {
            S32(0x1bc0) = 5;
        }
    } else if (state == 5) {
        if (S32(0x2468) != 0) {
            func_ov023_021eb26c((char *) S32(0x2468));
            ((SafeAllocator *) (self + 0x28 + 0x800))->Reset();
            ((SafeAllocator *) (self + 0x64 + 0x800))->Reset();
            S32(0x2468) = 0;
            S32(0x246c) = 0;
        }
        *(unsigned char *) (self + 0x2470) = 0;
        *(unsigned char *) (self + 0x2471) = 0;
        S32(0x1bc0)                        = 7;
    } else if (state == 6) {
        if (IsSubBrightnessTransitionActive(res)) return;
        func_ov013_02186fa0(self + 0x104 + 0x1c00);
        ((SafeAllocator *) (self + 0x850))->Reset();
        func_ov013_021846a0(self + 0xd70 + 0x1000);
        S32(0x1bc0) = 7;
    } else if (state == 7) {
        void *flags = GetDataPtr02114e04_020d6c00();
        if (TestFlags02046708((struct FlagWord02046708 *) flags, 1) ||
            !IsSubBrightnessTransitionActive(res))
        {
            ClearFlags020466f4((struct FlagWord020466f4 *) flags, 1);
            SetCombatModeFromCase020dc2d0(0);
        }
        if (*(unsigned char *) (self + 0x1c33) != 0) {
            PopStack1AndTrigger_020a1f4c(1);
            *(unsigned char *) (self + 0x1c33) = 0;
        }
        S32(0x1bb8) = 0x2b;
        S32(0x1bc0) = 0;
    }
}
