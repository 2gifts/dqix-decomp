#include <globaldefs.h>

class GameState;

extern "C" GameState *_ZN9GameState11GetInstanceEv();
unsigned char *GetCombatantWithFlag0x100(GameState *gs, int slot);
extern "C" int func_020dc920(int a, int b, int c, int d);
extern "C" int _Z31TestFlagBit55dIfActive_0218b628i(int bit);
extern int data_020fdcb0[][8];

struct Stat02159774 {
    unsigned char pad[0x34];
    unsigned short cur;
    unsigned short max;
    unsigned char pad38[4];
};

// USA: func_ov002_02159774
extern "C" ARM int func_ov002_02159774(char *self, int id, int check, int a, unsigned char b) {
    unsigned char *c;
    float cur, max, ratio;
    int res;
    c = GetCombatantWithFlag0x100(_ZN9GameState11GetInstanceEv(), id);
    if (c == 0) return 3;
    if (check) {
        int special = 0;
        if (*(short *) (self + 0x1c26) == 0xd1) special = 1;
        if (func_020dc920(id & 0xff, a, b, special) == 0) return 3;
    }
    int *e = data_020fdcb0[*(short *) (c + 4)];
    cur    = (float) e[0];
    max    = (float) e[2];
    if ((*(int *) (self + 0x247c) & 1) || *(int *) (self + 0x1bb8) == 4) {
        if (_Z31TestFlagBit55dIfActive_0218b628i((signed char) id)) {
            cur = (float) (int) *(unsigned short *) (*(unsigned char **) (c + 0x130) + 4);
            max = (float) (int) *(unsigned short *) (*(unsigned char **) (c + 0x134) + 0x30);
        } else {
            Stat02159774 *s = &((Stat02159774 *) (self + 0x1ab0))[*(short *) (c + 4)];
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
