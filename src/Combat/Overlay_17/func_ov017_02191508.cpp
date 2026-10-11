#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct PackedTriple02191508 {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int reserved : 2;
};

struct Template02191508 {
#if defined(jpn)
    char name[0xd];
#else
    char name[0x12];
#endif

    unsigned char kind;
    unsigned char slot;
    PackedTriple02191508 triples[3];
};

struct Packed02191508 {
    unsigned int header : 32;
    unsigned short kind : 7;
    unsigned short extra : 9;
    PackedTriple02191508 triples[3];
};

struct Status02191508 {
    unsigned int flags;
    unsigned short hp;
    unsigned short mp;
};

struct Combatant02191508 {
    unsigned char pad0[0x130];
    Status02191508* status;
    BaseCombatStats* baseStats;
};

struct Member02191508 {
    unsigned char pad0[0x3c];
    char name[0x16c - 0x3c];
    unsigned short kind;
    unsigned char pad16e[0x56a - 0x16e];
    unsigned char state;
};

Member02191508* GetFieldAt0x150(unsigned char* obj);
extern "C" void func_02083cbc(void* dst, void* src, void* tail);
extern "C" void func_02083e28(void* a, int arg2);
void SetBit0x954StoreIndex0x950(unsigned char* obj, int bit);
extern "C" void _Z23ClearTwoRegions02083c18Pc(char* obj);
void SetBitInArray0x910(unsigned char* obj, int index);

extern char data_020ef078[];

// JPN: func_ov017_021920ec
// USA: func_ov017_02191508
extern "C" ARM void func_ov017_02191508(int id, Template02191508* tmpl) {
    Combatant02191508* combatant =
        (Combatant02191508*)GetCombatantWithFlag0x100(GameState::GetInstance(), id);
    if (combatant == NULL) return;
    Member02191508* member = GetFieldAt0x150((unsigned char*)combatant);
    if (member == NULL) return;

    int hp = -1;
    if (strcmp(member->name, tmpl->name) == 0) {
        hp = combatant->status->hp;
    }
#if defined(jpn)
    sprintf(member->name, data_020ef078, tmpl->name);

#else
    if (tmpl != NULL) {
        sprintf(member->name, data_020ef078, tmpl->name);
    } else {
        sprintf(member->name, data_020ef078, member->name);
    }


#endif
    Packed02191508 packed;
    packed.header = 0;
    packed.extra = 0;
    packed.kind = tmpl->kind;
    packed.triples[0].fieldA = tmpl->triples[0].fieldA;
    packed.triples[0].fieldB = tmpl->triples[0].fieldB;
    packed.triples[0].fieldC = tmpl->triples[0].fieldC;
    packed.triples[1].fieldA = tmpl->triples[1].fieldA;
    packed.triples[1].fieldB = tmpl->triples[1].fieldB;
    packed.triples[1].fieldC = tmpl->triples[1].fieldC;
    packed.triples[2].fieldA = tmpl->triples[2].fieldA;
    packed.triples[2].fieldB = tmpl->triples[2].fieldB;
    packed.triples[2].fieldC = tmpl->triples[2].fieldC;
    member->state = 0xb;
    func_02083cbc(member, &packed, NULL);
    func_02083e28(member, 0);

    if (hp > -1) {
        combatant->status->hp = hp;
    } else {
        combatant->status->hp = combatant->baseStats->primaryStats.maxHP;
    }
    combatant->status->mp = combatant->baseStats->primaryStats.maxMP;
    SetBit0x954StoreIndex0x950((unsigned char*)member, 0);
    _Z23ClearTwoRegions02083c18Pc((char*)member);
    member->kind = tmpl->kind;
    SetBitInArray0x910((unsigned char*)member, tmpl->slot);
}
