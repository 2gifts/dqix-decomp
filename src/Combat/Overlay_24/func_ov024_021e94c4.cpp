#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);

struct Ctx_021e94c4 {
    char pad[0x10];
    int field10;
};

struct Parameters_021e94c4 {
    char pad[0x24];
    unsigned int : 10;
    unsigned int firstSelector : 10;
    unsigned int secondSelector : 10;
    unsigned int : 2;
};

// JPN: func_ov024_021e9cd0
// USA: func_ov024_021e94c4
extern "C" ARM int func_ov024_021e94c4(Ctx_021e94c4* ctx, int id,
    Parameters_021e94c4* parameters, int mode, signed char value,
    unsigned char useValue, unsigned char forceDefault) {
    GameObject* combatant = GetCombatantByID(ctx->field10, id);
    if (!combatant) return 0;
    if (useValue != 0) {
        if (mode == 0) {
            switch (value) {
                case 2: return 0x47;
                case 0: return 0x4b;
                default: return 0x49;
            }
        }
        switch (value) {
            case -2: return 0x48;
            case 0: return 0x4b;
            default: return 0x4a;
        }
    }
    if (mode == 1) {
        if (forceDefault != 0) return 0x1f;
        if (*(unsigned char*)(ctx->field10 + 0x8e95) != 0 ||
            (int)*((unsigned char*)combatant->currentStats_ + 0x4f) <= 0) {
#if defined(jpn)
            return 0x1b;
#else
            return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
#endif

        }
    }
    return SelectByIndexRange0to3_021da644(id, parameters->firstSelector, parameters->secondSelector);
}
