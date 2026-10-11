#include "GameState/GameState.h"
#include <globaldefs.h>

extern "C" void *func_0202ae18(void);
extern "C" void func_ov002_02153e90(void *entry);
extern "C" int func_ov002_02154a6c(void *self, int idA, int idB);
extern "C" int _Z36HasPositiveField256Short178_02154b94Pvi(void *self, int id);
GameObject *GetCombatantWithFlag0x100(GameState *gameState, int combatantId);
extern "C" short func_02084a64(void *a, int b);
extern "C" void func_02083e28(void *a, int arg2);
int CheckField0NonZero(int *p);
extern "C" void func_ov017_021cf078(int id, unsigned char b, int c);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

struct Entry021546c8 {
    unsigned char kind;
    char pad1;
    short val;
    char pad4[2];
};

struct Req021546c8 {
    short s0;
    signed char b2;
    unsigned char count;
    signed char ids[4];
    struct Entry021546c8 entries[4];
    struct Entry021546c8 alt[4];
};

// USA: func_ov002_021546c8
extern "C" ARM int func_ov002_021546c8(void *self, struct Req021546c8 *req, void *other, int useAlt) {
    if (req == NULL) return 0;
    if (other == NULL) return 0;

    GameState *gs              = GameState::GetInstance();
    void *w                    = func_0202ae18();
    int ret                    = 0;
    struct Entry021546c8 *ents = req->entries;
    if (useAlt) ents = req->alt;

    int i;
    for (i = 0; i < 4; i++) {
        func_ov002_02153e90(&ents[i]);
    }

    for (i = 0; i < req->count; i++) {
        struct Entry021546c8 *e = &ents[i];
        int id                  = req->ids[i];
        if (!func_ov002_02154a6c(self, id, req->b2)) {
            e->kind = 1;
            continue;
        }
        if (_Z36HasPositiveField256Short178_02154b94Pvi(self, id)) {
            e->kind = 2;
            continue;
        }
        GameObject *m = GetCombatantWithFlag0x100(gs, id);
        if (m == NULL) continue;
        e->val = func_02084a64(*(void **) ((char *) m + 0x150), req->s0);
        if (e->val <= 0) continue;
        e->kind = 3;
        func_02083e28(*(void **) ((char *) m + 0x150), 0);
        if (CheckField0NonZero((int *) w)) {
            func_ov017_021cf078(id, *(int *) (*(char **) ((char *) m + 0x150) + 0x950) & 0xff, 1);
            func_ov017_021c9e00(id, 0, 0, 1);
        }
        ret = 1;
    }
    return ret;
}
