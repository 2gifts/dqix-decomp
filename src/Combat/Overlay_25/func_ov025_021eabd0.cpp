#include <globaldefs.h>

extern "C" void* _Z19GetActiveCombatWorkv();
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* work);
extern "C" void* _Z22GetNodeAtIndex021600f8P12List021600f8i(void* list, int idx);
extern "C" short func_ov000_0215ffa0(void* node);
extern "C" int func_ov025_021ed380(char* obj, unsigned short id, short val2, int type, int val3, short val4, unsigned short val5);

extern unsigned int data_ov025_021ef9a4;

struct Slot021eabd0 {
    char pad0[9];
    unsigned char count;
    char padA[2];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    char padD[0xd];
    unsigned short partyMsgId;
    unsigned short enemyMsgId;
};

static inline int IsPartyIndex(short idx) {
    return (idx >= 0 && idx <= 3) ? 1 : 0;
}

// USA: func_ov025_021eabd0
extern "C" ARM void func_ov025_021eabd0(char* self, int party) {
    Slot021eabd0* slot = (Slot021eabd0*)_Z18GetSlotPtr02160f20Pv(_Z19GetActiveCombatWorkv());
    int found = -1;
    for (int i = 0; i < slot->count; i++) {
        void* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(slot, i);
        if (node == 0) continue;
        short idx = func_ov000_0215ffa0(node);
        if (party != 0) {
            if (IsPartyIndex(idx) != 0) {
                found = idx;
                break;
            }
        } else {
            if (IsPartyIndex(idx) == 0) {
                found = idx;
                break;
            }
        }
    }
    int type = 0;
    if (party != 0 && (slot->b0 || slot->b1)) {
        type = 5;
    } else if (party == 0 && (slot->b3 || slot->b4)) {
        type = 5;
    }
    int inParty = (found >= 0 && found <= 3) ? 1 : 0;
    int msg = inParty != 0 ? slot->partyMsgId : slot->enemyMsgId;
    func_ov025_021ed380(self + 0x5e8, msg, found, type, 0, -1, 0);
    self[0x5cc] = 1;
    if (party != 0) {
        data_ov025_021ef9a4 |= 0x800;
    } else {
        data_ov025_021ef9a4 |= 0x4000;
    }
}
