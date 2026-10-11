#include <globaldefs.h>
#include "GameState/GameState.h"

struct CombatInfo_021dfbfc {
#if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
    int status;
};

struct CombatInfo_021dfbfc* GetFieldAt0x150(unsigned char* obj);
void SetSubstructByte0x4c(unsigned char* obj, unsigned char value);

struct Action_021dfbfc {
    char pad0[0xe];
    short value;
};

struct Node_021dfbfc {
    char pad0[0x20];
    unsigned short id;
    char pad22[0xe];
    struct Node_021dfbfc* next;
};

struct Slot_021dfbfc {
    char pad0[0x10];
    struct Node_021dfbfc* head;
    struct Action_021dfbfc* action;
    char pad18[0x10];
};

struct Party_021dfbfc {
    char pad0[0x821c];
    struct Slot_021dfbfc slots[77];
    int slotCount;
};

struct BattleCtrl_021dfbfc {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    struct Party_021dfbfc* party;
};

static inline int IsInRange(int id) {
    return id >= 0xc0 && id <= 0xc7;
}

// JPN: func_ov025_021e050c
// USA: func_ov025_021dfbfc
extern "C" ARM void func_ov025_021dfbfc(BattleCtrl_021dfbfc* obj) {
    GameState* bs = GameState::GetInstance();
    struct Party_021dfbfc* party = obj->party;
    for (int i = 0; i < party->slotCount; i++) {
        struct Slot_021dfbfc* slot = &party->slots[i];
        for (struct Node_021dfbfc* node = slot->head; node != 0; node = node->next) {
            int id = node->id;
            int apply = 0;
            if (IsInRange(id)) {
                apply = 1;
            } else {
                GameObject* c = GetCombatantWithFlag0x100(bs, id);
                if (c != 0) {
                    struct CombatInfo_021dfbfc* info = GetFieldAt0x150((unsigned char*)c);
                    if (info != 0 && (signed char)info->status != 5) {
                        apply = 1;
                    }
                }
            }
            if (apply) {
                GameObject* target = bs->GetCombatantByIndex(id);
                if (target != 0 && slot->action != 0) {
                    SetSubstructByte0x4c((unsigned char*)target, slot->action->value);
                }
            }
        }
    }
}
