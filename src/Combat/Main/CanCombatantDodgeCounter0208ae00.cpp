#include <globaldefs.h>
#include "GameState/GameState.h"

unsigned int GetBitsInField4_0203b4fc(unsigned int* obj, unsigned int mask);
unsigned char GetByte0x26c_02039d7c(char* obj);

// USA: func_0208ae00
ARM int CanCombatantDodgeCounter0208ae00(char* obj, int combatantId) {
    unsigned int* v5 = ((unsigned int*)func_ov017_0218b5b0());
    GameState* battle = GameState::GetInstance();
    GameObject* c1 = GetCombatantWithFlag0x100_0200ff1c(battle, combatantId);
    GameObject* c2 = GetCombatantWithFlag0x100_0200ff1c(battle, combatantId);
    if (c1 == NULL || (**(int**)((char*)c1 + 0x130) & 1)) {
        return 0;
    }
    int* p2 = *(int**)((char*)c2 + 0x130);
    if (!(*p2 & 2)) {
        return 0;
    }
    if (GetBitsInField4_0203b4fc(v5, 0x10) != 0) {
        return 0;
    }
    if (*(int*)(obj + 0x1c) != 0) {
        return 0;
    }
    GameObject* c3 = battle->GetUnknownGameObject();
    if (*(short*)((char*)c3 + 0xb2) == 0) {
        return 0;
    }
    return GetByte0x26c_02039d7c((char*)c3) == 0 ? 1 : 0;
}
