#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02176134;

struct CombatNode021e9edc {
    char pad0[0x20];
    unsigned short id;
    unsigned short value;
    char pad24[0xc];
    CombatNode021e9edc* next;
};

struct CombatSlot021e9edc {
    char pad0[0x10];
    CombatNode021e9edc* head;
};

struct HudEntry021e9edc {
    char pad0[0xc];
    unsigned short value;
};

struct View021e9edc {
    char pad0[4];
    unsigned short value;
};

struct Combatant021e9edc {
    char pad0[0x130];
    View021e9edc* view;
};

void* GetActiveCombatWork_ov000_02160130(void);
CombatSlot021e9edc* GetSlotPtr02160f20(void* work);
int GetWord_021def24(void* work);
char* GetOffsetPtr02160f08(void* work);
HudEntry021e9edc* FindEntryById_021dafd0(char* list, int id);
extern "C" void _Z24SetShortField0xC02176134P11Obj02176134s(Obj02176134* obj, unsigned short val);

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov025_021e9edc
extern "C" ARM void func_ov025_021e9edc(void* p) {
    void* work = GetActiveCombatWork_ov000_02160130();
    CombatSlot021e9edc* slot = GetSlotPtr02160f20(work);
    if (GetWord_021def24(work) != 0) {
        return;
    }
    GameState* gs = GameState::GetInstance();
    char* list = GetOffsetPtr02160f08(GetActiveCombatWork_ov000_02160130());
    for (CombatNode021e9edc* node = slot->head; node != 0; node = node->next) {
        int id = node->id;
        unsigned short value = node->value;
        HudEntry021e9edc* entry = FindEntryById_021dafd0(list, id);
        Combatant021e9edc* comb = (Combatant021e9edc*)gs->GetCombatantByIndex(id);
        if (comb == 0) {
            continue;
        }
        if (IsPartyMember(id)) {
            value = node->value;
            entry = FindEntryById_021dafd0(list, id);
            comb = (Combatant021e9edc*)gs->GetCombatantByIndex(id);
        }
        if (entry != 0 && comb != 0) {
            _Z24SetShortField0xC02176134P11Obj02176134s((Obj02176134*)entry, value);
            entry->value = value;
            comb->view->value = value;
        }
    }
}
