#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"

struct ActionEntry_02153f98 {
    char pad0[0x14];
    unsigned int : 28;
    unsigned int kind : 4;
};

struct ShortList8 {
    short v[8];
};

void* GetData02108e10(void);
extern "C" struct ActionEntry_02153f98* _Z24SearchBothTables02079e2cPci(char* p, int key);
extern "C" int func_ov000_0215e9fc(struct Random* rand, short* buf, int max, int start);

extern struct ShortList8 data_ov000_02182b24;

// USA: func_ov000_02153f98
extern "C" ARM int func_ov000_02153f98(struct Random* rand, int id, int action, short* out) {
    GameState* gs = GameState::GetInstance();
    struct ActionEntry_02153f98* entry = _Z24SearchBothTables02079e2cPci((char*)GetData02108e10(), (short)action);
    if (entry == NULL) {
        return 0;
    }
    if (GetCombatantWithFlag0x100(gs, id) == NULL) {
        return 0;
    }
    unsigned int kind = entry->kind;
    int count = func_ov000_0215e9fc(rand, out, 8, 1);
    if (kind == 2) {
        *out = out[NextRandomMax(rand, count)];
        count = 1;
    } else if (kind == 8) {
        struct ShortList8 list = data_ov000_02182b24;
        short n = 0;
        short* p = list.v;
        for (int i = 0; i < count; i++) {
            if (id != out[i]) {
                p[n] = out[i];
                n++;
            }
        }
        *out = p[NextRandomMax(rand, n)];
        count = 1;
    } else {
        *out = id;
        count = 1;
    }
    return count;
}
