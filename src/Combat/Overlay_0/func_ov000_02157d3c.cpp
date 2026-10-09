#include <globaldefs.h>

struct ActionEntry {
    char pad0[0x20];
    short combatantId;
};

struct List02160094 {
    char pad0[8];
    unsigned char entryCount;
};

struct IdList {
    short v[8];
};

struct Battle {
    char pad0[0x81b1];
    unsigned char aliveCount : 4;
    unsigned char groupCount : 2;
    char pad81b2[0x8e14 - 0x81b2];
    signed char result;
};

extern IdList data_ov000_02182c74;

extern "C" void func_ov000_02155e94(Battle* battle);
extern "C" int func_ov000_0215e9fc(Battle* battle, short* buf, int max, int start);
extern "C" void func_ov000_0215858c(Battle* battle, int combatantId, ActionEntry* entry);
extern "C" void func_ov000_021599f4(Battle* battle, int combatantId);
extern "C" ActionEntry* _Z22GetNodeAtIndex02160094P12List02160094i(List02160094* list, int index);

// USA: func_ov000_02157d3c
extern "C" ARM void func_ov000_02157d3c(Battle* battle, List02160094* action, int flag) {
    func_ov000_02155e94(battle);
    IdList ids = data_ov000_02182c74;
    if (func_ov000_0215e9fc(battle, ids.v, 8, 9) <= 0) {
        battle->result = 2;
    } else if (battle->aliveCount == 0) {
        battle->result = 1;
    } else {
        battle->result = 0;
    }
    if (battle->result == 0 && flag == 0) {
        int i;
        for (i = 0; i < action->entryCount; i++) {
            ActionEntry* entry = _Z22GetNodeAtIndex02160094P12List02160094i(action, i);
            if (entry != 0) {
                func_ov000_0215858c(battle, entry->combatantId, entry);
                func_ov000_021599f4(battle, entry->combatantId);
            }
        }
    }
}
