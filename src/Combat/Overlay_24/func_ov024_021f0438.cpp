#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021edf00(int* context, int id, short* ids);
extern "C" int func_ov000_0215e9fc(int context, short* ids, int max, int start);
extern "C" void func_ov024_021ed8c0(void* context, int id, int record, int* count, short* ids);
extern "C" int _Z31IsCombatantFlagMask512_021eda60P10GameObject(GameObject* combatant);

extern unsigned short data_ov024_021fea6c[4];

// USA: func_ov024_021f0438
extern "C" ARM int func_ov024_021f0438(int* context, int id, int record, int* outCount, short* outIDs) {
    short buf[4];
    short* destination = buf;
    unsigned short* source = data_ov024_021fea6c;
    int remaining = 4;
    do {
        short* item = destination++;
        *item = *source++;
    } while (--remaining);

    int count = func_ov024_021edf00(context, id, buf);
    if (count <= 0) {
        count = func_ov000_0215e9fc(*context, buf, 4, 1);
        if (count <= 0) return 0;
    }
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* combatant = GetCombatantByID(*context, buf[i]);
        if (combatant && combatant->currentStats_->primaryStats.attack != 0 &&
            combatant->currentStats_->attackBuff > -2 &&
            !_Z31IsCombatantFlagMask512_021eda60P10GameObject(combatant) &&
            (int)((unsigned char*)combatant->currentStats_)[0x4f] > 0) {
            int index = *outCount;
            *outCount = index + 1;
            outIDs[index] = buf[i];
        }
    }
    if (*outCount <= 0) return 0;
    func_ov024_021ed8c0(context, id, record, outCount, outIDs);
    return 1;
}
