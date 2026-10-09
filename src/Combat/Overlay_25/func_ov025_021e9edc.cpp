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

extern "C" void* _Z19GetActiveCombatWorkv(void);
extern "C" CombatSlot021e9edc* _Z18GetSlotPtr02160f20Pv(void* work);
extern "C" int _Z16GetWord_021def24Pv(void* work);
extern "C" char* _Z20GetOffsetPtr02160f08Pv(void* work);
extern "C" HudEntry021e9edc* _Z22FindEntryById_021dafd0Pci(char* list, int id);
extern "C" void _Z24SetShortField0xC02176134P11Obj02176134s(Obj02176134* obj, unsigned short val);

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov025_021e9edc
extern "C" ARM void func_ov025_021e9edc(void* p) {
    void* work = _Z19GetActiveCombatWorkv();
    CombatSlot021e9edc* slot = _Z18GetSlotPtr02160f20Pv(work);
    if (_Z16GetWord_021def24Pv(work) != 0) {
        return;
    }
    GameState* gs = GameState::GetInstance();
    char* list = _Z20GetOffsetPtr02160f08Pv(_Z19GetActiveCombatWorkv());
    for (CombatNode021e9edc* node = slot->head; node != 0; node = node->next) {
        int id = node->id;
        unsigned short value = node->value;
        HudEntry021e9edc* entry = _Z22FindEntryById_021dafd0Pci(list, id);
        Combatant021e9edc* comb = (Combatant021e9edc*)gs->GetCombatantByIndex(id);
        if (comb == 0) {
            continue;
        }
        if (IsPartyMember(id)) {
            value = node->value;
            entry = _Z22FindEntryById_021dafd0Pci(list, id);
            comb = (Combatant021e9edc*)gs->GetCombatantByIndex(id);
        }
        if (entry != 0 && comb != 0) {
            _Z24SetShortField0xC02176134P11Obj02176134s((Obj02176134*)entry, value);
            entry->value = value;
            comb->view->value = value;
        }
    }
}
