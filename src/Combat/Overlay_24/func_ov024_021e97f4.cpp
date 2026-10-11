#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);

struct Context_021e97f4 {
    char pad[0x10];
    void* field10;
};

struct PackedParameters_021e97f4 {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int reserved : 2;
};

struct Parameters_021e97f4 {
    char pad[0x24];
    PackedParameters_021e97f4 packedParameterWord24;
};

struct BattleStateView_021e97f4 {
    char pad[0x8e95];
    unsigned char byte8e95;
};

static inline int ReadStatsByte52_021e97f4(ModifiableCombatStats* stats) {
    return ((unsigned char*)stats)[0x52];
}

// JPN: func_ov024_021e9fd0
// USA: func_ov024_021e97f4
extern "C" ARM int func_ov024_021e97f4(Context_021e97f4* ctx, int id,
    Parameters_021e97f4* parameters, int flag, signed char value,
    unsigned char useValue, unsigned char special) {
    GameObject* combatant = GetCombatantByID((int)ctx->field10, id);
    if (!combatant) return 0;

    if (useValue != 0) {
        if (flag == 0) {
            switch (value) {
                case 2: return 0xab;
                case 0: return 0xae;
                default: return 0xac;
            }
        }
        switch (value) {
            case -2: return 0xaf;
            case 0: return 0xae;
            default: return 0xad;
        }
    }
    if (flag == 1) {
        if (special != 0) return 0x1f;
        if (((BattleStateView_021e97f4*)ctx->field10)->byte8e95 != 0 ||
            ReadStatsByte52_021e97f4(combatant->currentStats_) <= 0) {
#if defined(jpn)
            return 0x1b;
#else
            return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
#endif

        }
    }
    return SelectByIndexRange0to3_021da644(id,
        parameters->packedParameterWord24.second,
        parameters->packedParameterWord24.third);
}
