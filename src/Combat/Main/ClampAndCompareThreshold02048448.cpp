#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150_02053c6c(unsigned char* obj);
int TestBitInArray0x8ec_02083b00(unsigned char* obj, int index);

struct Threshold02048448 {
    char pad[0x6];
    unsigned short value;
};

struct Struct02048448 {
    char pad[0x4];
    short combatantId;
    char pad2[0x130 - 0x6];
    struct Threshold02048448* threshold;
};

// USA: func_02048448
ARM int ClampAndCompareThreshold02048448(struct Struct02048448* s, int val) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(bs, s->combatantId);
    if (combatant != NULL) {
        unsigned char* ptr = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
        if (ptr != NULL) {
            if (TestBitInArray0x8ec_02083b00(ptr, 0x106)) {
                val = (int)(0.75f + 0.75f * (float)val);
                if (val <= 0) {
                    val = 0;
                }
            }
        }
    }
    return val <= s->threshold->value ? 1 : 0;
}
