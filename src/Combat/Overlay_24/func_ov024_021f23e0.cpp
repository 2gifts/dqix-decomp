#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" int func_ov024_021edf00(int* context, int id, short* ids);
extern "C" int func_ov000_0215e9fc(int battle, short* ids, int max, int flags);
extern "C" void func_ov024_021ed8c0(void* context, int id, int record, int* count, short* ids);
extern unsigned short data_ov024_021fea9c[4];

// JPN: func_ov024_021f2bac
// USA: func_ov024_021f23e0
extern "C" ARM int func_ov024_021f23e0(int* context, unsigned char id, void* record,
    int* outCount, short* outIDs) {
    short ids[4];
    short* dest = ids;
    unsigned short* source = data_ov024_021fea9c;
    int n = 4;
    do {
        short* d = dest++;
        *(unsigned short*)d = *source++;
    } while (--n);
    int count = func_ov024_021edf00(context, id, ids);
    if (count <= 0) {
        count = func_ov000_0215e9fc(*context, ids, 4, 1);
        if (count <= 0) return 0;
    }
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* combatant = GetCombatantByID(*context, ids[i]);
        if (combatant) {
            if (combatant->currentStats_->unkBuff18 > -2) {
                int index = *outCount;
                *outCount = index + 1;
                outIDs[index] = ids[i];
            }
        }
    }
    if (*outCount <= 0) return 0;
    func_ov024_021ed8c0(context, id, (int)record, outCount, outIDs);
    return 1;
}
