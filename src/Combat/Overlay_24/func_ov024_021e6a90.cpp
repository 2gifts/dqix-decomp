#include <globaldefs.h>

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

extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" struct Cbt_021e6a90* _Z16GetCombatantByIDii(struct Battle_021e6a90* battle, int id);
extern "C" int _Z33IsCombatantFlag2Mask2048_021e7ba8P10GameObject(struct Cbt_021e6a90* c);
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(struct Cbt_021e6a90* c);
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(struct Cbt_021e6a90* c);
extern "C" float _Z24GetClampedRateMultiplierii(int tension, int mode);
extern "C" int func_ov000_02156068(struct Battle_021e6a90* battle, int id, int kind, int mode);
extern "C" struct Tension_021e6a90* func_ov000_02153710(struct Battle_021e6a90* battle, int id);
extern "C" int func_ov000_02159dbc(struct Battle_021e6a90* battle, int id);
extern "C" float _Z21CalculateTensionBonusii(int tension, int level);
extern "C" int _Z24CheckFieldMatch_021ea7fcPvP17FieldObj_021ea7fci(struct Ctx_021e6a90* ctx, struct Action_021e6a90* action, int crit);
extern "C" struct Cbt_021e6a90* _Z25GetCombatantWithFlag0x100P9GameStatei(void* gs, int id);
extern "C" float _Z19ApplyRandomVarianceiiP6Random(int value, int mode, struct Battle_021e6a90* battle);
extern "C" float func_ov000_02156b38(struct Battle_021e6a90* battle, int id, int elem);
extern "C" int _Z20GetBits23To25At0x2f4Ph(unsigned char* p);
extern "C" int _Z21CheckFlag0x80AndKind1P6S886b0(struct Stats_021e6a90* s);
extern "C" int _Z21CheckFlag0x80AndKind2P6S886f8(struct Stats_021e6a90* s);
extern "C" int _Z28IsFlag0x80SetAndStateEquals3P11Obj02088740(struct Stats_021e6a90* s);
extern "C" int _Z28IsFlag0x80SetAndStateEquals4P11Obj02088788(struct Stats_021e6a90* s);
extern "C" int _Z28IsFlag0x80SetAndStateEquals5P11Obj020887d0(struct Stats_021e6a90* s);
extern "C" int _Z22IsField0x18Flag0x80SetP17Combatant_2088660(struct Stats_021e6a90* s);
extern "C" float _Z27GetPackedRateModifierField1Pc(unsigned char* p);
extern "C" float _Z24GetScaledBits0To5At0x2fcPh(unsigned char* p);
extern "C" float _Z27GetPackedRateModifierField4Pc(unsigned char* p);
extern "C" float _Z21GetField0x304ScaleLowP13Actor02085a48(unsigned char* p);
extern "C" float _Z27GetPackedRateModifierField3Pc(unsigned char* p);
extern "C" float _Z27GetPackedRateModifierField2Pc(unsigned char* p);
extern "C" float _Z27GetPackedRateModifierField0Pc(unsigned char* p);
extern "C" float _Z25GetScaledBits6To11At0x2fcPh(unsigned char* p);
extern "C" float _Z26GetScaledBits24To29At0x2fcPh(unsigned char* p);
extern "C" float _Z21GetField0x304ScaleMidP13Actor02085a80(unsigned char* p);
extern "C" float _Z26GetScaledBits18To23At0x2fcPh(unsigned char* p);
extern "C" float _Z26GetScaledBits12To17At0x2fcPh(unsigned char* p);
extern "C" float _Z33ComputeQuarterDecayFactor020748d0i(int v);
extern "C" float _Z25ComputeQuarterDecayFactori(int v);
extern "C" float _Z13LookupTableC0i(int v);
extern "C" int _Z31IsCombatantFlag2Mask32_021e67b0P10GameObject(struct Cbt_021e6a90* c);
extern "C" void* _Z17GetPtrField0x2a04P9GameState(void* gs);
extern "C" int _Z17ArrayContainsByteP23ArrayContainsByteStructi(void* arr, int id);
extern "C" void _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(struct Battle_021e6a90* battle, int idx);
extern "C" int _Z15TestBit5At0x2f4Ph(unsigned char* p);
extern "C" int _Z16TestBit10At0x2f4Ph(unsigned char* p);
extern "C" int _Z13NextRandomMaxP6Randomi(struct Battle_021e6a90* battle, int max);
extern "C" int _Z15TestBit4At0x2f4Ph(unsigned char* p);
extern "C" void _Z34ZeroFieldsAt0xe58And0xe82And0x8e52Pv(struct Battle_021e6a90* battle);

extern signed char data_ov024_021fe798[];
struct Scale4_021e6a90 { float v[4]; };
extern struct Scale4_021e6a90 data_ov024_021fe778;

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// JPN: func_ov024_021e7328
// USA: func_ov024_021e6a90
extern "C" ARM int func_ov024_021e6a90(struct Ctx_021e6a90* ctx, int attackerId, int targetId,
                                                          struct Action_021e6a90* action, unsigned int base) {
    void* gs = _ZN9GameState11GetInstanceEv();
    struct Cbt_021e6a90* attacker = _Z16GetCombatantByIDii(ctx->battle, attackerId);
    struct Cbt_021e6a90* target = _Z16GetCombatantByIDii(ctx->battle, targetId);
    int crit;
    if (ctx->flags->crit) {
        crit = 1;
    } else {
        crit = 0;
    }
    float dmg = base;
    float baseF = dmg;

    if (action->id != 0x150 && _Z33IsCombatantFlag2Mask2048_021e7ba8P10GameObject(target) &&
        action->kind == 1) {
        ctx->flags->bit6 = 1;
        if ((action->flags10 & 0x2000) &&
            (_Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(attacker) ||
             _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(attacker))) {
            ctx->state47 = 1;
            if (_Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(attacker)) {
                ctx->state47 = 2;
            }
        }
        return 0;
    }

    if (ctx->enabled76 && (action->flags10 & 0x2000) &&
        (_Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(attacker) ||
         _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(attacker))) {
        if (base != 0 || (action->id != 0x70 && action->id != 0x48)) {
            float mult;
            if (IsPartyMember(attackerId)) {
                mult = _Z24GetClampedRateMultiplierii(attacker->stats->tension24, 0);
            } else {
                mult = _Z24GetClampedRateMultiplierii(attacker->stats->tension24, 1);
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
                dmg = dmg + _Z21CalculateTensionBonusii(attacker->stats->tension24, level);
            }
        }
        ctx->state47 = 1;
        if (_Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(attacker)) {
            ctx->state47 = 2;
        }
    }

    if (crit && func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
        if (action->flags10 & 0x1000000) {
            dmg = baseF;
        }
    }

    if (_Z24CheckFieldMatch_021ea7fcPvP17FieldObj_021ea7fci(ctx, action, crit)) {
        unsigned char mode = 0;
        int value = base;
        float floor = 0.0f;
        if (action->id == 1 || action->id == 0xdb || action->id == 0x1f9) {
            value = attacker->info->value34;
            mode = 1;
            floor = base;
            if (IsPartyMember(attackerId)) {
                struct Cbt_021e6a90* p = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, attackerId);
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
        float v = _Z19ApplyRandomVarianceiiP6Random((short)value, mode, ctx->battle);
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
    struct Cbt_021e6a90* self = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, attackerId);
    if (self) {
        for (; *tbl != -1; tbl += 2) {
            if (tbl[1] == _Z20GetBits23To25At0x2f4Ph(self->field150)) {
                elem = tbl[0];
                break;
            }
        }
    }

    int useElem = 0;
    float elemDmg = 0;
    if (IsPartyMember(attackerId) && _Z25GetCombatantWithFlag0x100P9GameStatei(gs, attackerId) &&
        (action->flags10 & 0x40000) && elem >= 1 && elem <= 7) {
        elemDmg = dmg * func_ov000_02156b38(ctx->battle, targetId, elem);
        useElem = 1;
    }

    float resist = 0;
    if (target && action->elem == 8 && action->id != 0x1f9 && action->id != 0x205) {
        if (_Z21CheckFlag0x80AndKind1P6S886b0(attacker->stats)) {
            resist = 1.1f * dmg;
            resist = resist * (target->stats->resist3e / 100.0f);
        } else if (_Z21CheckFlag0x80AndKind2P6S886f8(attacker->stats)) {
            resist = 1.1f * dmg;
            resist = resist * (target->stats->resist3f / 100.0f);
        } else if (_Z28IsFlag0x80SetAndStateEquals3P11Obj02088740(attacker->stats)) {
            struct Stats_021e6a90* ts = target->stats;
            float a = 1.1f * dmg;
            a = a * (ts->resist41 / 100.0f);
            float b = 1.1f * dmg;
            b = b * (ts->resist40 / 100.0f);
            resist = b;
            if (b < a) {
                resist = a;
            }
        } else if (_Z28IsFlag0x80SetAndStateEquals4P11Obj02088788(attacker->stats)) {
            struct Stats_021e6a90* ts = target->stats;
            float a = 1.1f * dmg;
            a = a * (ts->resist43 / 100.0f);
            float b = 1.1f * dmg;
            b = b * (ts->resist42 / 100.0f);
            resist = b;
            if (b < a) {
                resist = a;
            }
        } else if (_Z28IsFlag0x80SetAndStateEquals5P11Obj020887d0(attacker->stats)) {
            resist = 1.1f * dmg;
            resist = resist * (target->stats->resist44 / 100.0f);
        }
        if (_Z22IsField0x18Flag0x80SetP17Combatant_2088660(attacker->stats)) {
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
        struct Cbt_021e6a90* p = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, attackerId);
        if (p && (action->flags10 & 0x40000)) {
            if (func_ov000_02156068(ctx->battle, targetId, 1, 0)) {
                dmg = dmg * _Z27GetPackedRateModifierField1Pc(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 2, 0)) {
                dmg = dmg * _Z24GetScaledBits0To5At0x2fcPh(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 3, 0)) {
                dmg = dmg * _Z27GetPackedRateModifierField4Pc(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 4, 0)) {
                dmg = dmg * _Z21GetField0x304ScaleLowP13Actor02085a48(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 5, 0)) {
                dmg = dmg * _Z27GetPackedRateModifierField3Pc(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 6, 0)) {
                dmg = dmg * _Z27GetPackedRateModifierField2Pc(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 7, 0)) {
                dmg = dmg * _Z27GetPackedRateModifierField0Pc(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 8, 0)) {
                dmg = dmg * _Z25GetScaledBits6To11At0x2fcPh(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 9, 0)) {
                dmg = dmg * _Z26GetScaledBits24To29At0x2fcPh(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 10, 0)) {
                dmg = dmg * _Z21GetField0x304ScaleMidP13Actor02085a80(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 11, 0)) {
                dmg = dmg * _Z26GetScaledBits18To23At0x2fcPh(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 12, 0)) {
                dmg = dmg * _Z26GetScaledBits12To17At0x2fcPh(p->field150);
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
                dmg = dmg * _Z33ComputeQuarterDecayFactor020748d0i((signed char)target->stats->decayA);
            }
        }
        if ((action->flags10 & 4) && (target->stats->flags14 & 0x20000)) {
            dmg = dmg * _Z25ComputeQuarterDecayFactori((signed char)target->stats->decayB);
        }
        if ((action->flags10 & 0x10) && target && ctx->battle->flag8e94 == 0) {
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
    }

    if (action->id == 0x82 && target->stats->rank21 != 3) {
        dmg = 1.0f;
    }

    forced = 0;
    if (IsPartyMember(attackerId)) {
        struct Cbt_021e6a90* p = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, attackerId);
        if (p) {
            if (action->flags10 & 0x80000) {
                if (_Z15TestBit5At0x2f4Ph(p->field150)) {
                    ctx->flags->bit2 = 0;
                }
            }
            if ((action->flags10 & 0x40000) && _Z16TestBit10At0x2f4Ph(p->field150)) {
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
            dmg = _Z13NextRandomMaxP6Randomi(ctx->battle, 2);
        }
    }

    if (func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
        if (!crit && (action->id == 0x40 || action->id == 0x7e)) {
            dmg = 1.0f + _Z13NextRandomMaxP6Randomi(ctx->battle, 2);
        }
        if (IsPartyMember(attackerId)) {
            struct Cbt_021e6a90* p = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, attackerId);
            if (p && (action->flags10 & 0x40000) && _Z15TestBit4At0x2f4Ph(p->field150)) {
                dmg += 1.0f;
            }
        }
        if (ctx->enabled76 && (action->flags10 & 0x2000) &&
            (_Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(attacker) ||
             _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(attacker))) {
            float mult;
            if (IsPartyMember(attackerId)) {
                mult = _Z24GetClampedRateMultiplierii(attacker->stats->tension24, 0);
            } else {
                mult = _Z24GetClampedRateMultiplierii(attacker->stats->tension24, 1);
            }
            dmg = dmg * mult;
        }
    }

    if (_Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(target) && action->sub18 == 1) {
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
        _Z34ZeroFieldsAt0xe58And0xe82And0x8e52Pv(ctx->battle);
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
