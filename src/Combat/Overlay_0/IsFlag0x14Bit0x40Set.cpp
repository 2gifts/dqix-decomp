#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156b20
ARM int IsFlag0x14Bit0x40Set_ov000_02156b20(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 0) & 0x40) != 0;
}
