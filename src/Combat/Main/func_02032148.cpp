#include <globaldefs.h>
#include "System/Matrix.h"

struct Shape02094b9c { fix32_t x, y, z, ext0, ext1; };

// USA: func_02032148
extern "C" ARM int func_02032148(const Vector3fix* anchor, const struct Shape02094b9c* s, int e) {
    if (s->y > anchor->y) { return 0; }
    if (s->y + s->ext1 < anchor->y) { return 0; }

    fix32_t dx = anchor->x - s->x;
    fix32_t dz = anchor->z - s->z;
    dz = FIX32_MULTIPLY(dz, dz);
    dx = FIX32_MULTIPLY(dx, dx);
    return FIX32_MULTIPLY(s->ext0, s->ext0) >= dx + dz;
}
