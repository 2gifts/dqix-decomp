#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct OutStruct0215ccbc;
struct EffectWords_021e2950 { int lo; int hi; };

struct FlagObj_021da9b0;
extern "C" int _Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0(struct FlagObj_021da9b0* obj);
void ClearFlag0x14Bit0x8AndBytes(void* obj);
struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2(struct S88514* obj);
struct Combatant_2088644;
void ClearFlag0x2AndKind(struct Combatant_2088644* obj);
extern "C" short _Z20ApplyHPDelta0215a16cPviiPs(void* unused, int id, int delta, short* outApplied);
extern "C" struct OutStruct0215ccbc* func_ov000_0215e958(void* ctx);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_02159eac(void* ctx, struct EffectWords_021e2950* words, int effect);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
    int unused, struct OutStruct0215ccbc* out, GameObject* combatant, short valC, short valA, short valB,
    struct EffectWords_021e2950 words, unsigned char byteE);

struct ActionFlags_021e2950 { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Obj_021e2950 {
    char pad0[0xc];
    struct ActionFlags_021e2950* action;
    void* ctx;
    int count;
};
struct Bit3b_021e2950 { unsigned char bit0 : 1; unsigned char rest : 7; };

static inline unsigned short GetMaxHP(GameObject* c) { return c->currentStats_->primaryStats.maxHP; }

extern "C" int _Z23CheckFlag0x14Bit0x10SetPh(void*);
extern "C" void _Z23ClearBattleFlag0x14Bit4Pv(void*);
extern "C" int _Z22IsFlagBit5Set_021de25cP16FlagObj_021de25c(void*);
extern "C" void _Z21ClearFlag0x20AndBytesPv(void*);
// JPN: func_ov024_021e31e8
// USA: func_ov024_021e2950
extern "C" ARM struct OutStruct0215ccbc* func_ov024_021e2950(struct Obj_021e2950* obj, int unused, int id, int unused2, int amount) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    struct OutStruct0215ccbc* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    struct EffectWords_021e2950 words;
    words.lo = 0;
    words.hi = 0;
    short hp = c->currentStats_->primaryStats.currHP;
    short applied = 0;
    unsigned short maxHP = GetMaxHP(c);
    if (c->currentStats_->primaryStats.currHP < maxHP) {
        hp = _Z20ApplyHPDelta0215a16cPviiPs(obj->ctx, id, amount, &applied);
        func_ov000_02159eac(obj->ctx, &words, 0x25);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, 0x16);
        obj->count++;
    }
    if (_Z23CheckFlag0x14Bit0x10SetPh(c->currentStats_)) {
        _Z23ClearBattleFlag0x14Bit4Pv(c->currentStats_);
        ((struct Bit3b_021e2950*)((char*)c->currentStats_ + 0x3b))->bit0 = 1;
        func_ov000_02159eac(obj->ctx, &words, 0x10);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, 0x40);
        obj->count++;
    }
    if (_Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0((struct FlagObj_021da9b0*)c)) {
        ClearFlag0x14Bit0x8AndBytes(c->currentStats_);
        ((struct Bit3b_021e2950*)((char*)c->currentStats_ + 0x3b))->bit0 = 1;
        func_ov000_02159eac(obj->ctx, &words, 0x1a);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, 0x1f9);
        obj->count++;
    }
    if (_Z22IsFlagBit5Set_021de25cP16FlagObj_021de25c(c)) {
        _Z21ClearFlag0x20AndBytesPv(c->currentStats_);
        ((struct Bit3b_021e2950*)((char*)c->currentStats_ + 0x3b))->bit0 = 1;
        func_ov000_02159eac(obj->ctx, &words, 0x19);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, 0x16f);
        obj->count++;
    }
    if (CheckFlag0x2AndKind1((struct Combatant_20885b4*)c->currentStats_) || CheckFlag0x2AndState2((struct S88514*)c->currentStats_)) {
        ClearFlag0x2AndKind((struct Combatant_2088644*)c->currentStats_);
        func_ov000_02159eac(obj->ctx, &words, 0x11);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, 0x54);
        obj->count++;
    }
    unsigned short mp = c->currentStats_->primaryStats.currMP;
    unsigned char flag;
    if (obj->action->flag) flag = 1; else flag = 0;
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih((int)obj->ctx, entry, c, -applied,
        hp, mp, words, flag);
    return entry;
}
