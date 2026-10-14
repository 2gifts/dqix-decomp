#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02157cc4
ARM int IsFlag0x14Bit0x800000Set_ov000_02157cc4(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 0) & 0x800000) != 0;
}
