#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);

struct Battle_021e95d4 {
    char pad[0x8e95];
    unsigned char flag8e95;
};

struct Ctx_021e95d4 {
    char pad[0x10];
    Battle_021e95d4* battle;
};

struct Params_021e95d4 {
    char pad[0x24];
    unsigned int low24 : 10;
    unsigned int rangeFirst24 : 10;
    unsigned int rangeSecond24 : 10;
    unsigned int high24 : 2;
};

// JPN: func_ov024_021e9dd0
// USA: func_ov024_021e95d4
extern "C" ARM int func_ov024_021e95d4(Ctx_021e95d4* ctx, int id,
    Params_021e95d4* params, int mode, signed char adjustment,
    unsigned char changed, unsigned char flag) {
    GameObject* combatant = GetCombatantByID((int)ctx->battle, id);
    if (!combatant) return 0;
    if (changed != 0) {
        if (mode == 0) {
            switch (adjustment) {
                case 2: return 0x3a;
                case 0: return 0x3e;
                default: return 0x3c;
            }
        }
        switch (adjustment) {
            case -2: return 0x3b;
            case 0: return 0x3e;
            default: return 0x3d;
        }
    }
    if (mode == 1) {
        if (flag != 0) return 0x1f;
        if (ctx->battle->flag8e95 != 0 ||
            (int)((unsigned char*)combatant->currentStats_)[0x50] <= 0) {
#if defined(jpn)
            return 0x1b;
#else
            return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
#endif

        }
    }
    return SelectByIndexRange0to3_021da644(id,
        params->rangeFirst24, params->rangeSecond24);
}
