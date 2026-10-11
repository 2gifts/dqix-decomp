#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215eb1c(int battle, unsigned short* table, int count, int flag);
extern "C" float func_ov024_021db358(GameObject* obj);

extern unsigned short data_ov024_021fec6c;

#pragma opt_common_subs off
// USA: func_ov024_021f20b8  (semantic: SelectLowHPQuorumAndCopyTable_021f20b8)
extern "C" ARM int func_ov024_021f20b8(int* a0, int a1, int a2, int* outCount, short* outArray) {
    unsigned short buf[8];
    float threshold;
    unsigned short* p;
    unsigned short* d = buf;
    unsigned short* s = &data_ov024_021fec6c;
    int n = 8;
    do {
        unsigned short* dd = d++;
        *dd = *s++;
    } while (--n);

    int count = func_ov000_0215eb1c(*a0, buf, 8, 1);
    if (count <= 0) return 0;

    p = buf;
    threshold = 0.5f;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantByID(*a0, *(short*)&p[i]);
        if (!member) continue;
        if (func_ov024_021db358(member) >= threshold) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        outArray[idx] = *(short*)&p[i];
    }
    if (*outCount <= 0) return 0;
    if (*outCount * 3 < count * 2) return 0;

    *outCount = count;
    memcpy(outArray, buf, 0x10);
    return 1;
}
