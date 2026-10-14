#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156c94
ARM int IsFlag0x18Bit0x8Set_ov000_02156c94(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x8) != 0;
}
