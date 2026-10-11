#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct Obj021db3a4;
struct Params021db3a4;
extern "C" void* _Z17GetPtrField0x2a04P9GameState(GameState*);
extern "C" int _Z17ArrayContainsByteP23ArrayContainsByteStructi(void*, int);
extern "C" float func_ov024_021db358(GameObject*);
extern "C" void _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(void*, int);
extern "C" short _Z20ApplyHPDelta0215a16cPviiPs(void*, int, int, short*);
extern "C" unsigned short func_ov024_021e9b24(Obj021db3a4*, int, Params021db3a4*, int);
extern "C" unsigned long long func_ov024_021e4b14(Obj021db3a4*, short, int, Params021db3a4*, int);
extern "C" void* func_ov000_0215e958(void*);
void AddEntryAndIncrementCount0215a88c(void*, void*, int);
extern "C" void func_ov000_02159eac(void*, void*, int);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void*, void*, GameObject*, short, short, short, unsigned long long, unsigned char);
struct Flags021db3a4 { char pad[0x1c]; unsigned char unused:7; unsigned char flag:1; };
struct Obj021db3a4 { char pad[0xc]; Flags021db3a4* action; void* context; int count; };
struct Code021db3a4 { unsigned int code:12; unsigned int rest:20; };
struct Params021db3a4 { char pad[4]; Code021db3a4 field4; };
// USA: func_ov024_021db3a4
extern "C" ARM void* func_ov024_021db3a4(Obj021db3a4* obj, short arg, int id, Params021db3a4* params, int amount, int unused, unsigned char enabled) {
    GameObject* c = GetCombatantByID((int)obj->context, id);
    if (!c) return 0;
    unsigned short code = params->field4.code;
    if (code == 0x21 || code == 0x310) amount = c->currentStats_->primaryStats.maxHP;
    void* list = _Z17GetPtrField0x2a04P9GameState(GameState::GetInstance());
    if (params->field4.code == 0x20 && _Z17ArrayContainsByteP23ArrayContainsByteStructi(list, arg) && func_ov024_021db358(c) <= 0.08f && enabled && amount > 0)
        _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(obj->context, 7);
    short applied = 0;
    short hp = _Z20ApplyHPDelta0215a16cPviiPs(obj->context, id, amount, &applied);
    int failed = 0;
    if (applied <= 0) failed = 1;
    unsigned short selection = func_ov024_021e9b24(obj, id, params, failed);
    union { struct { int low; int high; }; unsigned long long value; } effects;
    effects.low = 0;
    effects.high = 0;
    effects.value = func_ov024_021e4b14(obj, arg, id, params, amount);
    void* entry = func_ov000_0215e958(obj->context);
    if (!entry) return 0;
    if (applied > 0) obj->count++;
    else if (effects.value != 0) obj->count++;
    if (failed) {
        if (effects.value == 0) AddEntryAndIncrementCount0215a88c(obj->context, entry, selection);
        else AddEntryAndIncrementCount0215a88c(obj->context, entry, 0);
    } else {
        func_ov000_02159eac(obj->context, &effects, 0x25);
        AddEntryAndIncrementCount0215a88c(obj->context, entry, selection);
    }
    unsigned short mp = c->currentStats_->primaryStats.currMP;
    unsigned char flag;
    if (obj->action->flag) flag = 1; else flag = 0;
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(obj->context, entry, c, -applied, hp, mp, effects.value, flag);
    return entry;
}
