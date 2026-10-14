#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156050
ARM int IsFlag0x14Bit0x80000Set_ov000_02156050(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 0) & 0x80000) != 0;
}
