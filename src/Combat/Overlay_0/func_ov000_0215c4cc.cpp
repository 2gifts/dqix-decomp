#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>

struct Obj02160068 { short code; char pad[0x26]; };
struct Obj021600cc;
struct Node02160068 { char pad0[0x1c]; short index; char pad1[2]; short combatant; unsigned short hp; unsigned short mp; char pad2[0xa]; Node02160068* next; };
struct Node021600cc { char pad0[0xe]; short combatant; char pad1[7]; unsigned char active; char pad2[8]; Node021600cc* next; };
struct OutStruct0215ccbc { char payload[0x20]; OutStruct0215ccbc* next; };
struct BattleEvents { char pad0[0x8e00]; unsigned char summaryCount; unsigned char targetCount; unsigned char entryCount; char pad1[0x21]; int actionCount; };
struct CombatSource { char pad[0x2e]; short id; };
struct S_10088;
extern "C" int func_ov000_0215eb1c(BattleEvents*, short*, int, int);
GameObject* GetCombatantWithFlag0x400(GameState*, int);
int IsFlag0x18Bit0x1000Set(GameObject*);
int IsFlag10088Set(S_10088*);
int IsFlag0x18Bit0x2000Set(GameObject*);
void SetBool0x180Clear0x17f(unsigned char*, int);
void ClearFlag0x1000AndBytes7eA1(unsigned char*);
extern "C" void* _Z25GetWorkArrayEntry0215e9d8Pv(void*);
extern "C" void _Z18InitStruct02160030Pv(void*);
void* GetTableEntry0x8e00Bound0x48(void*);
void* GetTableEntry0x8e01Bound0x88(void*);
extern "C" void _Z19ResetStruct02157cdcPv(void*);
extern "C" OutStruct0215ccbc* func_ov000_0215e958(BattleEvents*);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(int, OutStruct0215ccbc*, GameObject*, short, short, short, int, int, unsigned char);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void*, void*, int);
extern "C" void _Z32AppendToChainAndIncCount0215ffc4PvS_i(void*, void*, int);
extern "C" void _Z18AppendNode02160068P11Obj02160068P12Node02160068(Obj02160068*, Node02160068*);
extern "C" void _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(Obj021600cc*, Node021600cc*);
extern short data_ov000_02182c24[8];
static inline short GetSource(GameObject* combatant) { short value = ((CombatSource*)combatant->currentStats_)->id; return value; }
static inline short GetHP(GameObject* combatant) { short value = combatant->currentStats_->primaryStats.currHP; return value; }
static inline short GetMP(GameObject* combatant) { short value = combatant->currentStats_->primaryStats.currMP; return value; }
static inline short GetCombatantId(short* combatants, int index) { short value = combatants[index]; return value; }

// USA: func_ov000_0215c4cc
extern "C" ARM void func_ov000_0215c4cc(BattleEvents* events) {
    short combatants[8];
    unsigned short* source = (unsigned short*)data_ov000_02182c24;
    int copyCount = 8;
    unsigned short* destination = (unsigned short*)combatants;
    do { *destination = *source++; destination++; } while (--copyCount);
    int count = func_ov000_0215eb1c(events, combatants, 8, 1);
    for (int i = 0; i < count; i++) {
        short combatantId = GetCombatantId(combatants, i);
        GameObject* combatant = GetCombatantWithFlag0x400(GameState::GetInstance(), combatantId);
        if (!combatant || !IsFlag0x18Bit0x1000Set(combatant)) continue;
        short sourceId = GetSource(combatant);
        GameObject* other = GameState::GetInstance()->GetCombatantByIndex(sourceId);
        if (other && !IsFlag10088Set((S_10088*)other) && !IsFlag0x18Bit0x2000Set(other)) continue;
        SetBool0x180Clear0x17f((unsigned char*)combatant, 1);
        ClearFlag0x1000AndBytes7eA1((unsigned char*)combatant->currentStats_);
        Obj02160068* action = (Obj02160068*)_Z25GetWorkArrayEntry0215e9d8Pv(events);
        if (!action) continue;
        _Z18InitStruct02160030Pv(action);
        Node02160068* summary = (Node02160068*)GetTableEntry0x8e00Bound0x48(events);
        if (!summary) continue;
        memset(summary, 0, 0x30);
        summary->index = -1;
        summary->next = 0;
        Node021600cc* target = (Node021600cc*)GetTableEntry0x8e01Bound0x88(events);
        if (!target) continue;
        _Z19ResetStruct02157cdcPv(target);
        OutStruct0215ccbc* entry = func_ov000_0215e958(events);
        if (!entry) continue;
        memset(entry, 0, 0x20);
        entry->next = 0;
        action->code = 0x3ab;
        summary->combatant = combatants[i];
        summary->hp = combatant->currentStats_->primaryStats.currHP;
        summary->mp = combatant->currentStats_->primaryStats.currMP;
        _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih((int)events, entry, combatant, 0, GetHP(combatant), GetMP(combatant), 0, 0, 0);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(events, entry, 0x164);
        target->combatant = combatants[i];
        target->active = 1;
        _Z32AppendToChainAndIncCount0215ffc4PvS_i(target, entry, 0);
        events->entryCount++;
        _Z18AppendNode02160068P11Obj02160068P12Node02160068(action, summary);
        _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc((Obj021600cc*)action, target);
        events->actionCount++;
        events->summaryCount++;
        events->targetCount++;
        events->entryCount++;
    }
}
