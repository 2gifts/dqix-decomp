#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" int func_ov000_0215e9fc(int battle, short* buf, int max, int flag);
extern "C" int func_ov000_0215eb1c(int battle, short* buf, int max, int flag);
struct S_bf3c_021f0d0c;
extern "C" int _Z23IsBitfield1Set_021f0d0cP15S_bf3c_021f0d0c(struct S_bf3c_021f0d0c* obj);
struct RngHolder_021ed9dc { int field0; };
extern "C" int _Z27CanTargetCombatant_021ed9dcP18RngHolder_021ed9dci(struct RngHolder_021ed9dc* holder, int id);

struct Buf8_021f0e90 { short v[8]; };
extern struct Buf8_021f0e90 data_ov024_021feebc;

// USA: func_ov024_021f0e90
extern "C" ARM int func_ov024_021f0e90(struct RngHolder_021ed9dc* holder, int id, int unused, int* outCount, short* outArray) {
    GameObject* self = GetCombatantWithFlag0x400ByID(holder->field0, id);
    if (!self) return 0;
    if (!_Z23IsBitfield1Set_021f0d0cP15S_bf3c_021f0d0c((struct S_bf3c_021f0d0c*)self)) return 0;

    int found = 0;
    struct Buf8_021f0e90 buf = data_ov024_021feebc;
    int count = func_ov000_0215e9fc(holder->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    for (int i = 0; i < count; i++) {
        if (_Z27CanTargetCombatant_021ed9dcP18RngHolder_021ed9dci(holder, buf.v[i])) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;

    memset(buf.v, -1, sizeof(buf));
    count = func_ov000_0215eb1c(holder->field0, buf.v, 8, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(holder->field0, buf.v[i]);
        if (!c) continue;
        if (c->currentStats_->unkBuff18 >= 2) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        outArray[idx] = buf.v[i];
    }
    if (*outCount <= 0) return 0;

    *outCount = count;
    memcpy(outArray, buf.v, sizeof(buf));
    return 1;
}
