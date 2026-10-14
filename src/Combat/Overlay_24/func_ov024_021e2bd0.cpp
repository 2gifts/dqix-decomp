#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>

struct Obj_021e8ca0;
struct FlagObj_021dd260;
struct FlagObj_021da998;
struct FieldRefStruct_021e8fa4;
struct TargetObj02088418;
struct ActionFlags { char pad0[0x1c]; unsigned char unused : 7; unsigned char forced_ : 1; };
struct CombatAction { char pad0[0xc]; ActionFlags* action_; Random* context_; };
struct StatusFields {
    char pad0[0x14];
    unsigned int flags_;
    char pad18[0x34];
    unsigned char chance_;
};
struct ActionParams {
    char pad0[4];
    unsigned int id_ : 12;
    unsigned int unused4_ : 20;
    char pad8[0xc];
    unsigned int enemy_ : 7;
    unsigned int party_ : 7;
    unsigned int unused14_ : 18;
    unsigned int unused18_ : 5;
    unsigned int category_ : 7;
    unsigned int unused18b_ : 20;
    char pad1c[0x16];
    short kind_;
};
union EffectFlags { struct { int low; int high; }; unsigned long long value; };

int LookupValueByKey_021e8fa4(struct FieldRefStruct_021e8fa4*, int, int);
extern "C" void func_ov000_02159eac(void*, EffectFlags*, int);
int IsValidTargetCombatant(TargetObj02088418*, int, int);
int IsFlagAllowedMask_021eb4b0(int, int, int);
int IsFlagBit24Set_021dd260(FlagObj_021dd260*);
int IsFlagBit8388608Set_021da998(FlagObj_021da998*);
void ResetTargetFlags02088474(void*, int, int);
void* AddEntryToListAndIncCount_021e8ca0(Obj_021e8ca0*, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, int, int, int);
extern "C" void func_ov024_021e8cfc(CombatAction*, GameObject*, int, int);

// USA: func_ov024_021e2bd0
extern "C" ARM unsigned long long func_ov024_021e2bd0(CombatAction* self, int actorID, int targetID, ActionParams* params, int amount) {
    GameObject* target = GetCombatantByID((int)self->context_, targetID);
    if (!target) return 0;
    if (params->category_ != 10) {
        if (amount <= 0) return 0;
        if (((StatusFields*)target->currentStats_)->chance_ == 0) return 0;
        int roll = NextRandomMax(self->context_, 100);
        float probability = 100.0f;
        if (!self->action_->forced_) {
            int party;
            if (actorID >= 0 && actorID <= 3) party = 1; else party = 0;
            if (party) probability = (float)params->party_;
            else probability = (float)params->enemy_;
            if (params->id_ != 0x239 && params->id_ != 0x1fc)
                probability *= (float)((StatusFields*)target->currentStats_)->chance_ / 100.0f;
        }
        if ((float)roll >= probability) return 0;
    }
    int kind = LookupValueByKey_021e8fa4((FieldRefStruct_021e8fa4*)self, targetID, params->kind_);
    if (!kind) return 0;
    EffectFlags effects;
    effects.low = 0;
    effects.high = 0;
    func_ov000_02159eac(self->context_, &effects, (unsigned char)kind);
    if (!IsValidTargetCombatant((TargetObj02088418*)target->currentStats_, (unsigned char)params->kind_, (unsigned short)params->id_)) return 0;
    if (IsFlagAllowedMask_021eb4b0((int)self, ((StatusFields*)target->currentStats_)->flags_, 0x80000)) {
        if (kind == 0x12 || kind == 0x15 || kind == 0x1b || kind == 0x1c)
            func_ov000_02159eac(self->context_, &effects, 0x2b);
    }
    int bit24 = IsFlagBit24Set_021dd260((FlagObj_021dd260*)target);
    int special = IsFlagBit8388608Set_021da998((FlagObj_021da998*)target);
    ResetTargetFlags02088474(target->currentStats_, (unsigned char)params->kind_, (unsigned short)params->id_);
    if (params->category_ != 10) {
        int message = 0;
        switch (params->kind_) {
        case 2: message = 0x150; break;
        case 5: message = 0x5e; break;
        }
        void* entry = AddEntryToListAndIncCount_021e8ca0((Obj_021e8ca0*)self, message);
        if (entry) func_ov000_0215cd44(self->context_, entry, target, 0, 0, 0, 0);
    }
    if (special) {
        func_ov024_021e8cfc(self, target, 0, 0);
    } else if (bit24) {
        if (!IsFlagBit24Set_021dd260((FlagObj_021dd260*)target))
            func_ov024_021e8cfc(self, target, 8, 0);
    }
    return effects.value;
}
