#include <globaldefs.h>
#include "GameState/GameState.h"

struct OutStruct0215ccbc;

void PopulateEntry_0215ccbc(int unused, struct OutStruct0215ccbc* out, GameObject* combatant,
                            short valC, short valA, short valB, int wordC, int wordD, unsigned char byteE);

static inline short GetCurrHP(GameObject* c) { short v = c->currentStats_->primaryStats.currHP; return v; }
static inline short GetCurrMP(GameObject* c) { short v = c->currentStats_->primaryStats.currMP; return v; }

// USA: func_ov000_0215cd44
extern "C" ARM void func_ov000_0215cd44(int unused, struct OutStruct0215ccbc* out, GameObject* combatant,
                                        short valC, int wordC, int wordD, unsigned char byteE) {
    PopulateEntry_0215ccbc(unused, out, combatant, valC, GetCurrHP(combatant), GetCurrMP(combatant), wordC, wordD, byteE);
}
