#include <globaldefs.h>
#include "GameState/GameState.h"

struct SourceTraits {
    unsigned short field_00 : 15;
    unsigned short flag15 : 1;
    unsigned char pad_02[0xe];
    unsigned int field_10 : 28;
    unsigned int flag28 : 1;
    unsigned int field_10_rest : 3;
};
struct CombatantSource {
    Object3D object;
    unsigned char pad_ac[4];
    SourceTraits* traits;
};
struct CombatantNameStats {
    unsigned char pad_00[0x36];
    unsigned short name;
    unsigned char pad_38[0x6c];
};
struct NameCombatant {
    Object3D object;
    unsigned char pad_ac[4];
    unsigned short scale;
    unsigned char pad_b2[0x10];
    unsigned char flags;
    unsigned char pad_c3[0x75];
    CombatantNameStats* stats;
    unsigned char pad_13c[0x40];
    unsigned char mode;
    unsigned char pad_17d[0x13];
};
struct CombatantModelState { unsigned char data[0x70]; };
struct CombatantLookup {
    unsigned char pad_00[0x400];
    unsigned char search[0xc];
    unsigned char names[0xc];
};
struct CombatantRoster {
    union {
        struct {
            unsigned char pad_00[0x158];
            CombatantNameStats stats[8];
            unsigned char search[0xc];
            unsigned char names[0xc];
        };
        struct {
            unsigned char pad_to_lookup[0x278];
            CombatantLookup lookup;
        };
    };
};
struct Struct5e00 {
#if defined(jpn)
    unsigned char pad_00[0x21c];
#else
    unsigned char pad_00[0x2a0];
#endif
    CombatantRoster* roster;
    unsigned char pad_2a4[0xc14];
    CombatantSource* sources[4];
    unsigned short field_ec8;
#if defined(jpn)
    unsigned char pad_eca[0x6014 - 0xe46];
#else
    unsigned char pad_eca[0x4f5a];
#endif
    NameCombatant combatants[8];
    CombatantModelState models[8];
};
struct Container02070e60;
struct Obj0204887c;
struct BinarySearchByComparatorStruct;
struct Bytes02033b88;
struct CombatantScaleEntry {
    unsigned char pad_00[0xc];
    short scale;
};
void ResetNameState02048614(unsigned char*);
extern "C" void func_02049c88(NameCombatant*, CombatantModelState*);
void CopyObjectFields02048588(unsigned char*, unsigned char*);
void BuildName020488ec(char*);
char* SearchWithLow15Comparator02070fd0(Container02070e60*, int);
void ReplaceEntryAndFormat0204887c(Obj0204887c*, char*);
void SetSubstructFlag0x80(unsigned char*);
void SetSubstructFlag0x200(unsigned char*);
CombatantScaleEntry* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
int SetByte0xbeShiftPrev(Bytes02033b88*, int);
void RegisterCombatantSlot(GameState*, int, GameObject*);
void AllocateSlotAndConfigureField02166784(Struct5e00*, unsigned char*, unsigned char*);
int FindOrAssignSlot02167c28(unsigned char*, int);
extern "C" void func_ov017_02191aac(void*, int, int, int);

// USA: func_ov000_02166540
extern "C" ARM void func_ov000_02166540(Struct5e00* state, int slot, int id, unsigned char mode) {
    if (slot < 0xc0 || slot > 0xc7) return;
    GameState* game = GameState::GetInstance();
    void* effects = func_ov017_0218b5b0();
    CombatantLookup* roster = &state->roster->lookup;
    int index = slot - 0xc0;
    CombatantSource* source = 0;
    for (int i = 0; i < 4; i++) {
        CombatantSource* candidate = state->sources[i];
        if (candidate && id == candidate->object.unknown_2_) {
            source = candidate;
            break;
        }
    }
    if (!source) return;
    NameCombatant* combatant = &state->combatants[index];
    if (!combatant) return;
    ResetNameState02048614((unsigned char*)combatant);
    CombatantModelState* model = &state->models[index];
    if (!model) return;
    func_02049c88(combatant, model);
    combatant->flags |= 0x20;
    CopyObjectFields02048588((unsigned char*)source, (unsigned char*)combatant);
    combatant->object.SetField06(state->field_ec8);
    combatant->mode = mode;
    combatant->stats = &state->roster->stats[index];
    BuildName020488ec((char*)combatant);
    if (combatant->stats->name) {
        char* name = SearchWithLow15Comparator02070fd0((Container02070e60*)state->roster->names, combatant->stats->name);
        if (name) ReplaceEntryAndFormat0204887c((Obj0204887c*)combatant, name);
    }
    combatant->object.EnableFlag(8);
    SourceTraits* traits = source->traits;
    if (traits) {
        if (!traits->flag28) SetSubstructFlag0x80((unsigned char*)combatant);
        if (!traits->flag15) SetSubstructFlag0x200((unsigned char*)combatant);
    }
    CombatantScaleEntry* entry = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)roster->search, (short)id);
    if (entry) {
        int value = entry->scale << 2;
        unsigned int scale = 0x324;
        if (value >= 0x4000) scale = 0xc9;
        else if (value >= 0x3000) scale = 0x10c;
        else if (value >= 0x2000) scale >>= 1;
        combatant->scale = scale;
    }
    SetByte0xbeShiftPrev((Bytes02033b88*)combatant, 0);
    RegisterCombatantSlot(game, slot, (GameObject*)combatant);
    AllocateSlotAndConfigureField02166784(state, (unsigned char*)source, (unsigned char*)combatant);
    FindOrAssignSlot02167c28((unsigned char*)state, slot);
    GameObject* registered = game->GetCombatantByIndex(slot);
    if (registered) {
        struct CombatFlags { unsigned char pad_00[0x14]; unsigned int flags; };
        if (((CombatFlags*)registered->currentStats_)->flags & 0x1000000) func_ov017_02191aac(effects, 1, slot, 4);
    }
}
