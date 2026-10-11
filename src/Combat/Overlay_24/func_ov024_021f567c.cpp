#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Buf4_021f567c { short v[4]; };
extern struct Buf4_021f567c data_ov024_021fec4c;

// USA: func_ov024_021f567c
extern "C" ARM int func_ov024_021f567c(int* a0, int a1, int a2, int* outFlag, short* outArr) {
    struct Buf4_021f567c buf = data_ov024_021fec4c;
    int count = func_ov000_0215e9fc(*a0, buf.v, 4, 1);
    if (count <= 0) return 0;
    *outFlag = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(*a0, buf.v[i]);
        if (!c) continue;
        void* inner = *(void**)((char*)c + 0x138);
        if (*(unsigned short*)((char*)inner + 2) == 0) continue;
        if (IsCombatantFlagMask512_021eda60(c)) continue;
        int n = *outFlag;
        *outFlag = n + 1;
        outArr[n] = buf.v[i];
    }
    if (*outFlag > 0) {
        PickRandomTableEntryResetCounter_021ed890((struct Random**)a0, outFlag, outArr);
        return 1;
    }
    return 0;
}
