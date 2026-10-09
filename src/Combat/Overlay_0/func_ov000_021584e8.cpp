#include <globaldefs.h>
#include "GameState/GameState.h"

struct OutStruct0215ccbc;

extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* world, void* entry, int value);
extern "C" void _Z32AppendToChainAndIncCount0215fe84PvS_i(void* chain, void* entry, int idx);
extern "C" void func_ov000_02159eac(void* world, void* buf, int kind);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
    void* world, struct OutStruct0215ccbc* out, GameObject* combatant, short valC, short valA, short valB,
    unsigned long long words, unsigned char byteE);

static inline short CurrHP(GameObject* c) { short v = c->currentStats_->primaryStats.currHP; return v; }
static inline short CurrMP(GameObject* c) { short v = c->currentStats_->primaryStats.currMP; return v; }

// USA: func_ov000_021584e8
extern "C" ARM void func_ov000_021584e8(void* world, struct OutStruct0215ccbc* entry, GameObject* combatant,
                                        void* chain, int value, unsigned char kind) {
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(world, entry, (unsigned short)value);
    _Z32AppendToChainAndIncCount0215fe84PvS_i(chain, entry, 1);
    ((unsigned char*)world)[0x8e02]++;
    unsigned long long words = 0;
    func_ov000_02159eac(world, &words, kind);
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
        world, entry, combatant, 0, CurrHP(combatant), CurrMP(combatant), words, 0);
}
