#include <globaldefs.h>
#include "GameState/GameState.h"

extern int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct Struct020372b8;

struct P021e59b4 {
    char pad[8];
    unsigned char f8;
    unsigned char f9;
    unsigned short fa;
};

// USA: func_ov025_021e59b4
ARM int SetColorForDispatched_021e59b4(struct P021e59b4* obj, int unused, int unused2, void* ctx) {
    GameState* bs = GameState::GetInstance();
    int buf[8];
    int count = DispatchByIndex021820bc(ctx, unused, obj->f8, (int)buf);
    for (int j = 0; j < count; j++) {
        GameObject* combatant = bs->GetGameObjectByIndex(buf[j]);
        if (combatant) {
            ((Object3D*)((struct Struct020372b8*)combatant))->TransitionInheritedAlpha(obj->f9, obj->fa);
        }
    }
    return 1;
}
