#include <globaldefs.h>

struct Stats_021eda78 {
    char pad0[0x21];
    unsigned char rank21;
};

struct Cbt_021eda78 {
    char pad0[0x138];
    struct Stats_021eda78* stats;
};

struct Battle_021eda78;

struct Ctx_021eda78 {
    struct Battle_021eda78* battle;
};

extern "C" struct Cbt_021eda78* _Z16GetCombatantByIDii(struct Battle_021eda78* battle, int id);
extern "C" int _Z31IsCombatantFlagMask512_021eda60P10GameObject(struct Cbt_021eda78* c);
extern "C" int _Z37IsCombatantFlagMask134217728_021edbc0P10GameObject(struct Cbt_021eda78* c);
extern "C" int _Z37IsCombatantFlagMask268435456_021edbd8P10GameObject(struct Cbt_021eda78* c);
extern "C" int _Z37IsCombatantFlagMask536870912_021edbf0P10GameObject(struct Cbt_021eda78* c);
extern "C" int _Z29IsFlagBit67108864Set_021edc08P13S_flag4000000(struct Cbt_021eda78* c);
extern "C" int _Z28IsFlagBit1048576Set_021edc20P12S_flag100000(struct Cbt_021eda78* c);
extern "C" int _Z28IsFlagBit2097152Set_021edc38P12S_flag200000(struct Cbt_021eda78* c);
extern "C" int _Z23IsFlagBit22Set_021e47dcP16FlagObj_021e47dc(struct Cbt_021eda78* c);
extern "C" int _Z31IsFlagBit1073741824Set_021edc50P14S_flag40000000(struct Cbt_021eda78* c);
extern "C" int _Z31IsFlagBit2147483648Set_021edc68P14S_flag80000000(struct Cbt_021eda78* c);
extern "C" int _Z17IsState4_021edc80P18S_state21_021edc80(struct Cbt_021eda78* c);
extern "C" int _Z17IsState5_021edca4P18S_state21_021edca4(struct Cbt_021eda78* c);

static inline int IsRank1(struct Cbt_021eda78* c) {
    return c->stats->rank21 == 1;
}

static inline int IsRank2(struct Cbt_021eda78* c) {
    return c->stats->rank21 == 2;
}

// JPN: func_ov024_021ee244
// USA: func_ov024_021eda78
extern "C" ARM int func_ov024_021eda78(struct Ctx_021eda78* ctx, int id) {
    struct Cbt_021eda78* c = _Z16GetCombatantByIDii(ctx->battle, id);
    if (!c) {
        return 0;
    }
    if (_Z31IsCombatantFlagMask512_021eda60P10GameObject(c)) {
        return 1;
    }
    if (_Z37IsCombatantFlagMask134217728_021edbc0P10GameObject(c)) {
        return 1;
    }
    if (IsRank1(c)) {
        return 1;
    }
    if (IsRank2(c)) {
        return 1;
    }
    if (_Z37IsCombatantFlagMask268435456_021edbd8P10GameObject(c)) {
        return 1;
    }
    if (_Z37IsCombatantFlagMask536870912_021edbf0P10GameObject(c)) {
        return 1;
    }
    if (_Z29IsFlagBit67108864Set_021edc08P13S_flag4000000(c)) {
        return 1;
    }
    if (_Z28IsFlagBit1048576Set_021edc20P12S_flag100000(c)) {
        return 1;
    }
    if (_Z28IsFlagBit2097152Set_021edc38P12S_flag200000(c)) {
        return 1;
    }
    if (_Z23IsFlagBit22Set_021e47dcP16FlagObj_021e47dc(c)) {
        return 1;
    }
    if (_Z31IsFlagBit1073741824Set_021edc50P14S_flag40000000(c)) {
        return 1;
    }
    if (_Z31IsFlagBit2147483648Set_021edc68P14S_flag80000000(c)) {
        return 1;
    }
    if (_Z17IsState4_021edc80P18S_state21_021edc80(c)) {
        return 1;
    }
    if (_Z17IsState5_021edca4P18S_state21_021edca4(c)) {
        return 1;
    }
    return _Z28IsFlagBit1048576Set_021edc20P12S_flag100000(c);
}
