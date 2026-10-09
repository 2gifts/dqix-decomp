#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
struct TailList020469b4;

struct InlineEntry {
    unsigned char unk0[2];
    unsigned short slotIndex : 2;
    unsigned short unk2b : 2;
    unsigned short group : 12;
    unsigned short f4;
    unsigned char unk6[2];
    int f8;
    unsigned char unkc;
    unsigned char fd;
    unsigned char unke[0xa];
    int vec18[3];
    unsigned char unk24[0x10];
    int f34;
};

struct GrottoSlot {
    unsigned char unk0[2];
    unsigned char used;
    unsigned char unk3[5];
    InlineEntry* entry;
    unsigned char unkc[5];
    unsigned char kind;
    unsigned short value;
    unsigned char unk14[4];
};

struct PendingGroup {
    unsigned short id;
    unsigned short group;
};

struct Combatant0219dc90 {
    unsigned char unk0[0x44];
    int vec44[3];
    unsigned char unk50[0x68];
    unsigned short b8;
    unsigned char unkba[8];
    unsigned char c2;
};

struct BattleOverlay0219dc90 {
    unsigned char unk0[0x3704];
    TailList020469b4* slotList;
    unsigned char unk3708[0x3a9c - 0x3708];
    GrottoSlot slots[4];
    unsigned char unk3afc[0x44b4 - 0x3afc];
    PendingGroup pending;
};

extern "C" void* func_0202ae18(void);
InlineEntry* GetEntryTableBase(void);
extern "C" void* func_02012fe4(void);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);
extern "C" void func_020288e0(InlineEntry* table);
extern "C" void _Z37SetFlagsForFlaggedCombatants_0219e0ecv(BattleOverlay0219dc90* self);
extern "C" int func_02028a54(InlineEntry* base, int id);
extern "C" void func_ov017_0219e180(BattleOverlay0219dc90* self, int id);
extern "C" InlineEntry* _Z19FindInlineEntryByIdP14Entry_02028bd0i(InlineEntry* base, int id);
extern "C" unsigned short func_02028460(int* a, int* b);
extern "C" int _Z17IsInRange0201b588i(int id);
extern "C" void _Z19InitStruct_021b46d8P14Struct021b46d8(GrottoSlot* slot);
extern "C" void _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(TailList020469b4* list, GrottoSlot* node);
extern "C" void _Z25ClearFieldcIfSet_021b4760P11Obj021b4760(GrottoSlot* slot);
extern "C" void func_02046a8c(TailList020469b4* list, GrottoSlot* node);

// USA: func_ov017_0219dc90
extern "C" ARM void func_ov017_0219dc90(BattleOverlay0219dc90* self, int combatantIdx, int id, unsigned char kind, unsigned short value) {
    GameState* gs = GameState::GetInstance();
    void* search = func_0202ae18();
    InlineEntry* table = GetEntryTableBase();
    func_02012fe4();
    Combatant0219dc90* combatant = (Combatant0219dc90*)GetCombatantWithFlag0x100(gs, combatantIdx);
    if (GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) != 0) return;
    func_020288e0(table);
    _Z37SetFlagsForFlaggedCombatants_0219e0ecv(self);
    if (combatant == NULL) return;
    int found = func_02028a54(table, id);
    func_ov017_0219e180(self, id);
    InlineEntry* entry = _Z19FindInlineEntryByIdP14Entry_02028bd0i(table, id);
    PendingGroup* pending = &self->pending;
    if (entry != NULL) {
        combatant->b8 = entry->f34 != 0 ? func_02028460(entry->vec18, combatant->vec44) : 0;
        signed char* grotto = (signed char*)gs->GetGrottoStruct();
        if (_Z17IsInRange0201b588i(id) && found) {
            entry->fd = grotto[8];
        }
        entry->f8 = 0;
        if (found) {
            if (pending->id == id) {
                entry->group = pending->group;
                pending->id = 0;
                pending->group = 0;
            }
            GrottoSlot* slot = &self->slots[entry->slotIndex];
            if (slot->used == 0) {
                _Z19InitStruct_021b46d8P14Struct021b46d8(slot);
                slot->entry = entry;
                slot->kind = kind;
                slot->value = value;
                _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(self->slotList, slot);
            } else {
                _Z25ClearFieldcIfSet_021b4760P11Obj021b4760(slot);
                func_02046a8c(self->slotList, slot);
                _Z19InitStruct_021b46d8P14Struct021b46d8(slot);
                slot->entry = entry;
                slot->kind = kind;
                slot->value = value;
                _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(self->slotList, slot);
            }
        } else {
            combatant->c2 |= 0x40;
        }
    }
    if (pending->id == id) {
        pending->id = 0;
        pending->group = 0;
    }
}
