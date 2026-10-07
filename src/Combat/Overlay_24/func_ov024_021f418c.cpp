#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_ov000_0215e9fc(int battle, short* ids, int max, int flags);
extern unsigned short data_ov024_021fec54[4];

struct Ctx_021f418c { int battle; };

static inline int BaseDefense_021f418c(BaseCombatStats* stats) {
    // Keep the promoted defense read separate from the attack addition.
    int defense = stats->primaryStats.defense;
    return defense;
}

// Callback receives a byte ID and two output addresses from the dispatcher at 021f66cc.
// Accumulated attack/defense sums wrap to 16 bits; outputs change only on success.
// USA: func_ov024_021f418c
extern "C" ARM int func_ov024_021f418c(Ctx_021f418c* ctx, unsigned char id,
    void* unused, int* outFlag, short* outID) {
    short ids[4];
    short* dest = ids;
    unsigned short* source = data_ov024_021fec54;
    int n = 4;
    do {
        short* d = dest++;
        *(unsigned short*)d = *source++;
    } while (--n);
    int count = func_ov000_0215e9fc(ctx->battle, ids, 4, 0);
    if (count <= 0) return 0;
    GameObject* combatant = GetCombatantByID(ctx->battle, id);
    if (!combatant) return 0;
    unsigned short selectedSum = combatant->baseStats_->primaryStats.attack +
        BaseDefense_021f418c(combatant->baseStats_);
    unsigned short total = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantByID(ctx->battle, ids[i]);
        if (member) {
            total += member->baseStats_->primaryStats.attack +
                BaseDefense_021f418c(member->baseStats_);
        }
    }
    if (total / count < selectedSum * 3) return 0;
    *outFlag = 1;
    *outID = id;
    return 1;
}
