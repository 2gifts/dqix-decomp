#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021543f4
ARM int IsFlag0x14Bit0x20Set_ov000_021543f4(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 0) & 0x20) != 0;
}
