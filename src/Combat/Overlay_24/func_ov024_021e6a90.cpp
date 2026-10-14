#include <globaldefs.h>
#include "GameState/GameState.h"

struct Stats_021e6a90 {
    char pad0[0x14];
    unsigned int flags14;
    unsigned int flags18;
    char pad1c[0x21 - 0x1c];
    unsigned char rank21;
    char pad22[0x24 - 0x22];
    signed char tension24;
    char pad25[0x3e - 0x25];
    unsigned char resist3e;
    unsigned char resist3f;
    unsigned char resist40;
    unsigned char resist41;
    unsigned char resist42;
    unsigned char resist43;
    unsigned char resist44;
    char pad45[0x58 - 0x45];
    int lo58 : 18;
    int decayA : 3;
    int decayB : 3;
    int hi58 : 8;
};

struct Bits2f4_021e6a90 {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int rest : 30;
};

struct Info_021e6a90 {
    char pad0[0x34];
    unsigned short value34;
};

struct Cbt_021e6a90 {
    char pad0[0x134];
    struct Info_021e6a90* info;
    struct Stats_021e6a90* stats;
#if defined(jpn)
    char pad13c[0x144 - 0x13c];
#else
    char pad13c[0x150 - 0x13c];
#endif
    unsigned char* field150;
};

struct Action_021e6a90 {
    unsigned int pad0;
    unsigned int id : 12;
    unsigned int rest4 : 20;
    unsigned int lo8 : 8;
    unsigned int kind : 2;
    unsigned int mid8 : 12;
    unsigned int elem : 5;
    unsigned int hi8 : 5;
    unsigned int padc;
    unsigned int flags10;
    unsigned int pad14;
    unsigned int lo18 : 5;
    unsigned int sub18 : 7;
    unsigned int hi18 : 20;
    unsigned int cap : 14;
    unsigned int hi1c : 18;
    unsigned int pad20[3];
    unsigned int lo2c : 27;
    unsigned int flag2c : 1;
    unsigned int hi2c : 4;
};

struct Hud_021e6a90 {
    char pad0[0xb];
    unsigned char lo : 3;
    unsigned char show : 1;
    unsigned char mid : 1;
    unsigned char level : 3;
};

struct Flags_021e6a90 {
    char pad0[0x1c];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char mid : 3;
    unsigned char bit6 : 1;
    unsigned char crit : 1;
};

struct Battle_021e6a90 {
    char pad0[0x8e38];
    int result8e38;
    char pad8e3c[0x8e83 - 0x8e3c];
    signed char level8e83;
    char pad8e84[0x8e94 - 0x8e84];
    unsigned char flag8e94;
};

struct Ctx_021e6a90 {
    char pad0[4];
    struct Hud_021e6a90* hud;
    char pad8[4];
    struct Flags_021e6a90* flags;
    struct Battle_021e6a90* battle;
    char pad14[0x47 - 0x14];
    unsigned char state47;
    char pad48[0x76 - 0x48];
    unsigned char enabled76;
};

struct Tension_021e6a90 {
    char pad0[0x16c];
    unsigned short values[1];
#if defined(jpn)
    char pad16e[0x8b8 - 0x16e];
#else
    char pad16e[0x950 - 0x16e];
#endif
    int index;
};

struct Cbt_021e6a90* GetCombatantByID(int, int);
struct GameObject;
int IsCombatantFlag2Mask2048_021e7ba8(GameObject*);
struct FlagObj_021da998;
int IsFlagBit8388608Set_021da998(FlagObj_021da998*);
struct FlagObj_021dd260;
int IsFlagBit24Set_021dd260(FlagObj_021dd260*);
float GetClampedRateMultiplier_02074738(int tension, int mode);
extern "C" int func_ov000_02156068(struct Battle_021e6a90* battle, int id, int kind, int mode);
extern "C" struct Tension_021e6a90* func_ov000_02153710(struct Battle_021e6a90* battle, int id);
extern "C" int func_ov000_02159dbc(struct Battle_021e6a90* battle, int id);
float CalculateTensionBonus(int tension, int level);
struct FieldObj_021ea7fc;
int CheckFieldMatch_021ea7fc(void*, FieldObj_021ea7fc*, int);
struct Random;
float ApplyRandomVariance_02074838(int, int, Random*);
extern "C" float func_ov000_02156b38(struct Battle_021e6a90* battle, int id, int elem);
int GetBits23To25At0x2f4_02085748(unsigned char* p);
struct S886b0;
int CheckFlag0x80AndKind1_020886b0(S886b0*);
struct S886f8;
int CheckFlag0x80AndKind2_020886f8(S886f8*);
struct Obj02088740;
int IsFlag0x80SetAndStateEquals3(Obj02088740*);
struct Obj02088788;
int IsFlag0x80SetAndStateEquals4(Obj02088788*);
struct Obj020887d0;
int IsFlag0x80SetAndStateEquals5(Obj020887d0*);
struct Combatant_2088660;
int IsField0x18Flag0x80Set_02088660(Combatant_2088660*);
float GetPackedRateModifierField1_02085968(char*);
float GetScaledBits0To5At0x2fc_02085818(unsigned char* p);
float GetPackedRateModifierField4_02085a10(char*);
struct Actor02085a48;
float GetField0x304ScaleLow(Actor02085a48*);
float GetPackedRateModifierField3_020859d8(char*);
float GetPackedRateModifierField2_020859a0(char*);
float GetPackedRateModifierField0_02085930(char*);
float GetScaledBits6To11At0x2fc_02085850(unsigned char* p);
float GetScaledBits24To29At0x2fc_020858f8(unsigned char* p);
struct Actor02085a80;
float GetField0x304ScaleMid(Actor02085a80*);
float GetScaledBits18To23At0x2fc_020858c0(unsigned char* p);
float GetScaledBits12To17At0x2fc_02085888(unsigned char* p);
float ComputeQuarterDecayFactor020748d0(int v);
float ComputeQuarterDecayFactor_020748a8(int v);
float LookupTableC0_02074938(int v);
int IsCombatantFlag2Mask32_021e67b0(GameObject*);
struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
void IncrementByteCounterCapped0x63_0215a8d4(unsigned char*, int);
int TestBit5At0x2f4_02085154(unsigned char* p);
int TestBit10At0x2f4_020851d8(unsigned char* p);
int NextRandomMax(Random*, int);
int TestBit4At0x2f4_02085128(unsigned char* p);
void ZeroFieldsAt0xe58And0xe82And0x8e52_ov000_0215cd80(void*);

extern signed char data_ov024_021fe798[];
struct Scale4_021e6a90 { float v[4]; };
extern struct Scale4_021e6a90 data_ov024_021fe778;

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021e6a90
extern "C" ARM int func_ov024_021e6a90(struct Ctx_021e6a90* ctx, int attackerId, int targetId,
                                                          struct Action_021e6a90* action, unsigned int base) {
    GameState* gs = GameState::GetInstance();
    struct Cbt_021e6a90* attacker = GetCombatantByID((int)ctx->battle, attackerId);
    struct Cbt_021e6a90* target = GetCombatantByID((int)ctx->battle, targetId);
    int crit;
    if (ctx->flags->crit) {
        crit = 1;
    } else {
        crit = 0;
    }
    float dmg = base;
    float baseF = dmg;

    if (action->id != 0x150 && IsCombatantFlag2Mask2048_021e7ba8((GameObject*)target) &&
        action->kind == 1) {
        ctx->flags->bit6 = 1;
        if ((action->flags10 & 0x2000) &&
            (IsFlagBit8388608Set_021da998((FlagObj_021da998*)attacker) ||
             IsFlagBit24Set_021dd260((FlagObj_021dd260*)attacker))) {
            ctx->state47 = 1;
            if (IsFlagBit24Set_021dd260((FlagObj_021dd260*)attacker)) {
                ctx->state47 = 2;
            }
        }
        return 0;
    }

    if (ctx->enabled76 && (action->flags10 & 0x2000) &&
        (IsFlagBit8388608Set_021da998((FlagObj_021da998*)attacker) ||
         IsFlagBit24Set_021dd260((FlagObj_021dd260*)attacker))) {
        if (base != 0 || (action->id != 0x70 && action->id != 0x48)) {
            float mult;
            if (IsPartyMember(attackerId)) {
                mult = GetClampedRateMultiplier_02074738(attacker->stats->tension24, 0);
            } else {
                mult = GetClampedRateMultiplier_02074738(attacker->stats->tension24, 1);
            }
            dmg = dmg * mult;
            unsigned char ok = 1;
            if (IsPartyMember(attackerId)) {
                if (func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
                    ok = 0;
                }
            }
            if (ok) {
                signed char level;
                if (IsPartyMember(attackerId)) {
                    struct Tension_021e6a90* t = func_ov000_02153710(ctx->battle, attackerId);
                    level = t->values[t->index];
                } else {
                    level = func_ov000_02159dbc(ctx->battle, attackerId);
                }
                dmg = dmg + CalculateTensionBonus(attacker->stats->tension24, level);
            }
        }
        ctx->state47 = 1;
        if (IsFlagBit24Set_021dd260((FlagObj_021dd260*)attacker)) {
            ctx->state47 = 2;
        }
    }

    if (crit && func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
        if (action->flags10 & 0x1000000) {
            dmg = baseF;
        }
    }

    if (CheckFieldMatch_021ea7fc(ctx, (FieldObj_021ea7fc*)action, crit)) {
        unsigned char mode = 0;
        int value = base;
        float floor = 0.0f;
        if (action->id == 1 || action->id == 0xdb || action->id == 0x1f9) {
            value = attacker->info->value34;
            mode = 1;
            floor = base;
            if (IsPartyMember(attackerId)) {
                struct Cbt_021e6a90* p = (struct Cbt_021e6a90*)GetCombatantWithFlag0x100_0200ff1c(gs, attackerId);
                if (p) {
                    struct Bits2f4_021e6a90* w = (struct Bits2f4_021e6a90*)(p->field150 + 0x2f4);
                    if (w && (w->bit1 || w->bit0)) {
                        mode = 0;
                        value = base;
                        floor = 0.0f;
                    }
                }
            }
        }
        dmg = 1.2f * dmg;
        float v = ApplyRandomVariance_02074838((short)value, mode, (Random*)ctx->battle);
        if (dmg < v) {
            dmg = v;
        }
        if (dmg < floor) {
            dmg = floor;
        }
    }

    dmg = dmg * func_ov000_02156b38(ctx->battle, targetId, action->elem);

    int elem = 0;
    signed char* tbl = data_ov024_021fe798;
    struct Cbt_021e6a90* self = (struct Cbt_021e6a90*)GetCombatantWithFlag0x100_0200ff1c(gs, attackerId);
    if (self) {
        for (; *tbl != -1; tbl += 2) {
            if (tbl[1] == GetBits23To25At0x2f4_02085748(self->field150)) {
                elem = tbl[0];
                break;
            }
        }
    }

    int useElem = 0;
    float elemDmg = 0;
    if (IsPartyMember(attackerId) && GetCombatantWithFlag0x100_0200ff1c(gs, attackerId) &&
        (action->flags10 & 0x40000) && elem >= 1 && elem <= 7) {
        elemDmg = dmg * func_ov000_02156b38(ctx->battle, targetId, elem);
        useElem = 1;
    }

    float resist = 0;
    if (target && action->elem == 8 && action->id != 0x1f9 && action->id != 0x205) {
        if (CheckFlag0x80AndKind1_020886b0((S886b0*)attacker->stats)) {
            resist = 1.1f * dmg;
            resist = resist * (target->stats->resist3e / 100.0f);
        } else if (CheckFlag0x80AndKind2_020886f8((S886f8*)attacker->stats)) {
            resist = 1.1f * dmg;
            resist = resist * (target->stats->resist3f / 100.0f);
        } else if (IsFlag0x80SetAndStateEquals3((Obj02088740*)attacker->stats)) {
            struct Stats_021e6a90* ts = target->stats;
            float a = 1.1f * dmg;
            a = a * (ts->resist41 / 100.0f);
            float b = 1.1f * dmg;
            b = b * (ts->resist40 / 100.0f);
            resist = b;
            if (b < a) {
                resist = a;
            }
        } else if (IsFlag0x80SetAndStateEquals4((Obj02088788*)attacker->stats)) {
            struct Stats_021e6a90* ts = target->stats;
            float a = 1.1f * dmg;
            a = a * (ts->resist43 / 100.0f);
            float b = 1.1f * dmg;
            b = b * (ts->resist42 / 100.0f);
            resist = b;
            if (b < a) {
                resist = a;
            }
        } else if (IsFlag0x80SetAndStateEquals5((Obj020887d0*)attacker->stats)) {
            resist = 1.1f * dmg;
            resist = resist * (target->stats->resist44 / 100.0f);
        }
        if (IsField0x18Flag0x80Set_02088660((Combatant_2088660*)attacker->stats)) {
            useElem = 1;
        }
    }

    if (useElem) {
        if (elemDmg <= resist) {
            dmg = resist;
        } else {
            dmg = elemDmg;
        }
    }

    if (IsPartyMember(attackerId)) {
        struct Cbt_021e6a90* p = (struct Cbt_021e6a90*)GetCombatantWithFlag0x100_0200ff1c(gs, attackerId);
        if (p && (action->flags10 & 0x40000)) {
            if (func_ov000_02156068(ctx->battle, targetId, 1, 0)) {
                dmg = dmg * GetPackedRateModifierField1_02085968((char*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 2, 0)) {
                dmg = dmg * GetScaledBits0To5At0x2fc_02085818(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 3, 0)) {
                dmg = dmg * GetPackedRateModifierField4_02085a10((char*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 4, 0)) {
                dmg = dmg * GetField0x304ScaleLow((Actor02085a48*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 5, 0)) {
                dmg = dmg * GetPackedRateModifierField3_020859d8((char*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 6, 0)) {
                dmg = dmg * GetPackedRateModifierField2_020859a0((char*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 7, 0)) {
                dmg = dmg * GetPackedRateModifierField0_02085930((char*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 8, 0)) {
                dmg = dmg * GetScaledBits6To11At0x2fc_02085850(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 9, 0)) {
                dmg = dmg * GetScaledBits24To29At0x2fc_020858f8(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 10, 0)) {
                dmg = dmg * GetField0x304ScaleMid((Actor02085a80*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 11, 0)) {
                dmg = dmg * GetScaledBits18To23At0x2fc_020858c0(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 12, 0)) {
                dmg = dmg * GetScaledBits12To17At0x2fc_02085888(p->field150);
            }
        }
    }

    unsigned char forced;
    if (target) {
        struct Stats_021e6a90* ts = target->stats;
        unsigned int guard = ts->flags18;
        if ((guard & 2) && action->elem == 1) {
            dmg = 0.75f * dmg;
        }
        if ((guard & 4) && action->elem == 2) {
            dmg = 0.75f * dmg;
        }
        if ((ts->flags14 & 0x20000000) && func_ov000_02156068(ctx->battle, attackerId, 8, 0)) {
            dmg = 0.5f * dmg;
        }
        if (action->flags10 & 1) {
            if ((target->stats->flags14 & 0x10000) && action->sub18 != 2) {
                dmg = dmg * ComputeQuarterDecayFactor020748d0((signed char)target->stats->decayA);
            }
        }
        if ((action->flags10 & 4) && (target->stats->flags14 & 0x20000)) {
            dmg = dmg * ComputeQuarterDecayFactor_020748a8((signed char)target->stats->decayB);
        }
        if ((action->flags10 & 0x10) && target && ctx->battle->flag8e94 == 0) {
            if (target->stats->rank21 <= 3) {
                dmg = dmg * LookupTableC0_02074938((signed char)target->stats->rank21);
            }
            if (IsCombatantFlag2Mask32_021e67b0((GameObject*)target)) {
                dmg = dmg * LookupTableC0_02074938(1);
            }
            if (ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)(GetPtrField0x2a04_02010828(GameState::GetInstance())), targetId) &&
                target && target->stats->rank21 == 1) {
                IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)ctx->battle, 0);
            }
        }
    }

    if (action->id == 0x82 && target->stats->rank21 != 3) {
        dmg = 1.0f;
    }

    forced = 0;
    if (IsPartyMember(attackerId)) {
        struct Cbt_021e6a90* p = (struct Cbt_021e6a90*)GetCombatantWithFlag0x100_0200ff1c(gs, attackerId);
        if (p) {
            if (action->flags10 & 0x80000) {
                if (TestBit5At0x2f4_02085154(p->field150)) {
                    ctx->flags->bit2 = 0;
                }
            }
            if ((action->flags10 & 0x40000) && TestBit10At0x2f4_020851d8(p->field150)) {
                dmg = 1.0f;
                forced = 1;
                ctx->flags->bit2 = 0;
                ctx->flags->bit1 = 0;
            }
        }
    }

    if (dmg > 0) {
        if (dmg > 0 && ctx->flags->bit2) {
            dmg = 0;
        }
        if (dmg > 0 && ctx->flags->bit1) {
            dmg = 0;
        }
    }

    if (func_ov000_02156068(ctx->battle, targetId, 0, 1) && (action->flags10 & 0x1000000) &&
        (action->kind == 1 || action->id == 0xdb) && !crit && action->id != 0x205 &&
        action->id != 0x82) {
        if (!forced) {
            dmg = 0;
        }
    }

    if (dmg <= 0) {
        int miss = 1;
        if (ctx->flags->bit2) {
            miss = 0;
        }
        if (ctx->flags->bit1) {
            miss = 0;
        }
        if (action->id == 0x70) {
            miss = 0;
        }
        if (action->id == 0x48) {
            miss = 0;
        }
        if (func_ov000_02156b38(ctx->battle, targetId, action->elem) <= 0) {
            miss = 0;
        }
        if (func_ov000_02156b38(ctx->battle, targetId, elem) <= 0) {
            miss = 0;
        }
        if (action->id == 0x1b) {
            miss = 0;
        }
        if (func_ov000_02156068(ctx->battle, targetId, 0, 1) && !(action->flags10 & 0x1000000)) {
            miss = 0;
        }
        if (miss) {
            dmg = NextRandomMax((Random*)ctx->battle, 2);
        }
    }

    if (func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
        if (!crit && (action->id == 0x40 || action->id == 0x7e)) {
            dmg = 1.0f + NextRandomMax((Random*)ctx->battle, 2);
        }
        if (IsPartyMember(attackerId)) {
            struct Cbt_021e6a90* p = (struct Cbt_021e6a90*)GetCombatantWithFlag0x100_0200ff1c(gs, attackerId);
            if (p && (action->flags10 & 0x40000) && TestBit4At0x2f4_02085128(p->field150)) {
                dmg += 1.0f;
            }
        }
        if (ctx->enabled76 && (action->flags10 & 0x2000) &&
            (IsFlagBit8388608Set_021da998((FlagObj_021da998*)attacker) ||
             IsFlagBit24Set_021dd260((FlagObj_021dd260*)attacker))) {
            float mult;
            if (IsPartyMember(attackerId)) {
                mult = GetClampedRateMultiplier_02074738(attacker->stats->tension24, 0);
            } else {
                mult = GetClampedRateMultiplier_02074738(attacker->stats->tension24, 1);
            }
            dmg = dmg * mult;
        }
    }

    if (IsFlagBit24Set_021dd260((FlagObj_021dd260*)target) && action->sub18 == 1) {
        dmg = 0.5f * dmg;
    }

    if (action->flag2c && dmg >= 1.0f) {
        struct Scale4_021e6a90 scales = data_ov024_021fe778;
        signed char level = ctx->battle->level8e83;
        if (level > 3) {
            level = 3;
        }
        dmg = dmg * scales.v[level];
        ctx->hud->show = 0;
        if (level != 0) {
            ctx->hud->level = level;
        }
    } else {
        ZeroFieldsAt0xe58And0xe82And0x8e52_ov000_0215cd80(ctx->battle);
    }

    int result = dmg;
    if (action->cap != 0 && action->cap < result) {
        result = action->cap;
    }
    if (action->id == 0xaf) {
        ctx->battle->result8e38 = 0.25f * result;
    }
    return result;
}
