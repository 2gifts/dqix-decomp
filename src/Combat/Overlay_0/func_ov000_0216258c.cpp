#include <globaldefs.h>
#include "GameState/GameState.h"

struct HpMpGauge0216258c {
    char pad0[8];
    unsigned short maxHP;
    unsigned short maxMP;
    short currHP;
    short currMP;
};

struct CombatantFlags0216258c {
    char pad[0x14];
    unsigned int flags;
};

struct BattleUi0216258c {
    char pad0[0x2a0];
    unsigned char* activeBits;
    char pad2a4[0x3760 - 0x2a4];
    char gauges[1];
};

int TestBitAt0x34(unsigned char* obj, unsigned int index);
extern "C" HpMpGauge0216258c* func_ov000_02161318(void* obj, int index);
extern "C" void func_ov000_0217f518(HpMpGauge0216258c* gauge);
extern "C" void _Z24SetShortField0xC02176134P11Obj02176134s(HpMpGauge0216258c* gauge, unsigned short val);
extern "C" void _Z24SetShortField0xE02176150P11Obj02176150s(HpMpGauge0216258c* gauge, unsigned short val);

// USA: func_ov000_0216258c
extern "C" ARM void func_ov000_0216258c(BattleUi0216258c* self) {
    GameState* bs = GameState::GetInstance();
    for (int i = 0; i < 4; i++) {
        if (!TestBitAt0x34(self->activeBits, i & 0xff)) continue;
        GameObject* c = GetCombatantWithFlag0x100(bs, i);
        if (!c) continue;
        HpMpGauge0216258c* gauge = func_ov000_02161318(self->gauges, i);
        if (!gauge) continue;
        if (gauge->currHP == 0 && !(((CombatantFlags0216258c*)c->currentStats_)->flags & 1)) {
            func_ov000_0217f518(gauge);
        }
        unsigned short hp = c->currentStats_->primaryStats.currHP;
        _Z24SetShortField0xC02176134P11Obj02176134s(gauge, hp);
        gauge->currHP = hp;
        unsigned short mp = c->currentStats_->primaryStats.currMP;
        _Z24SetShortField0xE02176150P11Obj02176150s(gauge, mp);
        gauge->currMP = mp;
        gauge->maxHP = c->baseStats_->primaryStats.maxHP;
        gauge->maxMP = c->baseStats_->primaryStats.maxMP;
    }
}
