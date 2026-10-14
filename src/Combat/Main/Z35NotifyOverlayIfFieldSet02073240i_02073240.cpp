#include <globaldefs.h>

#include "GameState/GameState.h"

void ApplyCombatantEffectByIndex020730e0(int id, int index);
int CallHelperIfCheckPasses_0218fcf8(int a, int b, int c);

extern short data_020e8846[];

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02073240
ARM void NotifyOverlayIfField0x9cSet02073240(int arg0) {
    GameState* gs = GameState::GetInstance();
    GameObject* obj = gs->GetGameObjectByIndex(arg0);
    if (!obj) return;

    short v;
    int i = 0;
    while ((v = data_020e8846[i]) >= 0) {
        ApplyCombatantEffectByIndex020730e0(arg0, v);
        i++;
    }

    if (*(unsigned short*)((char*)obj + 0x9c) == 0) return;

    int x = (int)func_ov017_0218b5b0();
    CallHelperIfCheckPasses_0218fcf8(x, arg0, *(unsigned short*)((char*)obj + 0x9c));
}
