#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetActiveCombatWork_ov000_02160130();
void* GetSlotPtr02160f20(void* work);
struct List02160094;
void* GetNodeAtIndex02160094(List02160094*, int);
struct List021600f8;
void* GetNodeAtIndex021600f8(List021600f8*, int);
extern "C" int func_ov025_021ed380(char* obj, unsigned short id, short val2, int type, int val3, short val4, unsigned short val5);
void SetShortArrayEntry128_021ed350(char* obj, int idx, unsigned short val);
void* SearchBothTables02079e2c(char*, int);

struct Slot021ea474 {
    unsigned short type;
    char pad2[0x16];
    unsigned short msgId;
    char pad1a[8];
    unsigned short extraMsgId;
};

struct Node021ea474 {
    char pad0[0xe];
    short who;
    char pad10[0x10];
    unsigned short id;
};

struct Combatant021ea474 {
    char pad0[0x138];
    char* stats;
};

struct Entry021ea474 {
    char pad0[0x18];
    unsigned int f18;
};

// USA: func_ov025_021ea474
extern "C" ARM void func_ov025_021ea474(char* self) {
    if (*(int*)(self + 0x1c4) & 1) return;
    void* gs = GameState::GetInstance();
    Slot021ea474* slot = (Slot021ea474*)GetSlotPtr02160f20(GetActiveCombatWork_ov000_02160130());
    if (slot != 0) {
        Node021ea474* first = (Node021ea474*)GetNodeAtIndex02160094((List02160094*)slot, 0);
        int who = 0;
        Node021ea474* node = (Node021ea474*)GetNodeAtIndex021600f8((List021600f8*)slot, who);
        if (node != 0) who = node->who;
        if (slot->type == 0x92 || slot->type == 0x3a1) {
            Combatant021ea474* c = (Combatant021ea474*)((GameState*)gs)->GetCombatantByIndex(first->id);
            if (c != 0) who = *(short*)(c->stats + 0x2a);
        }
        func_ov025_021ed380(self + 0x5e8, slot->msgId, who, 0, 0, -1, 0);
        if (slot->msgId == 0xfa) {
            SetShortArrayEntry128_021ed350(self + 0x5e8, (unsigned short)(*(unsigned char*)(self + 0x738) - 1), 0x1130);
            func_ov025_021ed380(self + 0x5e8, 0x1e0, who, 0, 0, -1, 100);
        }
        Entry021ea474* e = (Entry021ea474*)SearchBothTables02079e2c((char*)GetData02108e10_020797dc(), (short)slot->type);
        if ((e != 0 && ((e->f18 << 16) >> 28) == 2) || slot->type == 0x5c || slot->type == 0x67 ||
            slot->type == 0xa0 || slot->type == 0xbf) {
            func_ov025_021ed380(self + 0x5e8, slot->extraMsgId, who, 0, 0, -1, 0);
            slot->extraMsgId = 0;
        }
    }
    *(int*)(self + 0x1c4) |= 1;
}
