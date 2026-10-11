#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct FlagObj_021da9b0;
int IsFlagBit8Set_021da9b0(struct FlagObj_021da9b0* obj);
unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);

struct Ctx_021e9464 { char pad[0x10]; int unused; };

// USA: func_ov024_021e9464
ARM int SelectResultCode_021e9464(struct Ctx_021e9464* ctx, int id, int mode) {
    GameObject* c = GetCombatantByID(ctx->unused, id);
    if (!c) return 0;
    int flagSet = IsFlagBit8Set_021da9b0((struct FlagObj_021da9b0*)c);
    if (mode != 0) {
        return flagSet ? 0x6e : 0x1e;
    }
    if (flagSet) return 0x6f;
#if defined(jpn)
    return 0x1b;
#else
    return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
#endif
}
