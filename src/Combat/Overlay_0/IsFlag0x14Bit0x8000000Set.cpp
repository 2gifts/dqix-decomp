#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_0215516c
ARM int IsFlag0x14Bit0x8000000Set_ov000_0215516c(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 0) & 0x8000000) != 0;
}
