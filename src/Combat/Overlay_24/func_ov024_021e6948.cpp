#include <globaldefs.h>

struct Stats_021e6948 {
    char pad0[0x21];
    unsigned char rank21;
};

struct Cbt_021e6948 {
    char pad0[0x138];
    struct Stats_021e6948* stats;
};

struct Battle_021e6948;

struct Ctx_021e6948 {
    char pad0[0x10];
    struct Battle_021e6948* battle;
};

extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" struct Cbt_021e6948* _Z16GetCombatantByIDii(struct Battle_021e6948* battle, int id);
extern "C" float _Z13LookupTableC0i(int v);
extern "C" int _Z31IsCombatantFlag2Mask32_021e67b0P10GameObject(struct Cbt_021e6948* c);
extern "C" void* _Z17GetPtrField0x2a04P9GameState(void* gs);
extern "C" int _Z17ArrayContainsByteP23ArrayContainsByteStructi(void* arr, int id);
extern "C" void _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(struct Battle_021e6948* battle, int idx);
extern "C" int func_ov000_02156068(struct Battle_021e6948* battle, int id, int kind, int mode);
extern "C" int _Z13NextRandomMaxP6Randomi(struct Battle_021e6948* battle, int max);
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(struct Cbt_021e6948* c);

// JPN: func_ov024_021e71e0
// USA: func_ov024_021e6948
extern "C" ARM int func_ov024_021e6948(struct Ctx_021e6948* ctx, int targetId, int a, int b) {
    float dmg = (float)a * (float)b / 8.0f;
    struct Cbt_021e6948* target = _Z16GetCombatantByIDii(ctx->battle, targetId);
    if (target) {
        if (target->stats->rank21 <= 3) {
            dmg = dmg * _Z13LookupTableC0i((signed char)target->stats->rank21);
        }
        if (_Z31IsCombatantFlag2Mask32_021e67b0P10GameObject(target)) {
            dmg = dmg * _Z13LookupTableC0i(1);
        }
        if (_Z17ArrayContainsByteP23ArrayContainsByteStructi(
                _Z17GetPtrField0x2a04P9GameState(_ZN9GameState11GetInstanceEv()), targetId) &&
            target && target->stats->rank21 == 1) {
            _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(ctx->battle, 0);
        }
    }
    if (dmg > 0 && func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
        dmg = _Z13NextRandomMaxP6Randomi(ctx->battle, 2);
    }
    if (_Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(target)) {
        dmg = 0.5f * dmg;
    }
    return dmg;
}
