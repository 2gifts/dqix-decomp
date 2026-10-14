#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
void* GetWord0x0(int*);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);

// USA: func_ov001_0215b408
ARM int UpdateCounterFromBattleWord_0215b408(void* self, int mode) {
    int frames = func_ov017_021d60f4(self);
    if (mode >= 2) {
        func_ov017_021d60f4((char*)self + 0x8);
    }
    void* battle = GameState::GetInstance();
    void* obj = GetWord0x0((int*)battle);
    if (obj != NULL) {
        SetSubBrightness((GameResources*)obj, 0, frames);
        func_ov017_0218b5b0();
    }
    return 1;
}
