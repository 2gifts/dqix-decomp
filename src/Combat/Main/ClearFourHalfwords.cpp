#include <globaldefs.h>

#include "Combat/ObjectStateInitialization.h"

// USA: func_02032fb8
ARM void ClearFourHalfwords(struct Struct02032fb8* s) {
    s->x = 0;
    s->y = 0;
    s->z = 0;
    s->w = 0;
}
