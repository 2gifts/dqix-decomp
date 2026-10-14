#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

struct Entry {
    char name[0x30];
    int unk30;
    unsigned short unk34;
    unsigned short unk36;
    unsigned short unk38;
    unsigned short unk3a;
};
extern "C" void *memset(void *dst, int c, unsigned int n);
extern "C" int sprintf(char *buf, const char *fmt, ...);

// USA: func_ov002_0215b814
extern "C" ARM void func_ov002_0215b814(char *self) {
    GameState *gs = GameState::GetInstance();
    struct Entry *e;
    int i;
    for (i = 0; i < 4; i++) {
        e = (struct Entry *) (self + 0x1ab0) + i;
        memset(e, 0, 4);
        GameObject *c = GetCombatantWithFlag0x100_0200ff1c(gs, i);
        if (c != 0 && c->baseStats_->unk[0] != 0) {
            sprintf(e->name, c->baseStats_->unk);
            e->unk34 = c->combatFields_.savedState_130_->hp;
            e->unk36 = c->baseStats_->primaryStats.maxHP;
            e->unk38 = c->combatFields_.savedState_130_->mp;
            e->unk3a = c->baseStats_->primaryStats.maxMP;
            e->unk30 = c->combatFields_.savedState_130_->flags;
        }
    }
}
