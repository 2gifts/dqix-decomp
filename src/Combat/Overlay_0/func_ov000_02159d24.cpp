#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x144
#define REGION_OFFSET_1 0x8b8
#else
#define REGION_OFFSET_0 0x150
#define REGION_OFFSET_1 0x950
#endif

#include "GameState/GameState.h"

struct TableEntry02182d88 { short key; short pad; };
extern struct TableEntry02182d88 data_ov000_02182d88[];

struct TableEntry02182d8a { short value; short pad; };
extern struct TableEntry02182d8a data_ov000_02182d8a[];

// USA: func_ov000_02159d24
extern "C" ARM int func_ov000_02159d24(int unused, int combatantId) {
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), combatantId);
    if (combatant == 0) {
        return 0;
    }
    int i = 0;
    goto test;
    do {
        short key = data_ov000_02182d88[i].key;
        int base = *(int*)((char*)combatant + REGION_OFFSET_0);
        int field950 = *(int*)((char*)base + REGION_OFFSET_1);
        if (key == field950) {
            return data_ov000_02182d8a[i].value;
        }
        i++;
test:
        ;
    } while (data_ov000_02182d88[i].key != -1);
    return 0;
}
