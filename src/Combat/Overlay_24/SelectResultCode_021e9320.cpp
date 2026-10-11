#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct FlagObj_021de25c;
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj);
unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);

struct Ctx_021e9320 { char pad[0x10]; int unused; };

// USA: func_ov024_021e9320
ARM int SelectResultCode_021e9320(struct Ctx_021e9320* ctx, int id, int mode) {
    GameObject* c = GetCombatantByID(ctx->unused, id);
    if (!c) return 0;
    int flagSet = IsFlagBit5Set_021de25c((struct FlagObj_021de25c*)c);
    if (mode != 0) {
        if (flagSet) {
            return SelectByIndexRange0to3_021da644(id, 0x83, 0x84);
        }
        return SelectByIndexRange0to3_021da644(id, 0x81, 0x82);
    }
    if (flagSet) return 0x85;
    #if defined(jpn)
        return 0x1b;
#else
        return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
#endif
}
