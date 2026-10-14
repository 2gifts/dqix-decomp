#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

int CheckFlag0x14Bit0x10Set_020882f8(unsigned char* obj);
unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);

struct Ctx_021e929c {
    char pad[0x10];
    int field10;
};

// USA: func_ov024_021e929c
ARM int SelectMessageByFlags_021e929c(struct Ctx_021e929c* ctx, int id, int flag) {
    GameObject* combatant = GetCombatantByID(ctx->field10, id);
    if (combatant == NULL) {
        return 0;
    }
    int flagSet = CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)combatant->currentStats_);
    if (flag != 0) {
        if (flagSet != 0) {
            return SelectByIndexRange0to3_021da644(id, 0x42, 0x42 + 0x13c);
        }
        return SelectByIndexRange0to3_021da644(id, 0x41, 0x92);
    }
    if (flagSet != 0) {
        return 0x43;
    }
    #if defined(jpn)
        return 0x1b;
#else
        return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
#endif
}
