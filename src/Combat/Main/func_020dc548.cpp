#include <globaldefs.h>
#include "GameState/GameState.h"

void FilterSlotsWithFlag0x800020dc4d0(signed char*, signed char*);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
int GetSignedByte0x2d0_020546a8(void*);
static inline int ValidPartyIndex(int index) { return index >= 0 && index <= 3; }

// USA: func_020dc548
extern "C" ARM void func_020dc548(int index, signed char* out, signed char* outCount) {
    if (!ValidPartyIndex(index)) { *outCount = 0; return; }
    GameState* game = GameState::GetInstance();
    signed char slots[4], count;
    FilterSlotsWithFlag0x800020dc4d0(slots, &count);
    signed char groups[4][4];
    int leader = -1;
    signed char member = 0;
    signed char group = 0;
    signed char groupCounts[4] = {};
    for (signed char i = 0; i < count; ++i) {
        int slot = slots[i];
        GameObject* object = GetCombatantWithFlag0x1000_0200ff58(game, slot);
        if (object) {
            if (leader == GetSignedByte0x2d0_020546a8(object)) {
                groups[group][member] = slot;
                ++groupCounts[group];
                ++member;
            }
        } else {
            game->GetPartyMemberByIndex(slot);
            if (leader >= 0) ++group;
            groups[group][0] = slot;
            ++groupCounts[group];
            member = 0;
            ++member;
            leader = slot;
        }
    }
    for (signed char i = 0; i < 4; ++i) {
        bool found = false;
        for (signed char j = 0; j < groupCounts[i]; ++j) {
            if (index == groups[i][j]) found = true;
        }
        if (found) {
            if (out) memcpy(out, groups[i], groupCounts[i]);
            *outCount = groupCounts[i];
            break;
        }
    }
}
