#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Stats_021e67c8 {
    char pad0[0x21];
    unsigned char rank21;
    char pad22[0x40 - 0x22];
    unsigned char rate40;
};

struct Cbt_021e67c8 {
    char pad0[0x138];
    struct Stats_021e67c8* stats;
};

struct Ctx_021e67c8 {
    char pad0[0x10];
    void* battle;
};

extern "C" signed char _Z26GetFieldOrFallback02159e60Pvi(void* obj, int mode);
extern "C" struct Cbt_021e67c8* _Z16GetCombatantByIDii(void* battle, int id);
extern "C" float _Z13LookupTableC0i(int v);
extern "C" int _Z31IsCombatantFlag2Mask32_021e67b0P10GameObject(struct Cbt_021e67c8* c);
extern "C" void* _Z17GetPtrField0x2a04P9GameState(void* gs);
extern "C" int _Z17ArrayContainsByteP23ArrayContainsByteStructi(void* arr, int id);
extern "C" void _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(void* battle, int idx);
extern "C" int func_ov000_02156068(void* battle, int id, int kind, int mode);
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(struct Cbt_021e67c8* c);

// USA: func_ov024_021e67c8
extern "C" ARM int func_ov024_021e67c8(struct Ctx_021e67c8* ctx, int mode, int targetId) {
    void* battle = ctx->battle;
    int level = _Z26GetFieldOrFallback02159e60Pvi(battle, mode);
    float rate = (level + 5) * NextRandomFloatBetween((struct Random*)battle, 0.8f, 1.0f);
    if (rate > 100.0f) {
        rate = 100.0f;
    }
    struct Cbt_021e67c8* target = _Z16GetCombatantByIDii(ctx->battle, targetId);
    if (target) {
        rate = rate * (target->stats->rate40 / 100.0f);
    }
    if (target) {
        if (target->stats->rank21 <= 3) {
            rate = rate * _Z13LookupTableC0i((signed char)target->stats->rank21);
        }
        if (_Z31IsCombatantFlag2Mask32_021e67b0P10GameObject(target)) {
            rate = rate * _Z13LookupTableC0i(1);
        }
        if (_Z17ArrayContainsByteP23ArrayContainsByteStructi(
                _Z17GetPtrField0x2a04P9GameState(GameState::GetInstance()), targetId) &&
            target && target->stats->rank21 == 1) {
            _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(ctx->battle, 0);
        }
    }
    if (func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
        rate = NextRandomMax((struct Random*)ctx->battle, 2);
    }
    if (_Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(target)) {
        rate = 0.5f * rate;
    }
    return rate;
}
