#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);
int CheckFlag0x2AndState2(struct S88514* obj);
unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);

struct Ctx_021e939c {
    char pad[0x10];
    int field10;
};

// JPN: 021e9be8
// USA: func_ov024_021e939c
ARM int SelectMessageByFlags2_021e939c(struct Ctx_021e939c* ctx, int id, int flag1, int flag2) {
    GameObject* combatant = GetCombatantByID(ctx->field10, id);
    if (combatant == NULL) {
        return 0;
    }
    int state2 = CheckFlag0x2AndState2((struct S88514*)combatant->currentStats_);
    int kind1 = CheckFlag0x2AndKind1((struct Combatant_20885b4*)combatant->currentStats_);
    if (flag1 != 0) {
        if (flag2 != 0) {
            return state2 != 0 ? 0x10c : 0x10a;
        }
        if (state2 != 0) {
            return 0x10b;
        }
        #if defined(jpn)
        return 0x1b;
#else
        return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
#endif
    }
    if (flag2 != 0) {
        return kind1 != 0 ? 0x53 : 0x3f;
    }
    if (state2 != 0) {
        return 0x10b;
    }
    if (kind1 != 0) {
        return 0x52;
    }
    #if defined(jpn)
        return 0x1b;
#else
        return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
#endif
}
