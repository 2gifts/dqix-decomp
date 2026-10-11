#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0(int* obj);
extern "C" int _Z16SetSubBrightnessP13GameResourcesii(int, int, int);
extern "C" int _Z17SetMainBrightnessP13GameResourcesii(int, int, int);

// USA: func_ov023_021ddbb8
ARM int DispatchByMode77c_021ddbb8(void* obj, int a, int b) {
    int w = GetWord0x0((int*)GameState::GetInstance());
    signed char sb = *(signed char*)((char*)obj
#if defined(jpn)
        + 0x6f8
#else
        + 0x77c
#endif
);
    if (sb == 1) {
        return _Z16SetSubBrightnessP13GameResourcesii(w, a, b);
    }
    return _Z17SetMainBrightnessP13GameResourcesii(w, a, b);
}
