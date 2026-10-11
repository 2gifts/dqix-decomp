#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);

struct Ctx_021e96e4 {
    char pad[0x10];
    void* field10;
};

struct Params_021e96e4 {
    char pad[0x24];
    unsigned int reserved : 10;
    unsigned int codeA : 10;
    unsigned int codeB : 10;
    unsigned int reserved2 : 2;
};

// JPN: func_ov024_021e9ed0
// USA: func_ov024_021e96e4
extern "C" ARM int func_ov024_021e96e4(Ctx_021e96e4* ctx, int id,
    Params_021e96e4* params, int mode, signed char result,
    unsigned char resultFlag, unsigned char specialFlag) {
    GameObject* combatant = GetCombatantByID((int)ctx->field10, id);
    if (!combatant) return 0;
    if (resultFlag != 0) {
        if (mode == 0) {
            switch (result) {
                case 2: return 0x4c;
                case 0: return 0x50;
                default: return 0x4e;
            }
        }
        switch (result) {
            case -2: return 0x4d;
            case 0: return 0x50;
            default: return 0x4f;
        }
    }
    if (mode == 1) {
        if (specialFlag != 0) return 0x1f;
        if (((unsigned char*)ctx->field10)[0x8e95] != 0 ||
            (int)((unsigned char*)combatant->currentStats_)[0x51] <= 0) {
#if defined(jpn)
            return 0x1b;
#else
            return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
#endif

        }
    }
    return SelectByIndexRange0to3_021da644(id,
        params->codeA, params->codeB);
}
