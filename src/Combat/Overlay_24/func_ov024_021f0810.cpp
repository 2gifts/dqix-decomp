#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
int CheckFlag0x14Bit0x10Set(unsigned char* obj);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);

extern unsigned short data_ov024_021feaac;

// USA: func_ov024_021f0810
extern "C" ARM int func_ov024_021f0810(int* a0, int a1, int a2, int* outCount, void* outArray) {
    unsigned short buf[4];
    unsigned short* d = buf;
    unsigned short* s = &data_ov024_021feaac;
    int n = 4;
    do {
        unsigned short* dd = d++;
        *dd = *s++;
    } while (--n);

    int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
    if (count <= 0) return 0;

    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(*a0, *(short*)&buf[i]);
        if (c && !CheckFlag0x14Bit0x10Set((unsigned char*)c->currentStats_) && !IsCombatantFlagMask512_021eda60(c)) {
            int flag47 = *((unsigned char*)c->currentStats_ + 0x47);
            if (flag47 > 0) found++;
        }
    }
    if (found * 3 < count * 2) return 0;

    *outCount = count;
    memcpy(outArray, buf, 8);
    return 1;
}
