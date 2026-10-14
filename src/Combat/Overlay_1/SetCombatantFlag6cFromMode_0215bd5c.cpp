#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_0215bd5c
ARM int SetCombatantFlag6cFromMode_0215bd5c(void* self, int mode) {
    void* battle = GameState::GetInstance();
    if (battle == NULL) return 0;
    int flag = 1;
    int id = func_ov017_021d60f4(self);
    if (mode >= 2) {
        flag = func_ov017_021d60f4((char*)self + 0x8);
    }
    void* combatant = ((GameState*)battle)->GetGameObjectByIndex(id);
    if (combatant == NULL) return 0;
    if (flag != 0) {
        ((Object3D*)combatant)->MakeVisible();
    } else {
        ((Object3D*)combatant)->MakeHidden();
    }
    return 1;
}
