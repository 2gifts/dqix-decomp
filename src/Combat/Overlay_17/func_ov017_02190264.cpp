#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct PartyExtension { char pad[0x568]; short preserved; };
struct PartyObject {
    GameObject object;
#if defined(jpn)
    char unknownAfterObject[0x0c];
#else
    char unknownAfterObject[0x18];
#endif
    short* modelOwner;
    char unknownAfterModelOwner[0x17a];
    unsigned char order;
};
struct PartySlot { char pad[2]; unsigned char active; };
struct PartyIndices { int slots[13]; };
struct PartyOutput { int fields[4]; };
struct FieldBlock63d6_115a8;
struct SearchStruct0202c1a4;
extern "C" int* func_0202ae18();
extern "C" int func_ov017_021925e0();
PartyExtension* GetFieldAt0x150(unsigned char*);
extern "C" void func_02082828(PartyExtension*);
void SetFlagAndSyncVec3_021bd3d4(void*, int);
extern "C" PartySlot* func_ov017_021a4658(GameResources*, int);
extern "C" void func_02046a8c(void*, PartySlot*);
void ResetEntriesAndNotify_021b33d8(void*);
int CheckField0NonZero(int*);
void* GetField0x74deForValidIndex(char*, unsigned int);
int CheckSubstructByte0x7cPositive(signed char*);
extern "C" void func_020531f0(GameObject*);
void InvalidateField0(short*);
int GetByteField0x63d6(FieldBlock63d6_115a8*);
void ClearCombatantSlot(GameState*, int);
GameObject* GetCombatantWithFlag0x1000(GameState*, int);
extern "C" void func_ov017_02191108(GameResources*, int, int, int, int);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" void func_ov017_02190884(int, PartyOutput*, int*, int, int, int);
extern "C" void func_ov017_02191234(GameResources*);
#if defined(jpn)
#define data_ov017_021d622c data_ov017_021d667c
#endif
extern PartyIndices data_ov017_021d622c;
static inline int ValidPartyIndex(int index) { return index >= 0 && index <= 3; }

// USA: func_ov017_02190264
extern "C" ARM void func_ov017_02190264(GameResources* resources, int index) {
    int valid = ValidPartyIndex(index);
    if (!valid) return;
    GameState* game = GameState::GetInstance();
    int* search = func_0202ae18();
    void* node = resources->unknown_ptr_array_371c[6];
    if (func_ov017_021925e0()) {
        GameObject* member = game->GetPartyMemberByIndex(index);
        if (member && (member->obj3D_.unknown_0_ & 0x1000)) {
            PartyExtension* extension = GetFieldAt0x150((unsigned char*)member);
            if (extension) {
                short preserved = extension->preserved;
                func_02082828(extension);
                extension->preserved = preserved;
            }
            SetFlagAndSyncVec3_021bd3d4(node, (unsigned char)index);
            return;
        }
    }
    PartySlot* slot = func_ov017_021a4658(resources, index);
    if (slot->active) {
        func_02046a8c(resources->unknown_ptr_array_36fc[1], slot);
        ResetEntriesAndNotify_021b33d8(slot);
    }
    GameObject* combatant = GetCombatantWithFlag0x100(game, index);
    if (combatant) {
        if (CheckField0NonZero(search) && (combatant->obj3D_.unknown_0_ & 0x200)) {
            short* field = (short*)GetField0x74deForValidIndex((char*)game, index);
            if (field) *field = 0;
        }
        if (CheckSubstructByte0x7cPositive((signed char*)combatant)) func_020531f0(combatant);
        strcpy(resources->partyNames[index], (char*)combatant->baseStats_);
        short* reset = ((PartyObject*)combatant)->modelOwner;
        if (reset) InvalidateField0(reset);
        if (!GetByteField0x63d6((FieldBlock63d6_115a8*)game)) {
            PartyExtension* extension = GetFieldAt0x150((unsigned char*)combatant);
            if (extension) func_02082828(extension);
        }
    }
    PartyIndices indices = data_ov017_021d622c;
    indices.slots[0] = index;
    indices.slots[1] = index * 12 + 0x13;
    indices.slots[2] = index * 12 + 0x14;
    indices.slots[3] = index * 12 + 0x15;
    indices.slots[4] = index * 12 + 0x16;
    indices.slots[5] = index * 12 + 0x17;
    indices.slots[6] = index * 12 + 0x18;
    indices.slots[7] = index * 12 + 0x19;
    indices.slots[8] = index * 12 + 0x1a;
    indices.slots[9] = index * 12 + 0x1b;
    indices.slots[10] = index * 12 + 0x1c;
    indices.slots[11] = index * 12 + 0x1d;
    for (int i = 0; indices.slots[i] >= 0; i++) ClearCombatantSlot(game, indices.slots[i]);
    int memberIndex;
    GameState* updatedGame = GameState::GetInstance();
    PartyObject* members[4] = {};
    for (memberIndex = 1; memberIndex < 4; memberIndex++) {
        PartyObject* member = (PartyObject*)GetCombatantWithFlag0x1000(updatedGame, memberIndex);
        if (member) members[member->order] = member;
    }
    int scan;
    PartyObject** current = members;
    int order = 1;
    for (scan = 0; scan < 4; scan++) { PartyObject* member = *current; if (member) member->order = order++; current++; }
    if (!CheckField0NonZero(search)) {
        func_ov017_02191108(resources, 1, 1, 1, 1);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (i == GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search)) func_ov017_02191108(resources, 1, 1, 1, 1);
        else {
            PartyOutput output;
            int field = 0;
            func_ov017_02190884(i, &output, &field, 1, 1, 1);
        }
    }
    func_ov017_02191234(resources);
}
