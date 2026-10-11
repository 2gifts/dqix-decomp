#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>

struct Ctx_021e9464;
struct Obj_021e8ca0;
struct FlagObj_021da998;
struct ActionFlags { char pad0[0x1c]; unsigned char unused : 7; unsigned char forced_ : 1; };
struct CombatAction { char pad0[0xc]; ActionFlags* action_; Random* context_; };
struct StatusFields {
    char pad0[0x14];
    unsigned int flags_;
    char pad18[0x36];
    unsigned char chance_;
};
struct ActionChance {
    int field0;
    unsigned int id_ : 12;
    unsigned int unused4 : 20;
    char pad8[0xc];
    unsigned int enemy_ : 7;
    unsigned int party_ : 7;
    unsigned int unused_ : 18;
};
union EffectFlags { struct { int low; int high; }; unsigned long long value; };

extern "C" int func_ov000_02156068(void*, int, int, int);
extern "C" int _Z32CheckField0x14FlagsClear0208824cPh(unsigned char*);
extern "C" int _Z25SelectResultCode_021e9464P12Ctx_021e9464ii(Ctx_021e9464*, int, int);
extern "C" int _Z26IsFlagAllowedMask_021eb4b0iii(int, int, int);
extern "C" void func_ov000_02159eac(void*, EffectFlags*, int);
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(FlagObj_021da998*);
extern "C" void _Z24ResetStateFields0208826cPh(unsigned char*);
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(Obj_021e8ca0*, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, int, int, int);
extern "C" void func_ov024_021e8cfc(CombatAction*, GameObject*, int, int);

// JPN: func_ov024_021e42cc
// USA: func_ov024_021e3a34
extern "C" ARM unsigned long long func_ov024_021e3a34(CombatAction* self, int actorID, int targetID, ActionChance* chance, int amount) {
    if (amount <= 0) return 0;
    GameObject* target = GetCombatantByID((int)self->context_, targetID);
    if (!target) return 0;
    if (chance->id_ == 0x52) {
        if (!func_ov000_02156068(self->context_, targetID, 9, 0)) return 0;
    } else if (chance->id_ == 0x58) {
        if (!func_ov000_02156068(self->context_, targetID, 0, 1)
            && ((StatusFields*)target->currentStats_)->chance_ == 0) return 0;
    } else if (((StatusFields*)target->currentStats_)->chance_ == 0) return 0;
    if (!_Z32CheckField0x14FlagsClear0208824cPh((unsigned char*)target->currentStats_)) return 0;
    int roll = NextRandomMax(self->context_, 100);
    float probability = 100.0f;
    if (!self->action_->forced_) {
        int party;
        if (actorID >= 0 && actorID <= 3) party = 1; else party = 0;
        if (party) probability = (float)chance->party_;
        else probability = (float)chance->enemy_;
        probability *= (float)((StatusFields*)target->currentStats_)->chance_ / 100.0f;
        switch (chance->id_) {
        case 0x52:
            probability = 25.0f;
            break;
        case 0x58:
            if (func_ov000_02156068(self->context_, targetID, 0, 1)) probability = 12.5f;
            break;
        }
    }
    if ((float)roll >= probability) return 0;
    int message = _Z25SelectResultCode_021e9464P12Ctx_021e9464ii((Ctx_021e9464*)self, targetID, 1);
    EffectFlags effects;
    effects.low = 0;
    effects.high = 0;
    if (_Z26IsFlagAllowedMask_021eb4b0iii((int)self, ((StatusFields*)target->currentStats_)->flags_, 8))
        func_ov000_02159eac(self->context_, &effects, 0x2b);
    int special = _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((FlagObj_021da998*)target);
    _Z24ResetStateFields0208826cPh((unsigned char*)target->currentStats_);
    func_ov000_02159eac(self->context_, &effects, 0x18);
    void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((Obj_021e8ca0*)self, message);
    if (entry) func_ov000_0215cd44(self->context_, entry, target, 0, 0, 0, 0);
    if (special) func_ov024_021e8cfc(self, target, 0, 0);
    return effects.value;
}
