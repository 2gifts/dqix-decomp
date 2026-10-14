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
FieldStruct02048934* SearchWithLow15Comparator02070fd0(Container02070e60*, int);
Param02048850* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
Combatant* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
void ZeroStruct021620d8(ZeroableStruct021620d8*);
void FindOrAssignSlot02167c28(unsigned char*, int);
extern "C" void func_020891cc(CombatBlob*);
extern "C" void func_02089630(CombatBlob*, void*, int);
void SetupFieldsFromParam02048850(Obj02048850*, Param02048850*);
void SetRandomizedShort0x18802048934(void*, FieldStruct02048934*, Random*);
extern "C" int func_ov000_02161bb8(ZeroableStruct021620d8*);
void IncrementByteCounterWrapAt0x12_ov000_02161bec(unsigned char*);
static inline void* GetEntryPayload(FieldStruct02048934* entry) { return entry->payload; }
static inline int GetGroupCount(PartyRoster* roster) { SDK_NULL_ASSERT(roster); return roster->groupCount; }

static inline unsigned char GetBlobSlot(Combatant* actor) { SDK_NULL_ASSERT(actor); return actor->blob->slot; }

// USA: func_ov000_02161e30
extern "C" ARM void func_ov000_02161e30(BattleState* state, int id, int key) {
    FieldStruct02048934* entry;
    Combatant* actor;
    PartyRoster* const roster = &state->mirror->roster;
    GameState* game = GameState::GetInstance();
    func_0202ae18();
    BattleResources* resources = state->resources;
    BinarySearchByComparatorStruct* params = (BinarySearchByComparatorStruct*)state->resources->params;
    entry = SearchWithLow15Comparator02070fd0((Container02070e60*)resources->entries, key);
    Param02048850* param = SearchWithComparator0206f4f0(params, (short)key);
    if (!entry || !param) return;
    actor = GetCombatantWithFlag0x400_0200fea4(game, id);
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
        ZeroStruct021620d8(&roster->groups[index]);
        roster->groups[index].key = key;
        roster->groups[index].cursor = 1;
    }
    FindOrAssignSlot02167c28((unsigned char*)state, id);
    CombatBlob* blob = actor->blob;
    func_020891cc(blob);
    func_02089630(blob, GetEntryPayload(entry), 0);
    actor->entry = entry;
    int height = ((Object3D*)actor)->GetHeight();
    int radius = ((Object3D*)actor)->GetRadius();
    SetupFieldsFromParam02048850((Obj02048850*)actor, param);
    ((Object3D*)actor)->SetHeight(height);
    ((Object3D*)actor)->SetRadius(radius);
    SetRandomizedShort0x18802048934(actor, entry, &state->mirror->random);
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
    IncrementByteCounterWrapAt0x12_ov000_02161bec(&selected->cursor);
}
