#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
struct FlagObj_021de25c;
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

extern unsigned short data_ov024_021feb24;

// USA: func_ov024_021f5f6c  (semantic: SelectEligiblePositiveStatAndPick_021f5f6c)  (semantic: SelectEligiblePositiveStatAndPick_021f5f6c)
extern "C" ARM int func_ov024_021f5f6c(int* a0, int a1, int a2, int* outCount, short* outArray) {
    unsigned short buf[4];
    unsigned short* s = &data_ov024_021feb24;
    unsigned short* d = buf;
    int n = 4;
    do {
        unsigned short* dd = d++;
        *dd = *s++;
    } while (--n);

    int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantByID(*a0, *(short*)&buf[i]);
        if (!member) continue;
        if (IsFlagBit5Set_021de25c((struct FlagObj_021de25c*)member)) continue;
        if (IsCombatantFlagMask512_021eda60(member)) continue;
        unsigned char* p = (unsigned char*)member->currentStats_;
        int v = p[0x4a];
        if (v <= 0) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        outArray[idx] = *((short*)buf + i);
    }
    if (*outCount > 0) {
        PickRandomTableEntryResetCounter_021ed890((struct Random**)a0, outCount, outArray);
        return 1;
    }
    return 0;
}
