#include <globaldefs.h>
#include "GameState/GameState.h"

struct SpellSlot0206e424 {
    unsigned int field_0x0;
    unsigned int field_0x4;
    unsigned int kind : 4;
    unsigned int remainingKindBits : 28;
    unsigned int field_0xc : 12;
    unsigned int spellId : 11;
    unsigned int remainingSpellBits : 9;
    unsigned int field_0x10[4];
};
struct SpellData0206e424 {
    unsigned char padding_0x0[0x194];
    SpellSlot0206e424 slots[9];
};
struct LearnedSpellFlags0206e424 {
    unsigned char padding_0x0[0x8c];
    unsigned char bits[1];
};
struct SlotOrder0206e424 {
    signed char slots[9];
};
struct S_a04c8 {
    unsigned char padding_0x0[0x14];
    unsigned int field_0x14 : 18;
    unsigned int count : 11;
    unsigned int remainingBits : 3;
    unsigned char padding_0x18[0xb0 - 0x18];
};
extern SlotOrder0206e424 data_020e87b4;
int GetFieldAt0x150(unsigned char*);
int TestBitInByteArray(int, unsigned char*, int);
void SetOrClearBitInArray(void*, unsigned char*, int, int);
extern "C" void _Z23LoadBattleBlock020ac4c0Pv(void*);
void AddClamped11BitFieldAt0x14(S_a04c8*, unsigned int);
void CopyInBattleField0x7540(void*);

static inline int IsUsableSlot0206e424(SpellSlot0206e424* slot) {
    return slot->kind <= 7;
}

// USA: func_0206e424
extern "C" ARM void func_0206e424(LearnedSpellFlags0206e424* owner, int combatantId) {
    int inParty;
    if (combatantId >= 0 && combatantId <= 3) inParty = 1;
    else inParty = 0;
    if (!inParty) return;
    GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);
    if (!combatant) return;
    SpellData0206e424* spellData = (SpellData0206e424*)GetFieldAt0x150((unsigned char*)combatant);
    if (!spellData) return;
    SlotOrder0206e424 order = data_020e87b4;
    SpellSlot0206e424* slots = spellData->slots;
    unsigned char learned = 0;
    unsigned char index = 0;
    while (order.slots[index] >= 0) {
        SpellSlot0206e424* slot = &slots[order.slots[index]];
        if (IsUsableSlot0206e424(slot)) {
            unsigned short spellId = slot->spellId;
            if (spellId) {
                if (!TestBitInByteArray((int)owner, owner->bits, (spellId + 0x76) + 0xc00)) {
                    SetOrClearBitInArray(owner, owner->bits, (spellId + 0x76) + 0xc00, 1);
                    learned++;
                }
            }
        }
        index++;
    }
    S_a04c8 block;
    _Z23LoadBattleBlock020ac4c0Pv(&block);
    AddClamped11BitFieldAt0x14(&block, learned);
    CopyInBattleField0x7540(&block);
}
