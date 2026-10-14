#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"
struct ArrayContainsByteStruct;
int ArrayContainsByte(ArrayContainsByteStruct*, int);
extern "C" GameResources* func_ov017_0218b5b0();
extern "C" void func_ov017_02191108(GameResources*, int, int, int, int);

// USA: func_02048150
extern "C" ARM void func_02048150(GameObject* object, int hp, int notify) {
    GameState* state = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    ArrayContainsByteStruct* list = (ArrayContainsByteStruct*)GetPtrField0x2a04(state);
    CombatantStatus* runtime = object->combatFields_.savedState_130_;
    int hadFlag = 0;
    if (runtime->flags & 1) hadFlag = 1;
    int maxHP = object->baseStats_->primaryStats.maxHP;
    if (hp > 0) {
        if (hp > maxHP) hp = maxHP;
        runtime->hp = hp;
    } else if (runtime->hp == 0) runtime->hp = maxHP;
    int keepFlag = 0;
    CombatantStatus* current = object->combatFields_.savedState_130_;
    if (current->flags & 4) keepFlag = 1;
    current->flags = 0;
    if (keepFlag) object->combatFields_.savedState_130_->flags |= 4;
    if (hadFlag && ArrayContainsByte(list, object->obj3D_.unknown_4_) && notify)
        func_ov017_02191108(resources, 1, 1, 1, 1);
}
