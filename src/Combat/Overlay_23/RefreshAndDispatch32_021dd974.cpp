#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define REGION(j,u) (j)
#else
#define REGION(j,u) (u)
#endif

struct InfoWindowRefresh021dd974 {
    char beforeFlags[REGION(0x6f0,0x774)];
    unsigned short flags;
    char beforeDisplayState[7];
    signed char displayState;
};

extern "C" void func_ov023_021dfb4c(void* obj);
extern "C" void func_ov023_021ddae4(void* obj);
extern "C" void func_ov023_021dc520(void* obj);
extern "C" void func_ov023_021dd404(void* obj);
int GetWord0x0(int* obj);
int DispatchByMode77c_021ddbb8(void* obj, int a, int b);

// USA: func_ov023_021dd974
ARM void RefreshAndDispatch32_021dd974(void* obj) {
    InfoWindowRefresh021dd974* view = (InfoWindowRefresh021dd974*)obj;
    if (!(view->flags & 0x4000)) {
        func_ov023_021dfb4c(obj);
    }
    func_ov023_021ddae4(obj);

    if (view->displayState >= 0) {
        func_ov023_021dc520(obj);
        func_ov023_021dd404(obj);
    }

    if (!(view->flags & 0x40)) return;

    GetWord0x0((int*)GameState::GetInstance());

    if (!(view->flags & 0x20)) return;

    DispatchByMode77c_021ddbb8(obj, 0, 8);
    view->flags &= ~0x20;
}
