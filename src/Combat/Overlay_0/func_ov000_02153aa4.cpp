#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" void __clear(void* buf, int size);

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);

struct EnemyGroup02153aa4 {
    unsigned short value;
    unsigned char members[8];
    unsigned char total : 4;
    unsigned char alive : 4;
    char pad[0x18 - 0xb];
};

struct GroupCount02153aa4 {
    unsigned char counter : 4;
    unsigned char groupCount : 2;
    unsigned char unused : 2;
};

struct BattleAI02153aa4 {
    Random random;
    char pad0[0x81b1 - sizeof(Random)];
    GroupCount02153aa4 counts;
    char pad1[2];
    EnemyGroup02153aa4 groups[3];
};

static inline GameObject* GetCombatant(short idx) {
    return GameState::GetInstance()->GetCombatantByIndex(idx);
}

// USA: func_ov000_02153aa4
extern "C" ARM void func_ov000_02153aa4(BattleAI02153aa4* ai, int groupIdx, int* target) {
    short idx = *target;
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(idx);
    if (c == NULL) {
        return;
    }
    if (!IsFlag10088Set((struct S_10088*)c) && !IsFlag0x18Bit0x2000Set(c)) {
        return;
    }
    EnemyGroup02153aa4* groups = ai->groups;
    int groupBuf[3];
    __clear(groupBuf, 0xc);
    int* gbuf = groupBuf;
    int count = 0;
    if (groups[groupIdx].alive == 0) {
        for (int i = 0; i < ai->counts.groupCount; i++) {
            if (groups[i].alive != 0) {
                gbuf[count++] = i;
            }
        }
        groupIdx = gbuf[NextRandomMax(&ai->random, count)];
    }

    int n;
    unsigned char* members;
    int j;
    int id;
    EnemyGroup02153aa4* group;
    int* idp;
    int ids[8];
    __clear(ids, 0x20);
    n = 0;
    group = &groups[groupIdx];
    members = group->members;
    idp = ids;
    for (j = 0; j < group->total; j++) {
        id = members[j] + 0xc0;
        GameObject* m = GetCombatant(id);
        if (m != NULL && !IsFlag10088Set((struct S_10088*)m) && !IsFlag0x18Bit0x2000Set(m)) {
            idp[n] = id;
            n++;
        }
    }
    *target = idp[NextRandomMax(&ai->random, n)];
}
