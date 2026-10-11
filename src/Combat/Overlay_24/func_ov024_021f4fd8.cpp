#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215e9fc(int battle, short* table, int count, int flag);

int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Buf4_021f4fd8 { short v[4]; };
extern struct Buf4_021f4fd8 data_ov024_021feb84;

// USA: func_ov024_021f4fd8  (semantic: SelectLowAgilityBuffAndMaybePick_021f4fd8)
extern "C" ARM int func_ov024_021f4fd8(int* a0, int a1, int a2, int* outCount, short* outArray) {
    struct Buf4_021f4fd8 buf = data_ov024_021feb84;

    int count = func_ov000_0215e9fc(*a0, buf.v, 4, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantByID(*a0, buf.v[i]);
        if (member && member->currentStats_->primaryStats.agility != 0 && member->currentStats_->agilityBuff > -2) {
            int idx = *outCount;
            *outCount = idx + 1;
            outArray[idx] = buf.v[i];
        }
    }
    if (*outCount > 0) {
        PickRandomTableEntryResetCounter_021ed890((struct Random**)a0, outCount, outArray);
        return 1;
    }
    return 0;
}
