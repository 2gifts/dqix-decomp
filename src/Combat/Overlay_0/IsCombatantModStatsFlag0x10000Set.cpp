#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021599ac
ARM int IsCombatantModStatsFlag0x10000Set_ov000_021599ac(GameObject* c) {
    return (*(int*)((char*)c->currentStats_ + 0x14) & 0x10000) != 0;
}
