#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021563ec
ARM int IsFlag0x14Bit0x2000000Set_ov000_021563ec(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 0) & 0x2000000) != 0;
}
