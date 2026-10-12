#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);

// USA: func_ov000_02153cc0
ARM void MaybeUpdatePacked02153cc0(int unused, int newVal, int* ref) {
    short id = (short)(*(int*)ref);
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(id);
    if (c != NULL && IsFlag10088Set((struct S_10088*)c) == 0 && IsFlag0x18Bit0x2000Set(c) == 0) return;
    *ref = newVal;
}
