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

struct Cbt_021eda78* GetCombatantByID(int, int);
struct GameObject;
int IsCombatantFlagMask512_021eda60(GameObject*);
int IsCombatantFlagMask134217728_021edbc0(GameObject*);
int IsCombatantFlagMask268435456_021edbd8(GameObject*);
int IsCombatantFlagMask536870912_021edbf0(GameObject*);
struct S_flag4000000;
int IsFlagBit67108864Set_021edc08(S_flag4000000*);
struct S_flag100000;
int IsFlagBit1048576Set_021edc20(S_flag100000*);
struct S_flag200000;
int IsFlagBit2097152Set_021edc38(S_flag200000*);
struct FlagObj_021e47dc;
int IsFlagBit22Set_021e47dc(FlagObj_021e47dc*);
struct S_flag40000000;
int IsFlagBit1073741824Set_021edc50(S_flag40000000*);
struct S_flag80000000;
int IsFlagBit2147483648Set_021edc68(S_flag80000000*);
struct S_state21_021edc80;
int IsState4_021edc80(S_state21_021edc80*);
struct S_state21_021edca4;
int IsState5_021edca4(S_state21_021edca4*);

static inline int IsRank1(struct Cbt_021eda78* c) {
    return c->stats->rank21 == 1;
}

static inline int IsRank2(struct Cbt_021eda78* c) {
    return c->stats->rank21 == 2;
}

// USA: func_ov024_021eda78
extern "C" ARM int func_ov024_021eda78(struct Ctx_021eda78* ctx, int id) {
    struct Cbt_021eda78* c = GetCombatantByID((int)ctx->battle, id);
    if (!c) {
        return 0;
    }
    if (IsCombatantFlagMask512_021eda60((GameObject*)c)) {
        return 1;
    }
    if (IsCombatantFlagMask134217728_021edbc0((GameObject*)c)) {
        return 1;
    }
    if (IsRank1(c)) {
        return 1;
    }
    if (IsRank2(c)) {
        return 1;
    }
    if (IsCombatantFlagMask268435456_021edbd8((GameObject*)c)) {
        return 1;
    }
    if (IsCombatantFlagMask536870912_021edbf0((GameObject*)c)) {
        return 1;
    }
    if (IsFlagBit67108864Set_021edc08((S_flag4000000*)c)) {
        return 1;
    }
    if (IsFlagBit1048576Set_021edc20((S_flag100000*)c)) {
        return 1;
    }
    if (IsFlagBit2097152Set_021edc38((S_flag200000*)c)) {
        return 1;
    }
    if (IsFlagBit22Set_021e47dc((FlagObj_021e47dc*)c)) {
        return 1;
    }
    if (IsFlagBit1073741824Set_021edc50((S_flag40000000*)c)) {
        return 1;
    }
    if (IsFlagBit2147483648Set_021edc68((S_flag80000000*)c)) {
        return 1;
    }
    if (IsState4_021edc80((S_state21_021edc80*)c)) {
        return 1;
    }
    if (IsState5_021edca4((S_state21_021edca4*)c)) {
        return 1;
    }
    return IsFlagBit1048576Set_021edc20((S_flag100000*)c);
}
