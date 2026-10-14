#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
int IsFlag10088Set_02010088(struct S_10088* obj);
int IsFlag0x18Bit0x2000Set_ov000_02153c0c(GameObject* combatant);
int IsFlag0x14Bit0x8Set_ov000_02156038(GameObject* combatant);
int CheckFlag0x14Bit0x10Set_020882f8(unsigned char* obj);
int IsFlag0x14Bit0x80000Set_ov000_02156050(GameObject* combatant);
int IsFlag0x14Bit0x20Set_ov000_021543f4(GameObject* combatant);

// USA: func_ov000_02155f9c  (semantic: IsCombatantIneligible_02155f9c)
extern "C" ARM int func_ov000_02155f9c(void* unused, int combatantId, int checkSubFlag) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(combatantId);
    if (c == 0) {
        return 1;
    }
    if (IsFlag10088Set_02010088((struct S_10088*)c) ||
        IsFlag0x18Bit0x2000Set_ov000_02153c0c(c) ||
        IsFlag0x14Bit0x8Set_ov000_02156038(c) ||
        CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)c->currentStats_) ||
        IsFlag0x14Bit0x80000Set_ov000_02156050(c)) {
        return 1;
    }
    if (checkSubFlag != 0 && IsFlag0x14Bit0x20Set_ov000_021543f4(c)) {
        return 1;
    }
    return 0;
}
