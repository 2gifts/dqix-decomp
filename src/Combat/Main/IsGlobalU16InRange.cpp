#include <globaldefs.h>

#include "Combat/BattleSkillEligibility.h"

int IsInRange0201b588(int);

extern "C" unsigned short *func_02012fe4(void);

// USA: func_020117f0
ARM int IsGlobalU16InRange(GameState *) {
    return IsInRange0201b588((int) (*func_02012fe4()));
}
