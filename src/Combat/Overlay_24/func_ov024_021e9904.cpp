#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Ctx_021e9904 { char pad[0x10]; void* field0x10; };

// USA: func_ov024_021e9904
extern "C" ARM int func_ov024_021e9904(struct Ctx_021e9904* ctx, int id, int a2, int flag, signed char v) {
    GameObject* c = GetCombatantByID((int)ctx->field0x10, id);
    if (!c) return 0;
    if (flag == 0) {
        switch (v) {
            case 2: return 0xd0;
            case 0: return 0x1b7;
            default: return 0xd1;
        }
    }
    switch (v) {
        case -2: return 0x1b6;
        case 0: return 0x1b7;
        default: return 0x1b5;
    }
}
