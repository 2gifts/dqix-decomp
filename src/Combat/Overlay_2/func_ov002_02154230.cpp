#include "GameState/GameState.h"
#include "Util/Random.h"
#include <globaldefs.h>

struct ArrayContainsByteStruct;
int ArrayContainsByte(ArrayContainsByteStruct *arr, int value);
int CheckField0NonZero(int *p);
extern "C" int _Z36HasPositiveField256Short178_02154b94Pvi(void *self, int id);
extern "C" int _Z34HasPositiveField304Short4_02154a34Pvi(void *self, int id);
extern "C" int *func_0202ae18(void);
extern "C" void func_ov002_02153e90(char *entry);
extern "C" int func_ov002_02154a6c(char *self, int id, int arg);
extern "C" int func_ov002_02153be0(char *self, int target, int arg);
extern "C" void func_02048150(GameObject *m, int amount, int flag);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_02191108(GameResources *r, int a, int b, int c, int d);

struct Act02154230 {
    short kind;
    signed char arg;
    unsigned char count;
    signed char ids[4];
};

struct Rec02154230 {
    unsigned char state;
    unsigned char pad;
    short amount;
    unsigned char flag;
    unsigned char pad5;
};

// USA: func_ov002_02154230
extern "C" ARM int func_ov002_02154230(char *base, struct Act02154230 *act, int target, int alt) {
    if (act == NULL) return 0;
    if (target == 0) return 0;
    GameState *gs                  = GameState::GetInstance();
    GameResources *res             = func_ov017_0218b5b0();
    ArrayContainsByteStruct *party = (ArrayContainsByteStruct *) GetPtrField0x2a04(gs);
    int *ctx                       = func_0202ae18();
    struct Rec02154230 *recs       = (struct Rec02154230 *) ((char *) act + 8);
    unsigned char any              = 0;
    if (alt) recs = (struct Rec02154230 *) ((char *) act + 0x20);
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90((char *) &recs[i]);
    }
    for (int i = 0; i < act->count; i++) {
        struct Rec02154230 *rec = &recs[i];
        int id                  = act->ids[i];
        if (!ArrayContainsByte(party, id)) rec->flag = 1;
        if (!func_ov002_02154a6c(base, id, act->arg)) {
            rec->state = 1;
            continue;
        }
        if (_Z36HasPositiveField256Short178_02154b94Pvi(base, id)) {
            rec->state = 2;
            continue;
        }
        if (_Z34HasPositiveField304Short4_02154a34Pvi(base, id)) continue;
        int amount       = 0;
        unsigned char ok = 0;
        GameObject *m    = GetCombatantWithFlag0x100(gs, id);
        if (m == NULL) continue;
        if (act->kind == 0x27) {
            ok     = 1;
            amount = m->baseStats_->primaryStats.maxHP / 2;
            if (m->baseStats_->primaryStats.maxHP % 2) amount++;
        } else if (act->kind == 0x26) {
            ok       = 0;
            int rate = func_ov002_02153be0(base, target, act->arg);
            if (NextRandomMax(GetBTRandom(), 100) < rate) {
                ok     = 1;
                int v  = m->baseStats_->primaryStats.maxHP * (rate - 25);
                amount = v / 100;
                if (v % 100) amount++;
            }
        } else if (act->kind == 0x197) {
            ok     = 1;
            amount = 999;
        }
        if (!ok) continue;
        rec->state = 3;
        if (rec->flag) {
            rec->amount = amount;
            rec->state  = 3;
        } else {
            func_02048150(m, amount, 1);
        }
        if (CheckField0NonZero(ctx) && ArrayContainsByte(party, id)) {
            func_ov017_021c9e00(id, 1, 0, 1);
        }
        if (ArrayContainsByte(party, id)) {
            func_ov017_02191108(res, 1, 1, 1, 1);
        }
        any = 1;
    }
    return any;
}
