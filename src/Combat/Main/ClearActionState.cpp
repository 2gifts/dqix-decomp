#include <globaldefs.h>

#include "Combat/ActionState.h"

// USA: func_0201fbe0
ARM void ClearActionState(struct ActionState0201fbe0 *s, int force) {
    if (s->b2 != 0 && force == 0) return;
    if (s->field4 != 0 && force == 0) return;
    if (s->state == 2 || s->state == 3 || force != 0 || s->subState == 3) {
        s->subState = 4;
    }
    s->field4 = 0;
}
