#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156cac
ARM int IsFlag0x18Bit0x10Set_ov000_02156cac(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x10) != 0;
}
