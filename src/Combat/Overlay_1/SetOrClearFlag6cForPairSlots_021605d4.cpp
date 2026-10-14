#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_021605d4  (semantic: SetOrClearFlag6cForPairSlots_021605d4)
extern "C" ARM int func_ov001_021605d4(void* self) {
    int id1 = func_ov017_021d60f4(self);
    int flag = func_ov017_021d60f4((char*)self + 0x8);
    GameState* battle = GameState::GetInstance();
    int base = id1 * 0xc;
    GameObject* c1 = battle->GetGameObjectByIndex(base + 0x1c);
    if (c1 != NULL && *(short*)((char*)c1 + 2) >= 0) {
        if (flag != 0) {
            ((Object3D*)c1)->MakeVisible();
        } else {
            ((Object3D*)c1)->MakeHidden();
        }
    }
    GameObject* c2 = battle->GetGameObjectByIndex(base + 0x1d);
    if (c2 != NULL && *(short*)((char*)c2 + 2) >= 0) {
        if (flag != 0) {
            ((Object3D*)c2)->MakeVisible();
        } else {
            ((Object3D*)c2)->MakeHidden();
        }
    }
    return 1;
}
