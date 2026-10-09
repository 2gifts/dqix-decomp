#include <globaldefs.h>
#include "GameState/GameState.h"

struct List02169b04;

struct List021600f8 {
    char pad0[9];
    unsigned char count;
};

struct ListNode021600f8 {
    char pad0[0x18];
    unsigned char depthCount;
};

struct DepthNode0215fff4 {
    char pad0[8];
    void* entry;
};

struct Obj021e9b2c {
    struct List02169b04* keys;
    char pad4[0x1c4 - 0x4];
    unsigned int flags;
    char pad1c8[0x53c - 0x1c8];
    unsigned char active;
    char pad53d[0x5c8 - 0x53d];
    unsigned short targetIndex;
};

extern unsigned int data_ov025_021ef9a4;

void* GetActiveCombatWork(void);
extern "C" List021600f8* _Z18GetSlotPtr02160f20Pv(void* work);
extern "C" void _Z20ResetFields_021df9b0Pv(void* fields);
extern "C" void _Z40ApplyField41ToGatheredCombatants02163a7cP17GatherObj02163a7c(void* work);
extern "C" void* _Z21FindNodeByKey02169b04P12List02169b04i(struct List02169b04* list, int key);
extern "C" ListNode021600f8* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8* list, int index);
extern "C" DepthNode0215fff4* _Z23FindNodeAtDepth0215fff4Pvii(void* node, int index, int depth);
extern "C" short func_ov000_0215ffa0(void* node);
extern "C" void func_ov025_021eb6fc(Obj021e9b2c* self, int arg);
extern "C" void func_ov025_021ea474(Obj021e9b2c* self);
extern "C" void func_ov025_021eb7fc(Obj021e9b2c* self);
extern "C" void func_ov025_021e9d14(Obj021e9b2c* self);
extern "C" void func_ov025_021ea958(Obj021e9b2c* self, bool isParty, int a, int b);

// USA: func_ov025_021e9b2c
extern "C" ARM void func_ov025_021e9b2c(Obj021e9b2c* self) {
    GameState::GetInstance();
    void* work = GetActiveCombatWork();
    List021600f8* slot = _Z18GetSlotPtr02160f20Pv(work);
    if (data_ov025_021ef9a4 & 8) {
        func_ov025_021eb6fc(self, 0);
        func_ov025_021ea474(self);
        func_ov025_021eb7fc(self);
        _Z20ResetFields_021df9b0Pv((char*)work + 0x5ab0);
        _Z40ApplyField41ToGatheredCombatants02163a7cP17GatherObj02163a7c(work);
    }
    if (self->flags & 0x10) {
        self->flags &= ~0x10;
        if (!(data_ov025_021ef9a4 & 0x20)) {
            data_ov025_021ef9a4 |= 0x20;
            if (!((self->keys != NULL && _Z21FindNodeByKey02169b04P12List02169b04i(self->keys, 0x69) != NULL) ||
                  _Z21FindNodeByKey02169b04P12List02169b04i(self->keys, 0x89) != NULL)) {
                func_ov025_021e9d14(self);
            }
            int allIdle = 1;
            for (int i = 0; i < slot->count; i++) {
                ListNode021600f8* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(slot, i);
                if (node == NULL) {
                    continue;
                }
                for (int j = 0; j < node->depthCount; j++) {
                    DepthNode0215fff4* d = _Z23FindNodeAtDepth0215fff4Pvii(node, j, 0);
                    if (d != NULL && d->entry != NULL) {
                        allIdle = 0;
                        break;
                    }
                }
            }
            if (allIdle) {
                bool isParty = true;
                ListNode021600f8* first = _Z22GetNodeAtIndex021600f8P12List021600f8i(slot, 0);
                if (first != NULL) {
                    int index = func_ov000_0215ffa0(first);
                    isParty = (index >= 0 && index <= 3) ? 1 : 0;
                }
                func_ov025_021ea958(self, isParty, 1, -1);
            } else {
                self->active = 0;
            }
        }
    }
    if (self->targetIndex >= 0xff) {
        return;
    }
    if (self->active == 0) {
        return;
    }
    func_ov025_021ea958(self, (self->targetIndex <= 3) ? 1 : 0, 1, -1);
}
