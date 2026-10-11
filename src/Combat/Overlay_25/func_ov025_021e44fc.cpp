#include <globaldefs.h>
#include "GameState/GameState.h"

struct ListNode02160094 {
    char pad0[0x20];
    unsigned short combatantId;
    char pad22[2];
    unsigned short value;
};
struct List02160094;

struct Obj02176150 {
    char pad0[0xe];
    short val;
};

struct PartySlot021e44fc {
    struct Obj02176150 gauge;
    char pad10[0x4c - 0x10];
    int combatantId;
#if defined(jpn)
    char pad50[0x488 - 0x50];
#else
    char pad50[0x448 - 0x50];
#endif
};

struct CombatWorkOffsets021e44fc {
    char pad0[0x958];
    struct PartySlot021e44fc slots[4];
};

struct CombatantStats021e44fc {
    char pad0[6];
    unsigned short value;
};

struct CombatantView021e44fc {
    char pad0[0x130];
    struct CombatantStats021e44fc* stats;
};

extern "C" struct ListNode02160094* _Z22GetNodeAtIndex02160094P12List02160094i(struct List02160094* list, int index);
void* GetActiveCombatWork(void);
extern "C" void* _Z20GetOffsetPtr02160f08Pv(void* obj);
extern "C" void _Z24SetShortField0xE02176150P11Obj02176150s(struct Obj02176150* obj, unsigned short val);

static inline int IsPartyIndex(int id) {
    return id >= 0 && id <= 3;
}

// JPN: func_ov025_021e49ec
// USA: func_ov025_021e44fc
extern "C" ARM int func_ov025_021e44fc(void* unused, struct List02160094* list) {
    struct ListNode02160094* node = _Z22GetNodeAtIndex02160094P12List02160094i(list, 0);
    GameState* gs = GameState::GetInstance();
    struct CombatWorkOffsets021e44fc* work = (struct CombatWorkOffsets021e44fc*)_Z20GetOffsetPtr02160f08Pv(GetActiveCombatWork());
    struct PartySlot021e44fc* slot;
    if (IsPartyIndex(node->combatantId)) {
        for (int i = 0; i < 4; i++) {
            if (node->combatantId == work->slots[i].combatantId) {
                slot = &work->slots[i];
                goto found;
            }
        }
    }
    slot = 0;
found:
    struct CombatantView021e44fc* c = (struct CombatantView021e44fc*)gs->GetCombatantByIndex(node->combatantId);
    if (slot != 0) {
        unsigned short value = node->value;
        _Z24SetShortField0xE02176150P11Obj02176150s(&slot->gauge, value);
        slot->gauge.val = value;
    }
    if (c != 0) {
        c->stats->value = node->value;
    }
    return 1;
}
