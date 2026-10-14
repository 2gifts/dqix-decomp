#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"

// USA: func_02053fe4
ARM void ClearFieldBit02053fe4(GameObject* object, int hp, int notify) {
    func_02048150(object, hp, notify);
    CombatantRecovery* combatant = (CombatantRecovery*)object;
    combatant->recoveryFlags &= ~1U;
}
