#include <globaldefs.h>

struct Stats_021fa7ec {
    char pad0[0x21];
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

struct Info_021fa7ec {
    char pad0[0x34];
    unsigned short value34;
};

struct Entry_021fa7ec {
    char pad0[0xa];
    unsigned short lowBits : 12;
    unsigned short flagBit12 : 1;
};

struct Cbt_021fa7ec {
    char pad0[4];
    short id;
    char pad6[0x134 - 6];
    struct Info_021fa7ec* info;
    struct Stats_021fa7ec* stats;
    char pad13c[0x144 - 0x13c];
#if defined(jpn)
    union {
        struct Entry_021fa7ec* entry;
        unsigned char* field150;
    };
#else
    struct Entry_021fa7ec* entry;
    char pad148[0x150 - 0x148];
    unsigned char* field150;
#endif
};

struct Action_021fa7ec {
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

struct Battle_021fa7ec {
    char pad0[0x8e50];
    short target8e50;
    short action8e52;
    char pad8e54[0x8e82 - 0x8e54];
    signed char state8e82;
    signed char level8e83;
};

struct Ctx_021fa7ec {
    struct Battle_021fa7ec* battle;
    char pad4[4];
    struct Cbt_021fa7ec* attacker;
    char padc[0x9c - 0xc];
    int count9c;
    char pada0[0xe4 - 0xa0];
    float rates[(0x170 - 0xe4) / 4];
    float weight;
    char pad174[0x64c - 0x174];
    struct Action_021fa7ec* action;
    char pad650[4];
    unsigned char elem654;
};

struct Outer_021f736c {
    struct Cbt_021fa7ec* attacker;
    struct Cbt_021fa7ec* target;
    struct Entry_021fa7ec* entry;
    short count;
    struct Action_021fa7ec* action;
    float baseHi;
    float baseLo;
    float hi;
    float lo;
    float scale;
};

int GetFieldAt0x150(unsigned char*);
struct Entry_021fa7ec* FindEntryForCombatant02153758(void*, int);
int DispatchByCategory_021f736c(struct Outer_021f736c* obj);
struct FlagObj_021da998;
int IsFlagBit8388608Set_021da998(FlagObj_021da998*);
struct FlagObj_021dd260;
int IsFlagBit24Set_021dd260(FlagObj_021dd260*);
float GetClampedRateMultiplier(int tension, int mode);
int GetTableValue(void*);
float CalculateTensionBonus(int tension, int level);
extern "C" float func_ov024_021f875c(struct Ctx_021fa7ec* self, struct Cbt_021fa7ec* target, struct Action_021fa7ec* action, int flag);
extern "C" int func_ov000_02156068(struct Battle_021fa7ec* battle, int id, int kind, int mode);
extern "C" float func_ov000_02156b38(struct Battle_021fa7ec* battle, int id, int elem);
struct S886b0;
int CheckFlag0x80AndKind1(S886b0*);
struct S886f8;
int CheckFlag0x80AndKind2(S886f8*);
struct Obj02088740;
int IsFlag0x80SetAndStateEquals3(Obj02088740*);
struct Obj02088788;
int IsFlag0x80SetAndStateEquals4(Obj02088788*);
struct Obj020887d0;
int IsFlag0x80SetAndStateEquals5(Obj020887d0*);
struct Combatant_2088660;
int IsField0x18Flag0x80Set(Combatant_2088660*);
float GetPackedRateModifierField1(char*);
float GetScaledBits0To5At0x2fc(unsigned char* p);
float GetPackedRateModifierField4(char*);
struct Actor02085a48;
float GetField0x304ScaleLow(Actor02085a48*);
float GetPackedRateModifierField3(char*);
float GetPackedRateModifierField2(char*);
float GetPackedRateModifierField0(char*);
float GetScaledBits6To11At0x2fc(unsigned char* p);
float GetScaledBits24To29At0x2fc(unsigned char* p);
struct Actor02085a80;
float GetField0x304ScaleMid(Actor02085a80*);
float GetScaledBits18To23At0x2fc(unsigned char* p);
float GetScaledBits12To17At0x2fc(unsigned char* p);
struct S_flag2b;
int IsFlagBit2Set_021fb430(S_flag2b*);
struct S_flag4b;
int IsFlagBit4Set_021fb448(S_flag4b*);
struct S_flag10000;
int IsFlagBit65536Set_021fb460(S_flag10000*);
struct S_flag131072;
int IsFlagBit131072Set_021fb478(S_flag131072*);
float ComputeQuarterDecayFactor020748d0(int v);
float ComputeQuarterDecayFactor(int v);
float LookupTableC0(int v);
struct GameObject;
int IsCombatantFlag2Mask32_021e67b0(GameObject*);
int TestBit10At0x2f4(unsigned char* p);
int TestBit4At0x2f4(unsigned char* p);

struct Scale4_021fa7ec { float v[4]; };
extern struct Scale4_021fa7ec data_ov024_021fefa0;

// USA: func_ov024_021fa7ec
extern "C" ARM void func_ov024_021fa7ec(struct Ctx_021fa7ec* self, float* outHi, float* outLo, float* outAvg,
                                        int* outIndex, float baseHi, float baseLo, int useBase,
                                        struct Cbt_021fa7ec* target, int index) {
    struct Action_021fa7ec* action;
    int count;
    float startHi;
    float startLo;
    float hi;
    float lo;
    float floorLo;
    float rate;
    float resist;
    struct Cbt_021fa7ec* attacker;
    attacker = self->attacker;
    GetFieldAt0x150((unsigned char*)attacker);
    action = self->action;
    float weight = self->weight;
    count = self->count9c;

    if (useBase) {
        startHi = baseHi;
        startLo = baseLo;
    } else {
        startHi = self->rates[index];
        startLo = 0.9375f * startHi;
    }

    struct Outer_021f736c calc;
    calc.attacker = attacker;
    calc.target = target;
    calc.entry = FindEntryForCombatant02153758(self->battle, target->id);
    calc.count = count;
    calc.action = action;
    calc.baseHi = startHi;
    calc.baseLo = startLo;
    calc.hi = startHi;
    calc.lo = startLo;
    calc.scale = 1.0f;
    DispatchByCategory_021f736c(&calc);

    hi = calc.hi;
    lo = calc.lo;
    unsigned char floored = 0;

    if ((action->flags10 & 0x2000) &&
        (IsFlagBit8388608Set_021da998((FlagObj_021da998*)attacker) ||
         IsFlagBit24Set_021dd260((FlagObj_021dd260*)attacker))) {
        float mult = GetClampedRateMultiplier(attacker->stats->tension24, 0);
        hi = hi * mult;
        lo = lo * mult;
        if (target->entry == 0 || !target->entry->flagBit12) {
            signed char level = GetTableValue(attacker);
            CalculateTensionBonus(attacker->stats->tension24, level);
            hi = hi + level;
            lo = lo + level;
        }
    }

    if (action->id == 0x1f9) {
        unsigned short value = attacker->info->value34;
        float floorHi = value;
        hi = 1.2f * hi;
        if (floorHi < hi) {
            floorHi = hi;
        }
        hi = floorHi;
        floorLo = 0.95f * value;
        lo = 1.2f * lo;
        if (floorLo < lo) {
            floorLo = lo;
        }
        lo = floorLo;
        floored = 1;
    }

    rate = func_ov024_021f875c(self, target, action, 0);
    int targetId = target->id;

    if (attacker && (action->flags10 & 0x40000)) {
        if (func_ov000_02156068(self->battle, targetId, 1, 0)) {
            rate = rate * GetPackedRateModifierField1((char*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 2, 0)) {
            rate = rate * GetScaledBits0To5At0x2fc(attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 3, 0)) {
            rate = rate * GetPackedRateModifierField4((char*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 4, 0)) {
            rate = rate * GetField0x304ScaleLow((Actor02085a48*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 5, 0)) {
            rate = rate * GetPackedRateModifierField3((char*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 6, 0)) {
            rate = rate * GetPackedRateModifierField2((char*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 7, 0)) {
            rate = rate * GetPackedRateModifierField0((char*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 8, 0)) {
            rate = rate * GetScaledBits6To11At0x2fc(attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 9, 0)) {
            rate = rate * GetScaledBits24To29At0x2fc(attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 10, 0)) {
            rate = rate * GetField0x304ScaleMid((Actor02085a80*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 11, 0)) {
            rate = rate * GetScaledBits18To23At0x2fc(attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 12, 0)) {
            rate = rate * GetScaledBits12To17At0x2fc(attacker->field150);
        }
    }

    unsigned char useElem = 0;
    resist = 0;
    float elemRate = 0;
    int isParty = 0;
    struct Cbt_021fa7ec* player = self->attacker;
    if (player->id >= 0 && player->id <= 3) {
        isParty = 1;
    }
    if (isParty && player && (action->flags10 & 0x40000) &&
        self->elem654 >= 1 && self->elem654 <= 7) {
        elemRate = func_ov000_02156b38(self->battle, target->id, self->elem654);
        useElem = 1;
    }

    if (target && action->elem == 8) {
        if (CheckFlag0x80AndKind1((S886b0*)attacker->stats)) {
            resist = 1.1f * (target->stats->resist3e / 100.0f);
        } else if (CheckFlag0x80AndKind2((S886f8*)attacker->stats)) {
            resist = 1.1f * (target->stats->resist3f / 100.0f);
        } else if (IsFlag0x80SetAndStateEquals3((Obj02088740*)attacker->stats)) {
            struct Stats_021fa7ec* ts = target->stats;
            float a = 1.1f * (ts->resist41 / 100.0f);
            float b = 1.1f * (ts->resist40 / 100.0f);
            resist = b;
            if (b < a) {
                resist = a;
            }
        } else if (IsFlag0x80SetAndStateEquals4((Obj02088788*)attacker->stats)) {
            struct Stats_021fa7ec* ts = target->stats;
            float a = 1.1f * (ts->resist43 / 100.0f);
            float b = 1.1f * (ts->resist42 / 100.0f);
            resist = b;
            if (b < a) {
                resist = a;
            }
        } else if (IsFlag0x80SetAndStateEquals5((Obj020887d0*)attacker->stats)) {
            resist = 1.1f * (target->stats->resist44 / 100.0f);
        }
        if (IsField0x18Flag0x80Set((Combatant_2088660*)attacker->stats)) {
            useElem = 1;
        }
    }

    if (useElem) {
        if (elemRate <= resist) {
            rate = rate * resist;
        } else {
            rate = rate * elemRate;
        }
    }

    if (IsFlagBit2Set_021fb430((S_flag2b*)target) && action->elem == 1) {
        rate = 0.75f * rate;
    }
    if (IsFlagBit4Set_021fb448((S_flag4b*)target) && action->elem == 2) {
        rate = 0.75f * rate;
    }
    if (action->flags10 & 1) {
        if (IsFlagBit65536Set_021fb460((S_flag10000*)target) && action->sub18 != 2) {
            rate = rate * ComputeQuarterDecayFactor020748d0((signed char)target->stats->decayA);
        }
    }
    if ((action->flags10 & 4) && IsFlagBit131072Set_021fb478((S_flag131072*)target)) {
        rate = rate * ComputeQuarterDecayFactor((signed char)target->stats->decayB);
    }
    if (action->flags10 & 0x10) {
        if (target->stats->rank21 <= 3) {
            rate = rate * LookupTableC0((signed char)target->stats->rank21);
        } else if (IsCombatantFlag2Mask32_021e67b0((GameObject*)target)) {
            rate = rate * LookupTableC0(1);
        }
    }
    if (IsFlagBit24Set_021dd260((FlagObj_021dd260*)target) && action->sub18 == 1) {
        rate = 0.5f * rate;
    }

    hi = hi * rate;
    lo = lo * rate;

    if (action->flag2c) {
        struct Battle_021fa7ec* battle = self->battle;
        if (battle->action8e52 == action->id && battle->state8e82 == 1 && battle->target8e50 == target->id) {
            int level = battle->level8e83 + 1;
            if (level > 3) {
                level = 3;
            }
            struct Scale4_021fa7ec scales = data_ov024_021fefa0;
            hi = hi * scales.v[level];
            lo = lo * scales.v[level];
            *outIndex = index;
        }
    }

    if (self->action->id == 0x79) {
        if (index == 0) {
            int n = self->count9c;
            hi = hi * (0.8f + 0.125f * n);
            lo = lo * (0.8f + 0.125f * n);
        } else {
            hi *= 0.8f;
            lo *= 0.8f;
        }
    }

    if ((action->flags10 & 0x40000) && TestBit10At0x2f4(self->attacker->field150)) {
        hi = 1.0f;
        lo = hi;
    }

    if (action->id == 1) {
        if (hi < 1.0f) {
            hi = 1.0f;
        }
        if (lo < 0.4f) {
            lo = 0.4f;
        }
    }

    struct Entry_021fa7ec* entry = FindEntryForCombatant02153758(self->battle, target->id);
    if (entry && entry->flagBit12 && !floored) {
        if (action->id != 0x40 && action->id != 0x7e && action->id != 0x82) {
            hi = 1.0f;
            lo = 0.4f;
            if ((action->flags10 & 0x40000) && TestBit10At0x2f4(self->attacker->field150)) {
                lo = 1.0f;
            }
            if ((action->flags10 & 0x40000) && TestBit4At0x2f4(self->attacker->field150)) {
                hi += 1.0f;
                lo += 1.0f;
            }
            if ((action->flags10 & 0x2000) &&
                (IsFlagBit8388608Set_021da998((FlagObj_021da998*)attacker) ||
                 IsFlagBit24Set_021dd260((FlagObj_021dd260*)attacker))) {
                float mult = GetClampedRateMultiplier(attacker->stats->tension24, 0);
                hi = hi * mult;
                lo = lo * mult;
            }
        }
        if (!(action->flags10 & 0x1000000)) {
            hi = 0;
        }
    }

    unsigned int cap = action->cap;
    if (cap != 0 && cap < hi) {
        hi = cap;
    }
    if (cap != 0 && cap < lo) {
        lo = cap;
    }

    *outHi = hi;
    *outLo = lo;
    *outAvg = *outHi * weight + *outLo * (1.0f - weight);
}
