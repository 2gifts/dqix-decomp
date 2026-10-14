#include <globaldefs.h>
#include "GameState/GameState.h"

void ClearSubstructBytes_0200fb40(void* obj);
extern "C" void func_02092d60(void* s, int b);

struct BattlePhaseState02093080 {
    char unk0[0x34];
    unsigned char field34;
    unsigned char field35;
};

// USA: func_02093080
ARM void AdvanceBattlePhase02093080(struct BattlePhaseState02093080* s) {
    GameState* bs = GameState::GetInstance();
    unsigned char state = s->field35;
    if (state == 0) {
        ClearSubstructBytes_0200fb40(bs);
        func_02092d60(s, 1);
        s->field35++;
        return;
    }
    if (state == 1) {
        s->field34 = 2;
        s->field35 = 0;
    }
}
