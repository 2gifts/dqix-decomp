#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);

struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2(struct S88514* obj);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Buf8_021f4880 { short v[8]; };
extern struct Buf8_021f4880 data_ov024_021fec7c;

// USA: func_ov024_021f4880  (semantic: SelectKind1OrState2AndMaybePick_021f4880)
extern "C" ARM int func_ov024_021f4880(int* a0, int a1, int a2, int* outCount, short* outArray) {
    struct Buf8_021f4880 buf = data_ov024_021fec7c;

    int count = func_ov000_0215eb1c(*a0, buf.v, 8, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantByID(*a0, buf.v[i]);
        if (member && (CheckFlag0x2AndKind1((struct Combatant_20885b4*)member->currentStats_) ||
                       CheckFlag0x2AndState2((struct S88514*)member->currentStats_))) {
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
