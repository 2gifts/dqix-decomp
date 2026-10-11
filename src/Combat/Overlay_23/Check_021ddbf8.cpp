#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0(int* obj);
extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(int* obj);
extern "C" int _Z32IsMainBrightnessTransitionActiveP13GameResources(int* obj);

struct Obj021ddbf8 { char pad[
#if defined(jpn)
0x6f8
#else
0x77c
#endif
]; signed char f77c; };

// USA: func_ov023_021ddbf8
ARM int Check_021ddbf8(Obj021ddbf8* arg) {
    int* p = (int*)GetWord0x0((int*)GameState::GetInstance());
    int r;
    if (arg->f77c == 1) {
        r = _Z31IsSubBrightnessTransitionActiveP13GameResources(p);
    } else {
        r = _Z32IsMainBrightnessTransitionActiveP13GameResources(p);
    }
    return r != 0;
}
