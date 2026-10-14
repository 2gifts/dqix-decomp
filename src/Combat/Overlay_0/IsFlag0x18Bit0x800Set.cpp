#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156af0
ARM int IsFlag0x18Bit0x800Set_ov000_02156af0(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x800) != 0;
}
