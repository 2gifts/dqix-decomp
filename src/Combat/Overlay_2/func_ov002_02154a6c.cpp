#include "GameState/GameState.h"
#include "World/Object3D.h"
#include <globaldefs.h>

GameObject *GetCombatantWithFlag0x100(GameState *gameState, int combatantId);

// USA: func_ov002_02154a6c
extern "C" ARM int func_ov002_02154a6c(void *self, int idA, int idB) {
    GameState *gs = GameState::GetInstance();
    GameObject *a = GetCombatantWithFlag0x100(gs, idA);
    if (a == NULL) return 0;
    GameObject *b = GetCombatantWithFlag0x100(gs, idB);
    if (b == NULL) return 0;

    if (a->obj3D_.GetField06() == b->obj3D_.GetField06()) return 1;

    if ((a->obj3D_.GetField06() == 10000 && b->obj3D_.GetField06() == 5900) ||
        (a->obj3D_.GetField06() == 5900 && b->obj3D_.GetField06() == 10000))
    {
        return 1;
    }

    if ((a->obj3D_.GetField06() == 10100 && b->obj3D_.GetField06() == 6401) ||
        (a->obj3D_.GetField06() == 6401 && b->obj3D_.GetField06() == 10100))
    {
        return 1;
    }

    return 0;
}
