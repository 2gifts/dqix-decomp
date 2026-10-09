#include <globaldefs.h>
#include <GameState/GameState.h>

struct EnemyGroup {
    char pad[6];
    unsigned char members[8];
    unsigned char count : 4;
    unsigned char flags : 4;
    char tail[9];
};
struct BattleRoster {
    char pad[0x81b0];
    union {
        struct {
            unsigned char field_0x81b0;
            unsigned char lowFlags : 4;
            unsigned char groupCount : 2;
            unsigned char highFlags : 2;
        };
        EnemyGroup groups[3];
    };
};
struct S_10088;
int IsFlag0x18Bit0x2000Set(GameObject*);
int IsFlag10088Set(S_10088*);

// USA: func_ov000_0215eb1c
extern "C" ARM int func_ov000_0215eb1c(BattleRoster* roster, short* output, int capacity, int flags) {
    int count = 0;
    for (int group = 0; group < roster->groupCount; group++) {
        for (int member = 0; member < roster->groups[group].count; member++) {
            short id = roster->groups[group].members[member] + 0xc0;
            GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(id);
            if (!combatant) continue;
            if (!(flags & 0x10) && IsFlag0x18Bit0x2000Set(combatant)) continue;
            if ((flags & 1) && IsFlag10088Set((S_10088*)combatant)) continue;
            output[count++] = id;
            if (count == capacity) return count;
        }
    }
    return count;
}
