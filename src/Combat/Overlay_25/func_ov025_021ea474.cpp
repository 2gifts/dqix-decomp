#include <globaldefs.h>

extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _Z19GetActiveCombatWorkv();
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* work);
extern "C" void* _Z22GetNodeAtIndex02160094P12List02160094i(void* list, int idx);
extern "C" void* _Z22GetNodeAtIndex021600f8P12List021600f8i(void* list, int idx);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void* gs, int idx);
extern "C" int func_ov025_021ed380(char* obj, unsigned short id, short val2, int type, int val3, short val4, unsigned short val5);
extern "C" void _Z30SetShortArrayEntry128_021ed350Pcit(char* obj, int idx, unsigned short val);
extern "C" void* _Z15GetData02108e10v();
extern "C" void* _Z24SearchBothTables02079e2cPci(void* data, int id);

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
    void* gs = _ZN9GameState11GetInstanceEv();
    Slot021ea474* slot = (Slot021ea474*)_Z18GetSlotPtr02160f20Pv(_Z19GetActiveCombatWorkv());
    if (slot != 0) {
        Node021ea474* first = (Node021ea474*)_Z22GetNodeAtIndex02160094P12List02160094i(slot, 0);
        int who = 0;
        Node021ea474* node = (Node021ea474*)_Z22GetNodeAtIndex021600f8P12List021600f8i(slot, who);
        if (node != 0) who = node->who;
        if (slot->type == 0x92 || slot->type == 0x3a1) {
            Combatant021ea474* c = (Combatant021ea474*)_ZN9GameState19GetCombatantByIndexEi(gs, first->id);
            if (c != 0) who = *(short*)(c->stats + 0x2a);
        }
        func_ov025_021ed380(self + 0x5e8, slot->msgId, who, 0, 0, -1, 0);
        if (slot->msgId == 0xfa) {
            _Z30SetShortArrayEntry128_021ed350Pcit(self + 0x5e8, (unsigned short)(*(unsigned char*)(self + 0x738) - 1), 0x1130);
            func_ov025_021ed380(self + 0x5e8, 0x1e0, who, 0, 0, -1, 100);
        }
        Entry021ea474* e = (Entry021ea474*)_Z24SearchBothTables02079e2cPci(_Z15GetData02108e10v(), (short)slot->type);
        if ((e != 0 && ((e->f18 << 16) >> 28) == 2) || slot->type == 0x5c || slot->type == 0x67 ||
            slot->type == 0xa0 || slot->type == 0xbf) {
            func_ov025_021ed380(self + 0x5e8, slot->extraMsgId, who, 0, 0, -1, 0);
            slot->extraMsgId = 0;
        }
    }
    *(int*)(self + 0x1c4) |= 1;
}
