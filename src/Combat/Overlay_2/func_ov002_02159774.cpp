#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

extern "C" int func_020dc920(int a, int b, int c, int d);
int TestFlagBit55dIfActive_0218b628(int bit);
extern int data_020fdcb0[][8];

struct Stat02159774 {
    unsigned char pad[0x34];
    unsigned short cur;
    unsigned short max;
    unsigned char pad38[4];
};

// USA: func_ov002_02159774
extern "C" ARM int func_ov002_02159774(char *self, int id, int check, int a, unsigned char b) {
    GameObject *c;
    float cur, max, ratio;
    int res;
    c = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), id);
    if (c == 0) return 3;
    if (check) {
        int special = 0;
        if (*(short *) (self + 0x1c26) == 0xd1) special = 1;
        if (func_020dc920(id & 0xff, a, b, special) == 0) return 3;
    }
    int *e = data_020fdcb0[c->obj3D_.unknown_4_];
    cur    = (float) e[0];
    max    = (float) e[2];
    if ((*(int *) (self + 0x247c) & 1) || *(int *) (self + 0x1bb8) == 4) {
        if (TestFlagBit55dIfActive_0218b628((signed char) id)) {
            cur = (float) (int) c->combatFields_.savedState_130_->hp;
            max = (float) (int) c->baseStats_->primaryStats.maxHP;
        } else {
            Stat02159774 *s = &((Stat02159774 *) (self + 0x1ab0))[c->obj3D_.unknown_4_];
            cur             = (float) (unsigned int) s->cur;
            max             = (float) (unsigned int) s->max;
        }
    }
    ratio = 0.0f;
    if (cur > 0.0f && max > 0.0f) ratio = cur / max;
    res = 0xf;
    if (ratio <= 0.0f)
        res = 9;
    else if (ratio <= 0.08f)
        res = 0xb;
    else if (ratio <= 0.25f)
        res = 0xd;
    return res;
}
