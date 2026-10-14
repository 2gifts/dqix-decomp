#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02155154
ARM int IsFlag0x18Bit0x1000Set_ov000_02155154(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x1000) != 0;
}
