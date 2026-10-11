#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>

struct Ctx_021e939c;
struct Obj_021e8ca0;
struct Combatant_20885e0;
struct Combatant_2088624;
struct ActionFlags { char pad0[0x1c]; unsigned char unused : 7; unsigned char forced_ : 1; };
struct CombatAction { char pad0[0xc]; ActionFlags* action_; Random* context_; };
struct StatusFields {
    char pad0[0x14];
    unsigned int flags_;
    char pad18[0x35];
    unsigned char chance_;
};
struct ActionChance {
    char pad0[0x14];
    unsigned int enemy_ : 7;
    unsigned int party_ : 7;
    unsigned int unused_ : 18;
    char pad18[0x1a];
    short kind_;
};
union EffectFlags { struct { int low; int high; }; unsigned long long value; };

int CheckFlag0x1ClearAndFlag0x1000000Clear(unsigned char*);
int CheckFlags0x1And0x1000000ClearAndKindNot2(Combatant_20885e0*);
extern "C" int _Z30SelectMessageByFlags2_021e939cP12Ctx_021e939ciii(Ctx_021e939c*, int, int, int);
extern "C" int _Z26IsFlagAllowedMask_021eb4b0iii(int, int, int);
extern "C" void func_ov000_02159eac(void*, EffectFlags*, int);
void ResetAndSetFlag0x2AndBits(unsigned char*);
void SetFlag0x2AndKind1(Combatant_2088624*);
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(Obj_021e8ca0*, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, int, int, int);

// USA: func_ov024_021e303c
extern "C" ARM unsigned long long func_ov024_021e303c(CombatAction* self, int actorID, int targetID, ActionChance* chance, int amount) {
    if (amount <= 0) return 0;
    GameObject* target = GetCombatantByID((int)self->context_, targetID);
    if (!target) return 0;
    if (((StatusFields*)target->currentStats_)->chance_ == 0) return 0;
    if (chance->kind_ > 0) {
        if (!CheckFlag0x1ClearAndFlag0x1000000Clear((unsigned char*)target->currentStats_)) return 0;
    } else if (!CheckFlags0x1And0x1000000ClearAndKindNot2((Combatant_20885e0*)target->currentStats_)) return 0;
    int roll = NextRandomMax(self->context_, 100);
    float probability = 100.0f;
    if (!self->action_->forced_) {
        int party;
        if (actorID >= 0 && actorID <= 3) party = 1; else party = 0;
        if (party) probability = (float)chance->party_;
        else probability = (float)chance->enemy_;
        probability *= (float)((StatusFields*)target->currentStats_)->chance_ / 100.0f;
    }
    int kind = 0;
    if (chance->kind_ > 0) kind = 1;
    if ((float)roll >= probability) return 0;
    int message = _Z30SelectMessageByFlags2_021e939cP12Ctx_021e939ciii((Ctx_021e939c*)self, targetID, kind, 1);
    EffectFlags effects;
    effects.low = 0;
    effects.high = 0;
    if (_Z26IsFlagAllowedMask_021eb4b0iii((int)self, ((StatusFields*)target->currentStats_)->flags_, 2))
        func_ov000_02159eac(self->context_, &effects, 0x2b);
    if (kind) ResetAndSetFlag0x2AndBits((unsigned char*)target->currentStats_);
    else SetFlag0x2AndKind1((Combatant_2088624*)target->currentStats_);
    func_ov000_02159eac(self->context_, &effects, 0xf);
    void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((Obj_021e8ca0*)self, message);
    if (entry) func_ov000_0215cd44(self->context_, entry, target, 0, 0, 0, 0);
    return effects.value;
}
