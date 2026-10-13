#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
struct Random;

struct Stats_021e9f68 {
    char pad0[0x14];
    unsigned int flags14;
    char pad18[0x21 - 0x18];
    unsigned char kind21;
};

struct Cbt_021e9f68 {
    char pad0[0x138];
    struct Stats_021e9f68* stats;
#if defined(jpn)
    char pad13c[0x144 - 0x13c];
#else
    char pad13c[0x150 - 0x13c];
#endif
    unsigned char* field150;
};

struct Ctx_021e9f68 {
    char pad0[0xc];
    void* queue;
    struct Random* battle;
    char pad14[0x20 - 0x14];
    short partyTarget[4];
    short monTarget[8];
    unsigned char partyState[4];
    unsigned char monState[8];
    char pad44[0x76 - 0x44];
    unsigned char f76;
    unsigned char f77;
};

struct Action_021e9f68 {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int lo8 : 8;
    unsigned int kind : 2;
    unsigned int hi8 : 22;
    unsigned int padc;
    unsigned int flags10;
};

struct IdList_021e9f68 {
    short v[8];
};

extern const struct IdList_021e9f68 data_ov024_021fe768;
extern const struct IdList_021e9f68 data_ov024_021fe708;

extern "C" struct Cbt_021e9f68* _Z16GetCombatantByIDii(struct Random* battle, int id);
int IsFlag10088Set(struct S_10088* obj);
extern "C" int _Z33IsCombatantFlag2Mask8192_021e6798P10GameObject(struct Cbt_021e9f68* c);
extern "C" int _Z33IsCombatantFlag2Mask2048_021e7ba8P10GameObject(struct Cbt_021e9f68* c);
extern "C" void _Z17PushEntry0215ff50Pvsh(void* obj, short val1, unsigned char val2);
extern "C" struct Cbt_021e9f68* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int id);
int AnySlotHasBit18At0x2f4(unsigned char* obj);
int NextRandomMax(struct Random* random, int maximum);
extern "C" int func_ov000_02155f9c(struct Random* battle, int id, int checkSubFlag);
extern "C" int func_ov024_021ea500(struct Ctx_021e9f68* ctx, struct Action_021e9f68* action, int id);
extern "C" int func_ov000_0215eb1c(struct Random* battle, short* out, int max, int flags);
extern "C" int func_ov000_0215e9fc(struct Random* battle, short* out, int max, int flags);
extern "C" int func_ov000_02156558(struct Random* battle, int id);

static inline int IsKind_021e9f68(struct Cbt_021e9f68* c, int kind) {
    return c->stats->kind21 == kind;
}

// USA: func_ov024_021e9f68
extern "C" ARM int func_ov024_021e9f68(struct Ctx_021e9f68* ctx, short* a, short* b, struct Action_021e9f68* action,
                                       unsigned char* out) {
    struct Cbt_021e9f68* self;
    GameState* gs;
    short saved;
    void* queue;
    struct Random* rnd;
    unsigned char* state;
    short* target;
    if (ctx->queue == 0) {
        return 0;
    }
    self = _Z16GetCombatantByIDii(ctx->battle, *b);
    if (!self) {
        return 0;
    }
    if (IsFlag10088Set((struct S_10088*)self) || _Z33IsCombatantFlag2Mask8192_021e6798P10GameObject(self)) {
        return 0;
    }
    gs = GameState::GetInstance();
    rnd = ctx->battle;
    saved = *a;
    queue = ctx->queue;
    *out = 0;
    if (_Z33IsCombatantFlag2Mask2048_021e7ba8P10GameObject(self)) {
        return 0;
    }
    if ((action->flags10 & 0x400) && action->kind == 1 && *a != *b) {
        if (self->stats->flags14 & 0x200) {
            _Z17PushEntry0215ff50Pvsh(queue, *a, 1);
            *a = *b;
            *b = saved;
            ctx->f76 = 0;
            *out = 1;
            return 0;
        }
        int inRange = *b >= 0 && *b <= 3;
        if (inRange) {
            struct Cbt_021e9f68* c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, *b);
            if (c && AnySlotHasBit18At0x2f4(c->field150) && NextRandomMax(rnd, 4) == 0) {
                _Z17PushEntry0215ff50Pvsh(queue, *a, 1);
                *a = *b;
                *b = saved;
                ctx->f76 = 0;
                *out = 1;
                return 0;
            }
        }
    }
    if ((action->flags10 & 4) && action->kind == 1 && (self->stats->flags14 & 0x4000000)) {
        _Z17PushEntry0215ff50Pvsh(queue, *a, 2);
        *a = *b;
        *b = saved;
        ctx->f76 = 0;
        return 0;
    }
    if (func_ov000_02155f9c(ctx->battle, *b, 0)) {
        return 0;
    }
    int inRange = 0;
    int id = *b;
    if (id >= 0 && id <= 3) {
        inRange = 1;
    }
    if (inRange) {
        state = &ctx->partyState[*b];
        target = &ctx->partyTarget[*b];
    } else {
        state = &ctx->monState[id - 0xc0];
        target = &ctx->monTarget[id - 0xc0];
    }
    int busy = func_ov024_021ea500(ctx, action, *a);
    if ((action->flags10 & 0x80) && busy == 0) {
        if (IsKind_021e9f68(self, 4)) {
            _Z17PushEntry0215ff50Pvsh(queue, *a, 3);
            *a = *b;
            *b = saved;
            ctx->f76 = 0;
            *state = 1;
            return 1;
        }
        if (IsKind_021e9f68(self, 5)) {
            struct IdList_021e9f68 ids = data_ov024_021fe768;
            int isParty = *b >= 0 && *b <= 3;
            int count;
            if (isParty) {
                count = func_ov000_0215eb1c(ctx->battle, ids.v, 8, 1);
            } else {
                count = func_ov000_0215e9fc(ctx->battle, ids.v, 8, 1);
            }
            if (*target < 0) {
                *target = ids.v[NextRandomMax(rnd, count)];
            }
            _Z17PushEntry0215ff50Pvsh(queue, *target, 4);
            *a = *b;
            *b = *target;
            ctx->f76 = 0;
            ctx->f77 = 1;
            return 0;
        }
        if (IsKind_021e9f68(self, 9)) {
            int roll = NextRandomMax(rnd, 5);
            struct IdList_021e9f68 ids = data_ov024_021fe708;
            int isParty = *b >= 0 && *b <= 3;
            int count;
            if (isParty) {
                if (roll < 2) {
                    count = func_ov000_0215e9fc(ctx->battle, ids.v, 8, 1);
                } else {
                    count = func_ov000_0215eb1c(ctx->battle, ids.v, 8, 1);
                }
            } else {
                if (roll < 2) {
                    count = func_ov000_0215eb1c(ctx->battle, ids.v, 8, 1);
                } else {
                    count = func_ov000_0215e9fc(ctx->battle, ids.v, 8, 1);
                }
            }
            if (*target < 0) {
                *target = ids.v[NextRandomMax(rnd, count)];
            }
            if (*b == *target) {
                _Z17PushEntry0215ff50Pvsh(queue, *target, 10);
            } else {
                _Z17PushEntry0215ff50Pvsh(queue, *target, 5);
                *a = *b;
                ctx->f76 = 0;
                ctx->f77 = 1;
            }
            *b = *target;
            return 0;
        }
        int isParty = *b >= 0 && *b <= 3;
        if (isParty) {
            struct Random* battle = ctx->battle;
            if (*state == 0) {
                if (!func_ov000_02156558(battle, *b)) {
                    *state = 2;
                    return 0;
                }
                _Z17PushEntry0215ff50Pvsh(queue, *a, 3);
                *a = *b;
                *b = saved;
                *state = 1;
                ctx->f76 = 0;
                return 1;
            } else if (*state == 1) {
                _Z17PushEntry0215ff50Pvsh(queue, *a, 3);
                *a = *b;
                *b = saved;
                ctx->f76 = 0;
                return 1;
            }
        }
    }
    return 0;
}
