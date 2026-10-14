#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02153a8c
ARM int IsFlag0x18Bit0x200Set_ov000_02153a8c(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x200) != 0;
}
