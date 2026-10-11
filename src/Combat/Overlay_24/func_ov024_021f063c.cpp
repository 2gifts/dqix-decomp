#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

struct FlagInner_021de25c { char unk[0x14]; int flags; };
struct FlagObj_021de25c { char unk[0x138]; struct FlagInner_021de25c* inner; };

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);

extern unsigned short data_ov024_021febcc;

// USA: func_ov024_021f063c
extern "C" ARM int func_ov024_021f063c(int* a0, int a1, int a2, int* outCount, short* outArray) {
    unsigned short buf[4];
    unsigned short* s = &data_ov024_021febcc;
    unsigned short* d = buf;
    int n = 4;
    do {
        unsigned short* dd = d++;
        *dd = *s++;
    } while (--n);

    int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
    if (count <= 0) return 0;

    int validCount = 0;
    int i = validCount;
    for (i = 0; i < count; i++) {
        GameObject* member = GetCombatantByID(*a0, *(short*)&buf[i]);
        if (!member) continue;
        if (IsFlagBit5Set_021de25c((struct FlagObj_021de25c*)member)) continue;
        if (IsCombatantFlagMask512_021eda60(member)) continue;
        unsigned char* p = (unsigned char*)member->currentStats_;
        int v = p[0x4a];
        if (v > 0) validCount++;
    }
    if (validCount * 3 < count * 2) return 0;

    *outCount = count;
    memcpy(outArray, buf, 8);
    return 1;
}
