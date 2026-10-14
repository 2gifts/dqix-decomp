#include <globaldefs.h>
#include "GameState/GameState.h"

struct OutStruct0215ccbc;

void AddEntryAndIncrementCount0215a88c(void* world, void* entry, int value);
void AppendToChainAndIncCount0215fe84(void* chain, void* entry, int idx);
extern "C" void func_ov000_02159eac(void* world, void* buf, int kind);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
    void* world, struct OutStruct0215ccbc* out, GameObject* combatant, short valC, short valA, short valB,
    unsigned long long words, unsigned char byteE);

static inline short CurrHP(ModifiableCombatStats* s) { return s->primaryStats.currHP; }
static inline short CurrMP(ModifiableCombatStats* s) { return s->primaryStats.currMP; }

// USA: func_ov000_021584e8
extern "C" ARM void func_ov000_021584e8(void* world, struct OutStruct0215ccbc* entry, GameObject* combatant,
                                        void* chain, int value, unsigned char kind) {
    AddEntryAndIncrementCount0215a88c(world, entry, (unsigned short)value);
    AppendToChainAndIncCount0215fe84(chain, entry, 1);
    ((unsigned char*)world)[0x8e02]++;
    unsigned long long words = 0;
    func_ov000_02159eac(world, &words, kind);
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
        world, entry, combatant, 0, CurrHP(combatant->currentStats_), CurrMP(combatant->currentStats_), words, 0);
}
