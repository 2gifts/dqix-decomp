#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Container02070e60;
struct BinarySearchByComparatorStruct;
struct Param02048850;
struct Obj02048850;
struct FieldStruct02048934 { char padding0[0x2c]; char payload[1]; };
struct ZeroableStruct021620d8 {
    unsigned char cursor;
    char padding1;
    unsigned short key;
    unsigned int flags;
};
struct PartySlot {
    unsigned short key;
    unsigned char combatant;
    char padding3[7];
    unsigned char count : 4;
    unsigned char mode : 4;
    char paddingb[0xd];
};
struct PartyRoster {
    unsigned char count;
    unsigned char memberCount : 4;
    unsigned char field1 : 2;
    unsigned char groupCount : 2;
    char padding2[2];
    PartySlot slots[3];
    ZeroableStruct021620d8 groups[3];
};
struct PartyMirror {
    Random random;
    char padding[0x81b0 - sizeof(Random)];
    PartyRoster roster;
};
struct BattleResources {
    char padding0[0x678];
    char params[0xc];
    char entries[0xc];
};
struct BattleState {
    char padding0[0x29c];
    PartyMirror* mirror;
    BattleResources* resources;
};
struct CombatBlob {
    unsigned short first, second, third, fourth;
    char padding8[0x1d];
    unsigned char slot;
};
struct Combatant {
    char padding0[0x138];
    CombatBlob* blob;
    char padding13c[0xc];
    FieldStruct02048934* entry;
    char padding14c[0x30];
    unsigned char group;
    char padding17d[7];
    unsigned char active;
    char padding185;
    unsigned short key;
    unsigned short first, second;
    unsigned char previousGroup, variant;
};
extern "C" int* func_0202ae18();
extern "C" FieldStruct02048934* _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(Container02070e60*, int);
extern "C" Param02048850* _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(BinarySearchByComparatorStruct*, int);
Combatant* GetCombatantWithFlag0x400(GameState*, int);
extern "C" void _Z18ZeroStruct021620d8P22ZeroableStruct021620d8(ZeroableStruct021620d8*);
extern "C" void _Z24FindOrAssignSlot02167c28Phi(unsigned char*, int);
extern "C" void func_020891cc(CombatBlob*);
extern "C" void func_02089630(CombatBlob*, void*, int);
extern "C" void _Z28SetupFieldsFromParam02048850P11Obj02048850P13Param02048850(Obj02048850*, Param02048850*);
extern "C" void _Z31SetRandomizedShort0x18802048934PvP19FieldStruct02048934P6Random(void*, FieldStruct02048934*, Random*);
extern "C" int func_ov000_02161bb8(ZeroableStruct021620d8*);
void IncrementByteCounterWrapAt0x12(unsigned char*);
static inline void* GetEntryPayload(FieldStruct02048934* entry) { return entry->payload; }
static inline int GetGroupCount(PartyRoster* roster) { int value = roster->groupCount; return value; }

static inline unsigned char GetBlobSlot(Combatant* actor) { unsigned char slot = actor->blob->slot; return slot; }

// USA: func_ov000_02161e30
extern "C" ARM void func_ov000_02161e30(BattleState* state, int id, int key) {
    FieldStruct02048934* entry;
    Combatant* actor;
    PartyRoster* const roster = &state->mirror->roster;
    GameState* game = GameState::GetInstance();
    func_0202ae18();
    BattleResources* resources = state->resources;
    BinarySearchByComparatorStruct* params = (BinarySearchByComparatorStruct*)state->resources->params;
    entry = _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i((Container02070e60*)resources->entries, key);
    Param02048850* param = _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(params, (short)key);
    if (!entry || !param) return;
    actor = GetCombatantWithFlag0x400(game, id);
    int group = actor->group;
    roster->count -= roster->slots[group].count - 1;
    roster->memberCount -= roster->slots[group].mode - 1;
    memset(&roster->slots[group], 0, sizeof(PartySlot));
    roster->slots[group].mode = 1;
    roster->slots[group].count = 1;
    roster->slots[group].key = key;
    roster->slots[group].combatant = id - 0xc0;
    int found = 0;
    int index = 0;
    for (int i = 0; i < roster->groupCount; i++) {
        if (key == roster->groups[i].key) {
            index = i;
            found = 1;
            break;
        }
    }
    if (!found) {
        index = GetGroupCount(roster);
        roster->groupCount = index + 1;
        _Z18ZeroStruct021620d8P22ZeroableStruct021620d8(&roster->groups[index]);
        roster->groups[index].key = key;
        roster->groups[index].cursor = 1;
    }
    _Z24FindOrAssignSlot02167c28Phi((unsigned char*)state, id);
    CombatBlob* blob = actor->blob;
    func_020891cc(blob);
    func_02089630(blob, GetEntryPayload(entry), 0);
    actor->entry = entry;
    int height = ((Object3D*)actor)->GetHeight();
    int radius = ((Object3D*)actor)->GetRadius();
    _Z28SetupFieldsFromParam02048850P11Obj02048850P13Param02048850((Obj02048850*)actor, param);
    ((Object3D*)actor)->SetHeight(height);
    ((Object3D*)actor)->SetRadius(radius);
    _Z31SetRandomizedShort0x18802048934PvP19FieldStruct02048934P6Random(actor, entry, &state->mirror->random);
    unsigned short first = actor->first;
    unsigned short second = actor->second;
    actor->blob->first = first;
    actor->blob->third = first;
    actor->blob->second = second;
    actor->blob->fourth = second;
    ZeroableStruct021620d8* selected = &roster->groups[index];
    unsigned char slot = func_ov000_02161bb8(selected);
    actor->key = key;
    if (slot == 1) slot = 0;
    actor->previousGroup = group;
    actor->variant = slot;
    actor->active = 1;
    int bit = GetBlobSlot(actor);
    roster->groups[index].flags |= 1 << bit;
    IncrementByteCounterWrapAt0x12(&selected->cursor);
}
