#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>

struct Ctx_021e929c;
struct Obj_021e8ca0;
struct FlagObj_021da998;
struct ActionFlags { char pad0[0x1c]; unsigned char unused : 7; unsigned char forced_ : 1; };
struct CombatAction { char pad0[0xc]; ActionFlags* action_; Random* context_; };
struct StatusFields {
    char pad0[0x14];
    unsigned int flags_;
    char pad18[0x2f];
    unsigned char chance_;
};
struct ActionChance {
    char pad0[0x14];
    unsigned int enemy_ : 7;
    unsigned int party_ : 7;
    unsigned int unused_ : 18;
};
union EffectFlags { struct { int low; int high; }; unsigned long long value; };

int CheckField0x14Flags0x9Clear(unsigned char*);
int SelectMessageByFlags_021e929c(Ctx_021e929c*, int, int);
int IsFlagAllowedMask_021eb4b0(int, int, int);
extern "C" void func_ov000_02159eac(void*, EffectFlags*, int);
int IsFlagBit8388608Set_021da998(FlagObj_021da998*);
void ResetStateFields02088338(unsigned char*);
void* AddEntryToListAndIncCount_021e8ca0(Obj_021e8ca0*, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, int, int, int);
extern "C" void func_ov024_021e8cfc(CombatAction*, GameObject*, int, int);

// USA: func_ov024_021e33a4
extern "C" ARM unsigned long long func_ov024_021e33a4(CombatAction* self, int actorID, int targetID, ActionChance* chance, int amount) {
    if (amount <= 0) return 0;
    GameObject* target = GetCombatantByID((int)self->context_, targetID);
    if (!target) return 0;
    if (((StatusFields*)target->currentStats_)->chance_ == 0) return 0;
    if (!CheckField0x14Flags0x9Clear((unsigned char*)target->currentStats_)) return 0;
    int roll = NextRandomMax(self->context_, 100);
    float probability = 100.0f;
    if (!self->action_->forced_) {
        int party;
        if (actorID >= 0 && actorID <= 3) party = 1; else party = 0;
        if (party) probability = (float)chance->party_;
        else probability = (float)chance->enemy_;
        probability *= (float)((StatusFields*)target->currentStats_)->chance_ / 100.0f;
    }
    if ((float)roll >= probability) return 0;
    int message = SelectMessageByFlags_021e929c((Ctx_021e929c*)self, targetID, 1);
    EffectFlags effects;
    effects.low = 0;
    effects.high = 0;
    if (IsFlagAllowedMask_021eb4b0((int)self, ((StatusFields*)target->currentStats_)->flags_, 0x10))
        func_ov000_02159eac(self->context_, &effects, 0x2b);
    int special = IsFlagBit8388608Set_021da998((FlagObj_021da998*)target);
    ResetStateFields02088338((unsigned char*)target->currentStats_);
    func_ov000_02159eac(self->context_, &effects, 0xe);
    void* entry = AddEntryToListAndIncCount_021e8ca0((Obj_021e8ca0*)self, message);
    if (entry) func_ov000_0215cd44(self->context_, entry, target, 0, 0, 0, 0);
    if (special) func_ov024_021e8cfc(self, target, 0, 0);
    return effects.value;
}
