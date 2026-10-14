#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
void* GetWord0x0(int*);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void* obj, int value, int frames);

// USA: func_ov001_0215b50c  (semantic: UpdateCounterAndNotify_0215b50c)
extern "C" ARM int func_ov001_0215b50c(void* self, int mode) {
    int value;
    int frames = func_ov017_021d60f4(self);
    value = -16;
    if (mode >= 2) {
        value = func_ov017_021d60f4((char*)self + 0x8);
    }
    void* battle = GameState::GetInstance();
    void* obj = GetWord0x0((int*)battle);
    if (obj != NULL) {
        _Z17SetMainBrightnessP13GameResourcesii(obj, value, frames);
        func_ov017_0218b5b0();
    }
    return 1;
}
