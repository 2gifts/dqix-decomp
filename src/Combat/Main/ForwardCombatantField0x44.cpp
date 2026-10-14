#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_02094b9c(void* self, void* data);

struct Field0x44_02094b5c { unsigned int v[3]; };

// USA: func_02094b5c
ARM void ForwardCombatantField0x44_02094b5c(void* self, int combatantId) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetGameObjectByIndex(combatantId);
    struct Field0x44_02094b5c buf = *(struct Field0x44_02094b5c*)((char*)c + 0x44);
    func_02094b9c(self, &buf);
}
