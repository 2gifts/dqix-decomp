#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" float func_ov024_021db358(GameObject* obj);
extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
extern const short data_ov024_021fee2c[8] __attribute__((aligned(4)));

// USA: func_ov024_021f38f0
extern "C" ARM int func_ov024_021f38f0(int* context, int id, void* unusedResource, int* outCount, short* outTargets) {
    GameObject* incoming = GetCombatantWithFlag0x400ByID(*context, id);
    if (!incoming) return 0;
    if (func_ov024_021db358(incoming) < 0.5f) return 0;

    short table[8];
    const short* source = data_ov024_021fee2c;
    short* destination = table;
    int remaining = 8;
    do {
        *(unsigned short*)destination++ = *(const unsigned short*)source++;
    } while (--remaining);

    int count = func_ov000_0215eb1c(*context, table, 8, 1);
    if (count <= 0) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        if (table[i] == id) continue;
        GameObject* combatant = GetCombatantByID(*context, table[i]);
        if (!combatant) continue;
        if (func_ov024_021db358(combatant) >= 0.5f) continue;
        int index = *outCount;
        *outCount = index + 1;
        outTargets[index] = table[i];
    }
    if (*outCount * 3 < count) return 0;
    *outCount = 1;
    outTargets[0] = id;
    return 1;
}
