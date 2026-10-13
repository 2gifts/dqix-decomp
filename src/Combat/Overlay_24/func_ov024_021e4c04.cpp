#include <globaldefs.h>

#if defined(jpn)
enum { kAttackerTraitsOffset = 0x144 };
#else
enum { kAttackerTraitsOffset = 0x150 };
#endif

#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct BattleStage_021e4c04 {
    unsigned char pad_00[0x8e02];
    unsigned char entryCount;
};
struct TurnAction_021e4c04 {
    int value0;
    int value4;
    char pad8[0x18 - 0x8];
    unsigned char byte18;
    unsigned char byte19;
    char pad1a[0x1c - 0x1a];
    unsigned char unused : 7;
    unsigned char forced : 1;
};
struct Self_021e4c04 {
    char pad0[0xc];
    TurnAction_021e4c04* action;
    BattleStage_021e4c04* battle;
};
struct Record_021e4c04 {
    char pad0[0x10];
    unsigned int flags;
};
struct Stats_021e4c04 {
    unsigned short hp;
    char pad2[0x22 - 0x2];
    unsigned short low2 : 2;
    unsigned short kind : 4;
    unsigned short code : 3;
    unsigned short rest : 7;
    unsigned char count;
    char pad25[0x46 - 0x25];
    unsigned char rate46;
    unsigned char rate47;
    unsigned char rate48;
    unsigned char pad49;
    unsigned char rate4a;
    unsigned char rate4b;
    unsigned char rate4c;
    unsigned char rate4d;
    unsigned char rate4e;
    unsigned char rate4f;
    unsigned char rate50;
};
struct Attacker_021e4c04 {
    char pad0[kAttackerTraitsOffset];
    unsigned char* traits;
};
union Effects_021e4c04 { struct { int low; int high; }; unsigned long long value; };

struct FlagObj_021da998;
struct FlagObj_021dd260;
struct FlagObj_021e47dc;
struct FlagObj_021dd010;
struct TargetObj02088418;
struct StatStageStruct02087860;
struct Ctx_021e929c;
struct Ctx_021e9320;
struct Ctx_021e939c;
struct Ctx_021e9464;

int TestBit7At0x2f4(unsigned char*);
int TestBit26At0x2f4(unsigned char*);
int TestBit27At0x2f4(unsigned char*);
int TestBit28At0x2f4(unsigned char*);
int TestBit29At0x2f4(unsigned char*);
int TestBit30At0x2f4(unsigned char*);
int TestBit31At0x2f4(unsigned char*);
int TestBit0At0x2f8(unsigned char*);
int TestBit1At0x2f8(unsigned char*);
int TestBit2At0x2f8(unsigned char*);
int TestBit3At0x2f8(unsigned char*);
extern "C" short _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(FlagObj_021da998*);
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(FlagObj_021dd260*);
extern "C" int _Z23IsFlagBit22Set_021e47dcP16FlagObj_021e47dc(FlagObj_021e47dc*);
extern "C" int _Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010(FlagObj_021dd010*);
void DecrementCounter0x24UpdateFlag0x14(void*);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void*, void*, int);
extern "C" int _Z31CheckField0x14Bit0Clear02088840Ph(unsigned char*);
int CheckField0x14Flags0x9Clear(unsigned char*);
int CheckField0x14FlagsClear(unsigned char*);
int CheckFlag0x1ClearAndFlag0x1000000Clear(unsigned char*);
extern "C" int _Z32CheckField0x14FlagsClear0208824cPh(unsigned char*);
void SetFlag0x40AndBytes(unsigned char*);
extern "C" void _Z24ResetStateFields02088338Ph(unsigned char*);
void ClearFlag0x400000AndBytes(unsigned char*);
void ResetStateFields0x18(unsigned char*);
void SetFlag0x100AndBytes(unsigned char*);
int IsValidTargetCombatant(TargetObj02088418*, int, int);
extern "C" void _Z24ResetTargetFlags02088474Pvii(void*, int, int);
void ResetAndSetFlag0x2AndBits(unsigned char*);
extern "C" void _Z24ResetStateFields0208826cPh(unsigned char*);
int CanAdjustField0x58(void*, int);
int CanAdjustStatStageBit3(StatStageStruct02087860*, int);
void UpdateCombatantAttack(int, int);
void UpdateCombatantDefense(int, int);
extern "C" int _Z29SelectMessageByFlags_021e929cP12Ctx_021e929cii(Ctx_021e929c*, int, int);
extern "C" int _Z25SelectResultCode_021e9320P12Ctx_021e9320ii(Ctx_021e9320*, int, int);
extern "C" int _Z30SelectMessageByFlags2_021e939cP12Ctx_021e939ciii(Ctx_021e939c*, int, int, int);
extern "C" int _Z25SelectResultCode_021e9464P12Ctx_021e9464ii(Ctx_021e9464*, int, int);
extern "C" void _Z32AppendToChainAndIncCount0215ffc4PvS_i(void*, void*, int);
extern "C" void _Z28SetFirstEmptySlot48_021eb4e4P24SlotArrayStruct_021eb4e4i(Self_021e4c04*, TurnAction_021e4c04*);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_02159eac(void*, void*, int);
extern "C" int func_ov000_02156068(void*, int, int, int);
extern "C" void func_ov000_0215a004(void*, int, int, int, void*, Record_021e4c04*, int, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, unsigned long long, int);
extern "C" int func_ov024_021e9198(Self_021e4c04*, int, int, int);
extern "C" int func_020877c0(void*, int);
extern "C" int func_020878b4(void*, int);
extern "C" int func_ov024_021e94c4(Self_021e4c04*, int, Record_021e4c04*, int, signed char, unsigned char, unsigned char);
extern "C" int func_ov024_021e95d4(Self_021e4c04*, int, Record_021e4c04*, int, signed char, unsigned char, unsigned char);

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

static inline Stats_021e4c04* StatsOf(GameObject* c) {
    return (Stats_021e4c04*)c->currentStats_;
}

static inline unsigned short GetHP(GameObject* c) {
    unsigned short hp = StatsOf(c)->hp;
    return hp;
}

// USA: func_ov024_021e4c04
extern "C" ARM void func_ov024_021e4c04(Self_021e4c04* self, int attackerId, int targetId, Record_021e4c04* rec, int amount) {
    GameState* gs = GameState::GetInstance();
    GameObject* target = GetCombatantByID((int)self->battle, targetId);
    if (!target) return;
    void* entry = func_ov000_0215e958(self->battle);
    if (!entry) return;
    short special;
    float chance;
    int count;
    int any = 0;
    int msg = 0;
    Effects_021e4c04 effects;
    effects.low = 0;
    effects.high = 0;
    special = 0;
    int roll = NextRandomMax((Random*)self->battle, 100);
    if (rec->flags & 0x80000) {
        if (!IsPartyMember(attackerId)) return;
        Attacker_021e4c04* attacker = (Attacker_021e4c04*)GetCombatantWithFlag0x100(gs, attackerId);
        if (!attacker) return;

        if (TestBit7At0x2f4(attacker->traits)
            && (_Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((FlagObj_021da998*)target) || _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260((FlagObj_021dd260*)target))) {
            DecrementCounter0x24UpdateFlag0x14(target->currentStats_);
            count = StatsOf(target)->count;
            switch (count) {
            case 0: msg = 0x17f; break;
            case 1: msg = 0x180; break;
            case 2: msg = 0x181; break;
            case 3: msg = 0x259; break;
            }
            func_ov000_02159eac(self->battle, &effects, 0x1d);
            if (count == 3) func_ov000_02159eac(self->battle, &effects, 8);
            _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, msg);
            any = 1;
        }

        if (TestBit26At0x2f4(attacker->traits)
            && _Z31CheckField0x14Bit0Clear02088840Ph((unsigned char*)target->currentStats_)
            && (int)StatsOf(target)->rate46 > 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 20.0f)) {
                int msg = func_ov024_021e9198(self, targetId, 1, 1);
                if (!msg) msg = 0x25;
                _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, msg);
                any = 1;
                SetFlag0x40AndBytes((unsigned char*)target->currentStats_);
                StatsOf(target)->code = 1;
            }
        }

        if (TestBit27At0x2f4(attacker->traits)
            && CheckField0x14Flags0x9Clear((unsigned char*)target->currentStats_)
            && (int)StatsOf(target)->rate47 > 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 20.5f)) {
                special = _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((FlagObj_021da998*)target);
                int msg = _Z29SelectMessageByFlags_021e929cP12Ctx_021e929cii((Ctx_021e929c*)self, targetId, 1);
                _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, msg);
                any = 1;
                _Z24ResetStateFields02088338Ph((unsigned char*)target->currentStats_);
            }
        }

        if (TestBit28At0x2f4(attacker->traits)) {
            chance = 10.5f;
            if (func_ov000_02156068(self->battle, targetId, 0, 1) == 0 && StatsOf(target)->rate48 == 0) chance = 0.0f;
            if ((float)roll < chance) {
                GameObject* victim = GetCombatantByID((int)self->battle, targetId);
                if (_Z23IsFlagBit22Set_021e47dcP16FlagObj_021e47dc((FlagObj_021e47dc*)victim)) {
                    func_ov000_02159eac(self->battle, &effects, 0x29);
                    ClearFlag0x400000AndBytes((unsigned char*)victim->currentStats_);
                    func_ov000_0215a004(self->battle, attackerId, targetId, GetHP(victim) - 1, &effects, rec, self->action->forced != 0, 0);
                    _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, 200);
                } else {
                    func_ov000_0215a004(self->battle, attackerId, targetId, 0xffff, &effects, rec, self->action->forced != 0, 8);
                    effects.low = 0;
                    effects.high = 0;
                    func_ov000_02159eac(self->battle, &effects, 0xd);
                    _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, 0x257);
                }
                self->action->value0 = 0;
                self->action->byte18 = 0;
                self->action->value4 = 0;
                self->action->byte19 = 0;
                any = 1;
            }
        }

        if (TestBit29At0x2f4(attacker->traits)
            && CheckField0x14FlagsClear((unsigned char*)target->currentStats_)
            && StatsOf(target)->rate4a != 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 10.5f)) {
                int msg = _Z25SelectResultCode_021e9320P12Ctx_021e9320ii((Ctx_021e9320*)self, targetId, 1);
                _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, msg);
                any = 1;
                ResetStateFields0x18((unsigned char*)target->currentStats_);
            }
        }

        if (TestBit30At0x2f4(attacker->traits)
            && _Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010((FlagObj_021dd010*)target)
            && StatsOf(target)->rate4b != 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 25.0f)) {
                int msg = 0x18;
                if (_Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010((FlagObj_021dd010*)target)) msg = 0x1a;
                _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, msg);
                any = 1;
                SetFlag0x100AndBytes((unsigned char*)target->currentStats_);
            }
        }

        if (TestBit31At0x2f4(attacker->traits)
            && IsValidTargetCombatant((TargetObj02088418*)target->currentStats_, 5, 0)
            && StatsOf(target)->rate4c != 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 12.5f)) {
                special = _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((FlagObj_021da998*)target);
                int msg = 0x5e;
                if (StatsOf(target)->kind == 5) msg = 0x60;
                _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, msg);
                any = 1;
                _Z24ResetTargetFlags02088474Pvii(target->currentStats_, 5, 0);
            }
        }

        if (TestBit0At0x2f8(attacker->traits)
            && CheckFlag0x1ClearAndFlag0x1000000Clear((unsigned char*)target->currentStats_)
            && StatsOf(target)->rate4d != 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 12.5f)) {
                int msg = _Z30SelectMessageByFlags2_021e939cP12Ctx_021e939ciii((Ctx_021e939c*)self, targetId, 1, 1);
                _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, msg);
                any = 1;
                ResetAndSetFlag0x2AndBits((unsigned char*)target->currentStats_);
            }
        }

        if (TestBit1At0x2f8(attacker->traits)
            && _Z32CheckField0x14FlagsClear0208824cPh((unsigned char*)target->currentStats_)
            && StatsOf(target)->rate4e != 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 10.0f)) {
                special = _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((FlagObj_021da998*)target);
                int msg = _Z25SelectResultCode_021e9464P12Ctx_021e9464ii((Ctx_021e9464*)self, targetId, 1);
                _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, msg);
                any = 1;
                _Z24ResetStateFields0208826cPh((unsigned char*)target->currentStats_);
            }
        }

        if (TestBit2At0x2f8(attacker->traits)
            && CanAdjustField0x58(target->currentStats_, 1)
            && StatsOf(target)->rate4f != 0) {
            chance = 20.0f;
            if ((float)roll < chance) {
                int result = func_020877c0(target->currentStats_, -1);
                UpdateCombatantAttack((int)self->battle, targetId);
                int msg = func_ov024_021e94c4(self, targetId, rec, 1, (signed char)result, 1, 1);
                _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, msg);
                any = 1;
            }
        }

        if (TestBit3At0x2f8(attacker->traits)
            && CanAdjustStatStageBit3((StatStageStruct02087860*)target->currentStats_, 1)
            && StatsOf(target)->rate50 != 0) {
            chance = 20.0f;
            if ((float)roll < chance) {
                int result = func_020878b4(target->currentStats_, -1);
                UpdateCombatantDefense((int)self->battle, targetId);
                int msg = func_ov024_021e95d4(self, targetId, rec, 1, (signed char)result, 1, 1);
                _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, entry, msg);
                any = 1;
            }
        }
    }
    if (any) {
        func_ov000_0215cd44(self->battle, entry, target, 0, effects.value, 0);
        _Z32AppendToChainAndIncCount0215ffc4PvS_i(self->action, entry, 2);
        self->battle->entryCount++;
        _Z28SetFirstEmptySlot48_021eb4e4P24SlotArrayStruct_021eb4e4i(self, self->action);
    }
    if (special) {
        void* extra = func_ov000_0215e958(self->battle);
        if (!extra) return;
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->battle, extra, 0x25c);
        _Z32AppendToChainAndIncCount0215ffc4PvS_i(self->action, extra, 2);
        self->battle->entryCount++;
        func_ov000_0215cd44(self->battle, extra, target, 0, 0, 0);
    }
}
