#include <globaldefs.h>
#include "GameState/GameState.h"
int GetField0x3acValue_020100a8(GameState*);

struct Combatant020A36A8 {
    char pad[0x2a];
    signed char field2a;
};

// USA: func_020a36a8
ARM int MatchesActiveIndex020a36a8(struct Combatant020A36A8* obj) {
    return obj->field2a == GetField0x3acValue_020100a8((GameState*)(GameState::GetInstance()));
}
