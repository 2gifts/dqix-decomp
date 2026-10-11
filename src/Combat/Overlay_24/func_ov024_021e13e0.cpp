#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

int RoundUp(float);
extern "C" short _Z20ApplyHPDelta0215a16cPviiPs(void*, int, int, short*);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_02159eac(void*, void*, int);
void AddEntryAndIncrementCount0215a88c(void*, void*, int);
extern "C" int func_ov024_021eae14(void*, int);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void*, void*, GameObject*, short, short, short, unsigned long long, unsigned char);
struct Flags021e13e0 { char pad[0x1c]; unsigned char unused:7; unsigned char flag:1; };
struct Obj021e13e0 { char pad[0xc]; Flags021e13e0* action; void* context; };

// JPN: func_ov024_021e1c78
// USA: func_ov024_021e13e0
extern "C" ARM void* func_ov024_021e13e0(Obj021e13e0* obj, int unused, int id) {
    GameObject* c = GetCombatantByID((int)obj->context, id);
    if (!c) return 0;
    int amount = RoundUp(0.4f * (float)(unsigned int)c->currentStats_->primaryStats.maxHP);
    if (amount < 75) amount = 75;
    union { struct { int lo; int hi; }; unsigned long long value; } effects;
    effects.lo = 0;
    effects.hi = 0;
    short applied = 0;
    short hp = _Z20ApplyHPDelta0215a16cPviiPs(obj->context, id, amount, &applied);
    void* entry = func_ov000_0215e958(obj->context);
    if (!entry) return 0;
    int added = 0;
    if (applied > 0) {
        func_ov000_02159eac(obj->context, &effects, 0x25);
        AddEntryAndIncrementCount0215a88c(obj->context, entry, 0x1ba);
        AddEntryAndIncrementCount0215a88c(obj->context, entry, 0x16);
        added = 1;
    }
    if (func_ov024_021eae14(obj, id) > 0) {
        if (!added) {
            AddEntryAndIncrementCount0215a88c(obj->context, entry, 0x1ba);
            added = 1;
        }
        AddEntryAndIncrementCount0215a88c(obj->context, entry, 0x1bb);
    }
    if (!added) AddEntryAndIncrementCount0215a88c(obj->context, entry, 0x1f);
    unsigned short mp = c->currentStats_->primaryStats.currMP;
    unsigned char flag;
    if (obj->action->flag) flag = 1; else flag = 0;
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(obj->context, entry, c, -applied, hp, mp, effects.value, flag);
    return entry;
}
