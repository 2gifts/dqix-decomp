#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define RATIO_A 0x5ab4
#define RATIO_B 0x5abc
#define RATIO_C 0x5abe
#else
#define RATIO_A 0x58c4
#define RATIO_B 0x58cc
#define RATIO_C 0x58ce
#endif

// JPN: func_ov023_021f3b5c
// USA: func_ov023_021f44d0  (semantic: ComputeScaleRatio_021f44d0)
extern "C" ARM int func_ov023_021f44d0(void* obj) {
    GameState::GetInstance();
    unsigned int a = *(unsigned int*)((char*)obj + RATIO_A);
    unsigned short b = *(unsigned short*)((char*)obj + RATIO_B);
    unsigned short c = *(unsigned short*)((char*)obj + RATIO_C);
    float fa = (float)a;
    float fb = (float)b;
    float fc = (float)c;
    float result = fa * (fc / fb);
    if (0.0f < result) {
        if (result < 1.0f) {
            result = 1.0f;
        }
    }
    return (int)result;
}
