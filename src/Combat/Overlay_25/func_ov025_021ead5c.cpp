#include <globaldefs.h>

extern "C" void* __clear(void* dst, int count);

struct Member0215fd90 {
    char pad0[0xe];
    short hp;
    char pad10[0x20 - 0x10];
    struct Member0215fd90* next;
};

struct ListNode021600f8 {
    struct Member0215fd90* members;
    char pad4[0x20 - 0x4];
    struct ListNode021600f8* next;
};

struct List021600f8 {
    char pad0[0x1e];
    unsigned short field1e;
    unsigned short field20;
};

struct Obj021ead5c {
    char pad0[0x5ca];
    unsigned char triggered;
    unsigned char triggeredAll;
    char pad5cc[0x5d2 - 0x5cc];
    short pendingIds[9];
    int pendingCount;
    char queue[1];
};

void* GetActiveCombatWork(void);
extern "C" List021600f8* _Z18GetSlotPtr02160f20Pv(void* work);
extern "C" ListNode021600f8* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8* list, int index);
extern "C" int func_ov000_0215fd90(Member0215fd90* member, int flag);
extern "C" short func_ov000_0215ffa0(ListNode021600f8* node);
extern "C" int func_ov025_021ed380(char* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);

static inline int IsSpecialId(int id) {
    return (id >= 0xc0 && id <= 0xc7) ? 1 : 0;
}

static inline int IsPartyId(int id) {
    return (id >= 0 && id <= 3) ? 1 : 0;
}

// USA: func_ov025_021ead5c
extern "C" ARM void func_ov025_021ead5c(Obj021ead5c* self, int all) {
    if (all == 0) {
        if (self->triggered != 0) {
            return;
        }
        self->triggered = 1;
    }
    if (all != 0) {
        if (self->triggeredAll != 0) {
            return;
        }
        self->triggeredAll = 1;
    }
    List021600f8* slot = _Z18GetSlotPtr02160f20Pv(GetActiveCombatWork());
    unsigned char seen[4];
    int partyIds[4];
    __clear(seen, sizeof(seen));
    int specialId = 0;
    __clear(partyIds, sizeof(partyIds));
    int partyCount = 0;
    if (slot->field1e != 0 || slot->field20 != 0) {
        for (ListNode021600f8* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(slot, 0); node != NULL; node = node->next) {
            for (Member0215fd90* m = node->members; m != NULL; m = m->next) {
                if (func_ov000_0215fd90(m, 0xd) != 0) {
                    continue;
                }
                if (m->hp > 0) {
                    continue;
                }
                int id = func_ov000_0215ffa0(node);
                if (IsSpecialId(id)) {
                    if (specialId == 0) {
                        specialId = id;
                    }
                } else if (IsPartyId(id)) {
                    if (seen[id] == 0) {
                        partyIds[partyCount] = id;
                        seen[id] = 1;
                        partyCount++;
                    }
                }
                break;
            }
        }
    }
    if (all != 0) {
        for (int i = 0; i < self->pendingCount; i++) {
            func_ov025_021ed380(self->queue, 8, self->pendingIds[i], 0, 0, -1, 0);
        }
        self->pendingCount = 0;
    } else if (specialId != 0) {
        func_ov025_021ed380(self->queue, slot->field20, (short)specialId, 0, 0, -1, 0);
    }
}
