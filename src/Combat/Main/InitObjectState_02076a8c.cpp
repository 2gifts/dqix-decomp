#include <globaldefs.h>

#include "Combat/FieldActorState.h"

// USA: func_02076a8c  (semantic: InitObjectState_02076a8c)
extern "C" ARM void func_02076a8c(FieldMonsterState* p) {
    func_02032e58(&p->actor.base);

    p->actor.base.object.unknown_0_ |= 0x20;
    p->actor.base.fieldB4 = 0x1c2;
    p->actor.phase = 1;
    p->actor.unknown_134 = 1;
    p->actor.unknown_138 = 1;
    p->actor.unknown_139 = 2;
    p->actor.unknown_13a = 1;
    p->actor.unknown_13b = 3;
    p->actor.unknown_13c = 1;
    p->actor.unknown_140 = 0x1e;
    p->actor.unknown_144 = 5;
    p->actor.unknown_148 = 0x1000;
    p->actor.elapsedTime = 0;
    p->actor.tickCount = 0;
    p->actor.phaseElapsedTime = 0;
    p->unknown164 = 0;
    p->combatantId = 0;
    p->unknown168 = 0;
    p->flags = 0;
    p->height = 0;
    p->rise = 0;
    p->unknown176 = 0;
    p->rising = 0;
    p->unknown17b = 0;
    p->unknown17c = 0;
    p->shadowInfo = 0;
    p->attributes = 0;
    p->unknown16a = 0;
    p->unknown17e = 0;
    p->targetPosition.x = 0;
    p->targetPosition.y = 0;
    p->targetPosition.z = 0;

    p->actor.base.object.DisableFlag(0x80);
}
