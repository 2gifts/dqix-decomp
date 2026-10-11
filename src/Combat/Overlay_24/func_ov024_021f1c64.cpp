#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
extern "C" float func_ov024_021db358(GameObject* obj);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

extern unsigned short data_ov024_021fef7c;

// USA: func_ov024_021f1c64
extern "C" ARM int func_ov024_021f1c64(int* a0, int a1, int a2, int* outCount, short* outArray) {
    short buf[8];
    unsigned short* d = (unsigned short*)buf;
    unsigned short* s = &data_ov024_021fef7c;
    int n = 8;
    do {
        unsigned short* dd = d++;
        *dd = *s++;
    } while (--n);

    int count = func_ov000_0215eb1c(*a0, buf, 8, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantByID(*a0, buf[i]);
        if (!member) continue;
        if (func_ov024_021db358(member) >= 0.5f) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        outArray[idx] = buf[i];
    }
    if (*outCount <= 0) return 0;
    PickRandomTableEntryResetCounter_021ed890((struct Random**)a0, outCount, outArray);
    return 1;
}
