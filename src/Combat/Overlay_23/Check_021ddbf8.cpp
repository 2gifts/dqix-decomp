#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0_0200fb8c(int* obj);
struct GameResources;
int IsSubBrightnessTransitionActive(GameResources*);
int IsMainBrightnessTransitionActive(GameResources*);

struct Obj021ddbf8 { char pad[
#if defined(jpn)
0x6f8
#else
0x77c
#endif
]; signed char f77c; };

// USA: func_ov023_021ddbf8
ARM int Check_021ddbf8(Obj021ddbf8* arg) {
    int* p = (int*)GetWord0x0_0200fb8c((int*)GameState::GetInstance());
    int r;
    if (arg->f77c == 1) {
        r = IsSubBrightnessTransitionActive((GameResources*)p);
    } else {
        r = IsMainBrightnessTransitionActive((GameResources*)p);
    }
    return r != 0;
}
