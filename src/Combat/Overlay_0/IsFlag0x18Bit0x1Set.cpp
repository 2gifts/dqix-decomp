#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156258
ARM int IsFlag0x18Bit0x1Set_ov000_02156258(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x1) != 0;
}
