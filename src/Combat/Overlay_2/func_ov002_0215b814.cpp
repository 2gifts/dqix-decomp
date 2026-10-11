#include <globaldefs.h>

struct BattleStruct;
struct StatsA {
    int unk0;
    unsigned short unk4;
    unsigned short unk6;
};
struct StatsB {
    char name[0x30];
    unsigned short unk30;
    unsigned short unk32;
};
struct CombatantStruct {
    char unk[0x130];
    struct StatsA *a;
    struct StatsB *b;
};
struct Entry {
    char name[0x30];
    int unk30;
    unsigned short unk34;
    unsigned short unk36;
    unsigned short unk38;
    unsigned short unk3a;
};
extern "C" struct BattleStruct *_ZN9GameState11GetInstanceEv();
extern "C" struct CombatantStruct *_Z25GetCombatantWithFlag0x100P9GameStatei(struct BattleStruct *gs, int id);
extern "C" void *memset(void *dst, int c, unsigned int n);
extern "C" int sprintf(char *buf, const char *fmt, ...);

// USA: func_ov002_0215b814
extern "C" ARM void func_ov002_0215b814(char *self) {
    struct BattleStruct *gs = _ZN9GameState11GetInstanceEv();
    struct Entry *e;
    int i;
    for (i = 0; i < 4; i++) {
        e = (struct Entry *) (self + 0x1ab0) + i;
        memset(e, 0, 4);
        struct CombatantStruct *c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, i);
        if (c != 0 && c->b->name[0] != 0) {
            sprintf(e->name, c->b->name);
            e->unk34 = c->a->unk4;
            e->unk36 = c->b->unk30;
            e->unk38 = c->a->unk6;
            e->unk3a = c->b->unk32;
            e->unk30 = c->a->unk0;
        }
    }
}
