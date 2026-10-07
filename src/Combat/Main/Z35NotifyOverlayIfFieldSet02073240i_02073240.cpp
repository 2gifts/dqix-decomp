#include <globaldefs.h>

#include "GameState/GameState.h"

extern "C" void _Z35ApplyCombatantEffectByIndex020730e0ii(int id, int index);
extern "C" int _Z32CallHelperIfCheckPasses_0218fcf8iii(int a, int b, int c);

extern short data_020e8846[];

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02073240
extern "C" ARM void _Z35NotifyOverlayIfField0x9cSet02073240i(int arg0) {
    GameState* gs = GameState::GetInstance();
    GameObject* obj = gs->GetGameObjectByIndex(arg0);
    if (!obj) return;

    short v;
    int i = 0;
    while ((v = data_020e8846[i]) >= 0) {
        _Z35ApplyCombatantEffectByIndex020730e0ii(arg0, v);
        i++;
    }

    if (*(unsigned short*)((char*)obj + 0x9c) == 0) return;

    int x = (int)func_ov017_0218b5b0();
    _Z32CallHelperIfCheckPasses_0218fcf8iii(x, arg0, *(unsigned short*)((char*)obj + 0x9c));
}
