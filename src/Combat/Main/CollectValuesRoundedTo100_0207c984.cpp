#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPointerFromArray0xbd0(unsigned char* obj, unsigned int index);

struct Outer_02054000;
void* GetActiveSub_02054000(struct Outer_02054000* p);

extern short data_020e8a34[];

// USA: func_0207c984  (semantic: CollectValuesRoundedTo100_0207c984)
extern "C" ARM int func_0207c984(unsigned char* obj, int combatantId, int categoryId, short* outArr, short* outCount) {
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), combatantId);
    if (combatant == 0) {
        return 1;
    }

    void* sub = GetActiveSub_02054000((struct Outer_02054000*)combatant);
    short special = -1;
    if (sub != 0) {
        unsigned int packed = *(unsigned int*)((char*)sub + 0x8);
        unsigned int bits = (packed << 23) >> 27;
        if (bits <= 11) {
            special = *(short*)((char*)sub + 0x18);
        }
    }

    short count = 0;
    short target = data_020e8a34[categoryId];
    if (special > 0) {
        if ((short)(special - special % 100) == target) {
            outArr[count++] = special;
        }
    }

    short* arr = (short*)GetPointerFromArray0xbd0(obj, 0);
    short i;
    for (i = 0; i < 0x110; i++) {
        short v = arr[i];
        if (v != special) {
            if ((short)(v - v % 100) == target) {
                outArr[count] = v;
                count = count + 1;
            }
        }
    }

    *outCount = count;
    return 0;
}
