#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0_0200fb8c(int* obj);
int IsSubBrightnessTransitionActive(GameResources*);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);
struct Struct02074bf4;
extern "C" void func_02074e54(struct Struct02074bf4*);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void SetCombatModeFromCase020dc2d0(int);

struct SelfState0215445c {
    char pad0[0x38];
    char pad1[0x58 - 0x38];
    unsigned char f58;
    char pad2[0x5a - 0x59];
    unsigned char f5a;
    unsigned char f5b;
};

// USA: func_ov003_0215445c
ARM void HandleStateTransition_0215445c(struct SelfState0215445c* self) {
    int w = GetWord0x0_0200fb8c((int*)GameState::GetInstance());

    if (self->f58 == 0) {
        self->f5a = 3;
        return;
    }
    if (self->f5b == 0) {
        SetSubBrightness((GameResources*)w, -16, 1);
        self->f5b = self->f5b + 1;
        return;
    }
    if (self->f5b != 1) return;
    if (IsSubBrightnessTransitionActive((GameResources*)w) != 0) return;

    func_02074e54((struct Struct02074bf4*)((char*)self + 0x38));
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 1);
    SetCombatModeFromCase020dc2d0(0);
    self->f5a = 3;
    self->f5b = 0;
}
