#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int battle, unsigned short* table, int count, int flag);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);
extern "C" float func_ov024_021db358(GameObject* obj);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

extern unsigned short data_ov024_021fec9c;

#pragma opt_common_subs off
// USA: func_ov024_021ee6a8  (semantic: SelectLowHPUnflaggedAndMaybePick_021ee6a8)
extern "C" ARM int func_ov024_021ee6a8(int* a0, int a1, int a2, int* outCount, short* outArray) {
    unsigned short buf[8];
    unsigned short* p;
    unsigned short* d = buf;
    unsigned short* s = &data_ov024_021fec9c;
    int n = 8;
    do {
        unsigned short* dd = d++;
        *dd = *s++;
    } while (--n);

    int count = func_ov000_0215eb1c(*a0, buf, 8, 1);
    if (count <= 0) return 0;

    p = buf;
    float threshold = 0.5f;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantByID(*a0, *(short*)&p[i]);
        if (!member) continue;
        if (IsCombatantFlagMask512_021eda60(member)) continue;
        if (func_ov024_021db358(member) >= threshold) continue;
        outArray[*outCount] = *(short*)&p[i];
        (*outCount)++;
    }
    if (*outCount <= 0) return 0;
    PickRandomTableEntryResetCounter_021ed890((struct Random**)a0, outCount, outArray);
    return 1;
}
