#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

struct Action_021fb91c {
    unsigned int field_0x0;
    unsigned int code : 12;
    unsigned int unused_0x4 : 20;
    unsigned int unused_0x8 : 8;
    unsigned int mode : 2;
    unsigned int unused_0xa : 22;
    unsigned int field_0xc;
    unsigned int flags;
    unsigned int unused_0x14 : 28;
    unsigned int targetKind : 4;
    unsigned int kind : 5;
    unsigned int range : 7;
    unsigned int unused_0x18 : 20;
};
struct Entry_021fb91c {
    float value;
    unsigned char id, flag, index, percent, kind, field_0x9;
    unsigned char padding[2];
};
struct AddEntryList_021f6a1c {
    Entry_021fb91c entries[16];
    int count;
    float threshold;
    AddEntryList_021f6a1c() { memset(this, 0, sizeof(*this)); }
};
struct ActionWork_021fb91c {
    unsigned char padding[0x3ec];
    int scaling;
    Action_021fb91c* action;
    unsigned char padding_0x3f4[5];
    unsigned char eligible;
    unsigned char padding_0x3fa[2];
    AddEntryList_021f6a1c* list;
    Entry_021fb91c savedEntry;
    GameObject* target;
    int targetIndex;
};
struct Battle_021fb91c {
    unsigned char padding[0x8e18];
    unsigned char* partyWork;
};
struct Context_021fb91c {
    Battle_021fb91c* battle;
    short id;
    unsigned short field_0x6;
    GameObject* actor;
    unsigned char padding_0xc[0x114 - 0xc];
    float ratings[4];
    float threshold;
    int activeIndex;
    unsigned char padding_0x12c[0x25c - 0x12c];
    ActionWork_021fb91c work;
};
struct StatsView_021fb91c {
    PrimaryCombatStats primary;
    unsigned int flags;
    unsigned char padding[0x24 - 0x18];
    signed char rate;
};
struct FlagObj_021da998;
struct FlagObj_021dd260;
struct S_10088;
int GetFieldAt0x150_02053c6c(unsigned char*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
int IsFlag10088Set_02010088(S_10088*);
int IsFlagBit8388608Set_021da998(FlagObj_021da998*);
int IsFlagBit24Set_021dd260(FlagObj_021dd260*);
float GetClampedRateMultiplier_02074738(int, int);
void AddEntryIfUnderLimit16_021f6a1c(AddEntryList_021f6a1c*, void*);
extern "C" void func_ov024_021f8938(void*, float*, float*, int, void*, GameObject*);
extern "C" void func_ov024_021f6a4c(void*, void*);
extern "C" void func_ov024_021fd858(void*);
extern "C" void func_ov024_021f9874(void*, void*, int, int);

static inline unsigned int GetMaximumHP_021fb91c(GameObject* actor) { return actor->currentStats_->primaryStats.maxHP; }

// USA: func_ov024_021fb91c
extern "C" ARM void func_ov024_021fb91c(Context_021fb91c* context) {
    Action_021fb91c* action = context->work.action;
    if (action->mode == 1) return;
    float threshold = context->threshold;
    int eligible = 1;
    if (context->ratings[context->activeIndex] >= threshold) eligible = 0;
    if (!eligible && action->kind == 0) return;
    GameObject* actor = context->actor;
    GetFieldAt0x150_02053c6c((unsigned char*)actor);
    GetData02108e10_020797dc();
    int scaling = context->work.scaling;
    float value = 0;
    float spread = 0;
    func_ov024_021f8938(context, &value, &spread, scaling, context->work.action, actor);
    if (action->code == 0x21) {
        value = 999.0f;
        spread = 999.0f;
    }
    if ((action->flags & 0x2000) &&
        (IsFlagBit8388608Set_021da998((FlagObj_021da998*)actor) ||
        IsFlagBit24Set_021dd260((FlagObj_021dd260*)actor))) {
        float multiplier = GetClampedRateMultiplier_02074738(((StatsView_021fb91c*)actor->currentStats_)->rate, 0);
        value *= multiplier;
        spread *= multiplier;
    }
    AddEntryList_021f6a1c list;
    memset(&list, 0, sizeof(list));
    for (int index = 0; index < 4; ++index) {
        if (!TestBitAt0x34_020a35e0(context->battle->partyWork, index)) continue;
        if (action->targetKind == 1 && index != context->id) continue;
        if (action->targetKind == 8 && index == context->id) continue;
        GameObject* target = GetCombatantByID((int)context->battle, (short)index);
        if (!target) continue;
        if (IsFlag10088Set_02010088((S_10088*)target)) continue;
        context->work.eligible = 1;
        if (context->ratings[index] >= threshold) context->work.eligible = 0;
        if (!context->work.eligible && action->kind == 0) continue;
        if ((action->flags & 0x400) && (((StatsView_021fb91c*)target->currentStats_)->flags & 0x200)) continue;
        float amount = value;
        int hp = target->currentStats_->primaryStats.currHP;
        int maximum = target->currentStats_->primaryStats.maxHP;
        if (action->code == 0x1fa) amount = 0.4f * (float)maximum;
        if (action->range == 14) {
            if ((float)hp / (float)maximum > 0.08f) continue;
            unsigned int actorMaximum = GetMaximumHP_021fb91c(actor);
            unsigned int actorCurrent = actor->currentStats_->primaryStats.currHP;
            if (((float)actorCurrent - amount) / (float)actorMaximum < 0.5f) continue;
            amount *= 0.3f;
        }
        maximum -= hp;
        if (amount > (float)maximum) amount = (float)maximum;
        ActionWork_021fb91c* work = &context->work;
        Entry_021fb91c entry;
        entry.flag = 0;
        entry.percent = 100;
        entry.kind = 3;
        entry.value = amount;
        entry.index = index;
        AddEntryIfUnderLimit16_021f6a1c(&list, &entry);
        if (action->kind != 0) {
            context->work.list = &list;
            func_ov024_021f6a4c(&work->savedEntry, &entry);
            context->work.target = target;
            context->work.targetIndex = index;
            func_ov024_021fd858(context);
        }
        if (action->targetKind == 2 || action->targetKind == 1 || action->targetKind == 8) {
            func_ov024_021f9874(context, &list, 0, (unsigned char)target->obj3D_.unknown_4_);
            memset(&list, 0, sizeof(list));
        }
    }
    if (action->targetKind == 4 || action->targetKind == 3) {
        GetCombatantByID((int)context->battle, 0);
        int target = (unsigned char)actor->obj3D_.unknown_4_;
        if (action->targetKind == 3) target = 0xff;
        func_ov024_021f9874(context, &list, 0, target);
    }
}
