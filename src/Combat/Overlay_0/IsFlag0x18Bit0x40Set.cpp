#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156b08
ARM int IsFlag0x18Bit0x40Set_ov000_02156b08(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x40) != 0;
}
