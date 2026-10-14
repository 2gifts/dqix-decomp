#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156404
ARM int IsFlag0x18Bit0x400Set_ov000_02156404(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x400) != 0;
}
