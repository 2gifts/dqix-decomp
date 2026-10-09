#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0217538c(void* list);
int TestBitInArray0x8ec(unsigned char* obj, int index);
int CountNodesFieldBitClear02175f80(void* obj);
int CountNodesWithFlag0217f5dc(void* obj);

struct Data02184288 {
    int field0;
    int field4;
    void* list;
};
extern struct Data02184288 data_ov000_02184288;
extern int data_ov000_02183ff0;

struct Action02171210 {
    char pad0[4];
    unsigned int id : 12;
    unsigned int pad4 : 20;
    unsigned int pad8 : 8;
    unsigned int mode : 2;
    unsigned int pad8b : 22;
    char padC[0x14 - 0xc];
    unsigned int pad14 : 28;
    unsigned int kind : 4;
};

struct Target02171210 {
    char pad0[0x1d];
    signed char field1d;
    char pad1e[0x21 - 0x1e];
    signed char field21;
    char pad22[0x2e - 0x22];
    signed char field2e;
    char pad2f[0x4c - 0x2f];
    int combatantId;
    char pad50[0x434 - 0x50];
    int field434;
};

// USA: func_ov000_02171210
extern "C" ARM int func_ov000_02171210(struct Action02171210* action, struct Target02171210* target) {
    if (action->mode == 1) {
        target->field1d = 0;
        target->field21 = -1;
        target->field2e = -1;
        int kind = action->kind;
        if (kind == 3) {
            return 100;
        }
        if (kind == 4) {
            if (data_ov000_02184288.list != NULL && func_ov000_0217538c(data_ov000_02184288.list) == 1) {
                return 100;
            }
        } else if (data_ov000_02184288.field4 == 1) {
            return 100;
        }
        target->field434 = 0;
        return 0xe;
    } else if (action->mode == 2) {
        GameState::GetInstance();
        target->field1d = -1;
        target->field21 = 0;
        int kind = action->kind;
        if (kind == 6) {
            GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), target->combatantId);
            if (combatant != NULL) {
                kind = 2;
                if (TestBitInArray0x8ec(*(unsigned char**)((char*)combatant + 0x150), 0xe6)) {
                    kind = 3;
                }
            }
        }
        int countA = 1;
        int countB = 1;
        if (data_ov000_02184288.list != NULL) {
            countA = CountNodesFieldBitClear02175f80(data_ov000_02184288.list);
            countB = CountNodesWithFlag0217f5dc(data_ov000_02184288.list);
        }
        switch (kind) {
        case 3:
        case 4:
            target->field2e = target->combatantId;
            return 100;
        case 8:
            if (data_ov000_02184288.list != NULL) {
                if (data_ov000_02183ff0 == 1 || countA == 1 || countB == 1) {
                    return 0x1e;
                }
            }
            return 0x14;
        case 1:
            if ((action->id == 0xb9 || action->id == 0xb6) && data_ov000_02184288.list != NULL) {
                if (data_ov000_02183ff0 == 1 || countA == 1 || countB == 1) {
                    return 0x1e;
                }
            }
            target->field21 = 0;
            target->field2e = target->combatantId;
            return 100;
        case 7:
            if (countB != 1) {
                return 0x13;
            }
            target->field21 = 0;
            target->field2e = target->combatantId;
            return 100;
        default:
            if (countB != 1) {
                return 0x12;
            }
            target->field21 = 0;
            target->field2e = target->combatantId;
            return 100;
        }
    }
    return 100;
}
