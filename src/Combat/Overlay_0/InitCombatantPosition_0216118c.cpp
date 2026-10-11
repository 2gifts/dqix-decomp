#include <globaldefs.h>
#if defined(jpn)
enum { objectOffset = 0xb94, mirrorOffset = 0x218, positionOffset = 0xc04 };
#else
enum { objectOffset = 0xc18, mirrorOffset = 0x29c, positionOffset = 0xc88 };
#endif
#include "GameState/GameState.h"

extern "C" void func_ov000_021626a0(void* self, int a, int b);
extern "C" void func_ov000_0216d600(void* obj, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
void ApplyVec3Tail(void* obj, int* vec);
void SetPosAndFields0216f1e4(void* obj, int* srcVec3, int a, int b);

struct Vec3_0216118c { int v[3]; };

// USA: func_ov000_0216118c
ARM void InitCombatantPosition_0216118c(void* self, int flag) {
    GameState::GetInstance();
    ((int)func_ov017_0218b5b0());
    func_ov000_021626a0(self, 0x26, 0);
    func_ov000_0216d600((char*)self + objectOffset, 1, 1, 0, 0, 0, 0, 1);
    if (flag == 0) {
        return;
    }
    int* mirrorPtr = *(int**)((char*)self + mirrorOffset);
    if (*(int*)((char*)mirrorPtr + 0x8000 + 0xe20) != 0) {
        return;
    }
    struct Vec3_0216118c temp1 = *(struct Vec3_0216118c*)((char*)self + positionOffset);
    struct Vec3_0216118c temp2 = temp1;
    temp2.v[1] += 0x800;
    temp2.v[2] += 0x3000;
    ApplyVec3Tail((char*)self + objectOffset, temp2.v);
    SetPosAndFields0216f1e4((char*)self + objectOffset, temp1.v, 0xf33, 0);
}
