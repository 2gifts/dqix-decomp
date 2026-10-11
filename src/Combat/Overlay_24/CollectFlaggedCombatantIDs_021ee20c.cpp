#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" void __clear(void* dst, int count);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);

extern unsigned short data_ov024_021feb34;

// USA: func_ov024_021ee20c  (semantic: CollectFlaggedCombatantIDs_021ee20c)
extern "C" ARM int func_ov024_021ee20c(int* a0, int a1, int a2, int* a3, short* a4) {
    short buf[4];
    short* d = buf;
    unsigned short* s = &data_ov024_021feb34;
    int n = 4;
    do {
        short* dd = d++;
        *dd = *s++;
    } while (--n);

    int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
    if (count <= 0) return 0;

    short out[4];
    __clear(out, 8);

    int i;
    unsigned short outCount;
    outCount = 0;
    i = 0;
    for (; i < count; i++) {
        GameObject* c = GetCombatantByID(*a0, buf[i]);
        if (c && IsCombatantFlagMask512_021eda60(c)) {
            out[outCount] = buf[i];
            outCount++;
        }
    }
    if (outCount * 3 >= count) return 0;

    *a3 = count;
    memcpy(a4, buf, 8);
    return 1;
}
