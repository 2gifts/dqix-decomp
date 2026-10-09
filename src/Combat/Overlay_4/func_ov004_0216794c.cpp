#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02086aec;
extern "C" short _Z30SumCombatantKeyMatches02086aecP11Obj02086aeci(struct Obj02086aec* obj, int key);

struct TauntThreshold {
    short threshold;
    short value;
};
extern struct TauntThreshold data_ov004_02170010[];

// USA: func_ov004_0216794c
extern "C" ARM void func_ov004_0216794c(short* current, short* matches, short* threshold, char* reached, int* index) {
    *current = *(int*)((char*)GetPtrField0x2a04(GameState::GetInstance()) + 0xf74);
    *matches = _Z30SumCombatantKeyMatches02086aecP11Obj02086aeci((struct Obj02086aec*)GetPtrField0x2a04(GameState::GetInstance()), 0x5617);
    *reached = 0;
    short cur = *current;
    int i;
    for (i = 0; i < 10; i++) {
        if (data_ov004_02170010[i].threshold > cur) {
            goto found;
        }
    }
    i = -1;
found:
    *index = i;
    if (*index >= 0) {
        *threshold = data_ov004_02170010[*index].threshold;
        if (*current + *matches >= *threshold) {
            *reached = 1;
        }
    } else {
        *threshold = 0;
        *reached = 0;
    }
}
