#include <globaldefs.h>

struct ListNode021600f8 {
    char pad0[0x14];
    unsigned char states[3];
    unsigned char count;
};
struct List021600f8 {
    char pad0[6];
    short actorId;
    unsigned char field8;
    unsigned char count;
    char padA[2];
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 1;
    unsigned char flags5 : 3;
    char padD[0x1a-0xd];
    unsigned short partyAction;
    unsigned short monsterAction;
};
struct ActionDisplay {
    char pad0[0x5cc];
    unsigned char active;
    char pad5cd[3];
    unsigned char blocked;
    unsigned char enabled;
    char pad5d2[0x5e8-0x5d2];
    unsigned char command[1];
};
void* GetActiveCombatWork();
extern "C" List021600f8* _Z18GetSlotPtr02160f20Pv(void*);
extern "C" ListNode021600f8* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8*, int);
extern "C" short func_ov000_0215ffa0(ListNode021600f8*);
extern "C" void func_ov025_021ed380(void*, unsigned short, short, int, int, int, int);
extern "C" void func_ov025_021ead5c(ActionDisplay*, int);
extern unsigned int data_ov025_021ef9a4;

inline int IsPartyActor(int id) { return id >= 0 && id <= 3; }

// USA: func_ov025_021ea958
extern "C" ARM void func_ov025_021ea958(ActionDisplay* display, int party, int update, int actorId) {
    if (party && (data_ov025_021ef9a4 & 0x800)) return;
    if (!party && (data_ov025_021ef9a4 & 0x4000)) return;
    List021600f8* list = _Z18GetSlotPtr02160f20Pv(GetActiveCombatWork());
    if (display->blocked && !display->enabled) return;
    if (party && (list->flag0 || list->flag1)) actorId = -2;
    else if (!party && (list->flag3 || list->flag4)) actorId = -2;
    for (int i = 0; i < list->count; i++) {
        ListNode021600f8* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, i);
        if (node) {
            for (int j = 1; j < node->count; j++) {
                if (node->states[j] == 1 || node->states[j] == 2) return;
            }
        }
    }
    int forced = 0;
    if (actorId == -2) forced = 1;
    if (actorId < 0) {
        for (int i = 0; i < list->count; i++) {
            ListNode021600f8* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, i);
            if (node) {
                int id = func_ov000_0215ffa0(node);
                if (party) {
                    if (IsPartyActor(id)) { actorId = id; break; }
                } else if (!IsPartyActor(id)) { actorId = id; break; }
            }
        }
    }
    int action = IsPartyActor(actorId) ? list->partyAction : list->monsterAction;
    if ((action == 0xf1 || action == 0xf2) && list->actorId != actorId) return;
    int mode = 0;
    if (forced) mode = 5;
    func_ov025_021ed380(display->command, action, actorId, mode, 0, -1, 0);
    display->active = 1;
    if (update) func_ov025_021ead5c(display, party);
    if (party) data_ov025_021ef9a4 |= 0x800;
    else data_ov025_021ef9a4 |= 0x4000;
}
