#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215ec80(int battle, short* buf, int max, int group, int flag);

struct Groups_021ef074 {
    unsigned char b0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
};

struct Battle_021ef074 {
    struct Random rng;
    char pad[0x81b0 - sizeof(struct Random)];
    struct Groups_021ef074 groups;
};

struct Ctx_021ef074 {
    struct Battle_021ef074* battle;
};

struct GroupList_021ef074 { short v[3]; };
struct IdTable_021ef074 { short v[8]; };

extern struct GroupList_021ef074 data_ov024_021fea1c[];
extern struct IdTable_021ef074 data_ov024_021fed1c;

// USA: func_ov024_021ef074
extern "C" ARM int func_ov024_021ef074(struct Ctx_021ef074* ctx, int unused1, int unused2, int* out, short* outIds) {
    struct Groups_021ef074* groups = &ctx->battle->groups;
    if (groups == 0) return 0;
    struct GroupList_021ef074 picks = data_ov024_021fea1c[1];
    short numPicks = 0;
    for (int i = 0; i < groups->groupCount; i++) {
        struct IdTable_021ef074 ids = data_ov024_021fed1c;
        int count = func_ov000_0215ec80((int)ctx->battle, ids.v, 8, i & 0xff, 1);
        if (count <= 0) continue;
        short eligible = 0;
        for (int j = 0; j < count; j++) {
            GameObject* c = GetCombatantByID((int)ctx->battle, ids.v[j]);
            if (c == 0) continue;
            ModifiableCombatStats* stats = c->currentStats_;
            if (stats->primaryStats.defense >= 0xffff) continue;
            if (stats->defenseBuff < 2) eligible++;
        }
        if (eligible > 0) picks.v[numPicks++] = i;
    }
    if (numPicks <= 0) return 0;
    int r = NextRandomMax(&ctx->battle->rng, numPicks);
    *out = func_ov000_0215ec80((int)ctx->battle, outIds, 8, picks.v[r] & 0xff, 1);
    return 1;
}
