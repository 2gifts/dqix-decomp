#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
struct Random;
struct ArrayContainsByteStruct;

struct Stats_021e9b74 {
    char pad0[0x21];
    unsigned char kind21;
    char pad22[0x2a - 0x22];
    short owner2a;
};

struct Cbt_021e9b74 {
    char pad0[0x138];
    struct Stats_021e9b74* stats;
};

struct Ctx_021e9b74 {
    char pad0[0xc];
    void* queue;
    int battle;
    char pad14[0x79 - 0x14];
    unsigned char redirected;
};

struct Cmd_021e9b74 {
    short targetId;
};

struct Action_021e9b74 {
    char pad0[0x10];
    unsigned int flags10;
};

struct IdList_021e9b74 {
    short v[8];
};

struct CandList_021e9b74 {
    int v[8];
};

extern const struct IdList_021e9b74 data_ov024_021fe6f8;
extern const struct CandList_021e9b74 data_ov024_021fe7e0;

struct Cbt_021e9b74* GetCombatantByID(int unused, int id);
int IsFlag10088Set(struct S_10088* obj);
extern "C" int _Z33IsCombatantFlag2Mask8192_021e6798P10GameObject(GameObject* combatant);
extern "C" int func_ov000_0215e9fc(int battle, short* table, int count, int flag);
extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
extern "C" int func_ov000_02155f9c(int battle, int id, int v);
int NextRandomMax(struct Random* random, int maximum);
extern "C" void _Z17PushEntry0215ff20Pvsh(void* obj, short val1, unsigned char val2);
extern "C" float func_ov024_021db358(struct Cbt_021e9b74* obj);
void* GetPtrField0x2a04(GameState* gameState);
int ArrayContainsByte(struct ArrayContainsByteStruct* s, int val);
extern "C" void _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(unsigned char* obj, int idx);

static inline short GetOwner_021e9b74(struct Cbt_021e9b74* c) { SDK_NULL_ASSERT(c); return c->stats->owner2a; }

static inline int IsKind_021e9b74(struct Cbt_021e9b74* c, int kind) {
    return c->stats->kind21 == kind;
}

// USA: func_ov024_021e9b74
extern "C" ARM int func_ov024_021e9b74(struct Ctx_021e9b74* ctx, int unused, struct Cmd_021e9b74* cmd,
                                       struct Action_021e9b74* action) {
    void* queue;
    int n;
    int i;
    struct Random* rnd;
    if (ctx->queue == 0) {
        return 0;
    }
    struct Cbt_021e9b74* self = GetCombatantByID(ctx->battle, cmd->targetId);
    if (!self) {
        return 0;
    }
    if (IsFlag10088Set((struct S_10088*)self) || _Z33IsCombatantFlag2Mask8192_021e6798P10GameObject((GameObject*)self)) {
        return 0;
    }
    GameState::GetInstance();
    rnd = (struct Random*)ctx->battle;
    queue = ctx->queue;
    if (action->flags10 & 0x1000) {
        struct IdList_021e9b74 ids = data_ov024_021fe6f8;
        int isParty = cmd->targetId >= 0 && cmd->targetId <= 3;
        int count;
        if (isParty) {
            count = func_ov000_0215e9fc(ctx->battle, ids.v, 8, 1);
        } else {
            count = func_ov000_0215eb1c(ctx->battle, ids.v, 8, 1);
        }
        struct CandList_021e9b74 cands = data_ov024_021fe7e0;
        n = 0;
        for (i = 0; i < count; i++) {
            struct Cbt_021e9b74* c = GetCombatantByID(ctx->battle, ids.v[i]);
            if (c && cmd->targetId != ids.v[i] && !func_ov000_02155f9c(ctx->battle, ids.v[i], 0) &&
                IsKind_021e9b74(c, 8)) {
                cands.v[n++] = ids.v[i];
            }
        }
        if (n > 0) {
            cmd->targetId = cands.v[NextRandomMax(rnd, n)];
            _Z17PushEntry0215ff20Pvsh(queue, cmd->targetId, 6);
            ctx->redirected = 1;
            return 1;
        }
        n = 0;
        memset(&cands, -1, sizeof(cands));
        if (func_ov024_021db358(self) <= 0.08f) {
            for (i = 0; i < count; i++) {
                struct Cbt_021e9b74* c = GetCombatantByID(ctx->battle, ids.v[i]);
                if (c && cmd->targetId != ids.v[i] && !func_ov000_02155f9c(ctx->battle, ids.v[i], 0) &&
                    IsKind_021e9b74(c, 7)) {
                    cands.v[n++] = ids.v[i];
                }
            }
            if (n > 0) {
                cmd->targetId = cands.v[NextRandomMax(rnd, n)];
                _Z17PushEntry0215ff20Pvsh(queue, cmd->targetId, 7);
                ctx->redirected = 1;
                return 1;
            }
        }
        n = 0;
        memset(&cands, -1, sizeof(cands));
        for (i = 0; i < count; i++) {
            struct Cbt_021e9b74* c = GetCombatantByID(ctx->battle, ids.v[i]);
            if (c && !func_ov000_02155f9c(ctx->battle, ids.v[i], 0) && IsKind_021e9b74(c, 6) &&
                cmd->targetId == GetOwner_021e9b74(c)) {
                cands.v[n++] = ids.v[i];
            }
        }
        if (n > 0) {
            cmd->targetId = cands.v[NextRandomMax(rnd, n)];
            _Z17PushEntry0215ff20Pvsh(queue, cmd->targetId, 8);
            ctx->redirected = 1;
            if (ArrayContainsByte((struct ArrayContainsByteStruct*)GetPtrField0x2a04(GameState::GetInstance()),
                                  cmd->targetId)) {
                _Z39IncrementByteCounterCapped0x63_0215a8d4Phi((unsigned char*)ctx->battle, 4);
            }
            return 1;
        }
        memset(&cands, -1, sizeof(cands));
    }
    return 0;
}
