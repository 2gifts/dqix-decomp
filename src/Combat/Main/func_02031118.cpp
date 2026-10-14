#include <globaldefs.h>

#include "World/Bounds3D.h"

// USA: func_02031118
extern "C" ARM int func_02031118(const Vector3fix* p, const Bounds3D* b) {
    if (b->maximum.x < p->x) return 0;
    if (b->maximum.y < p->y) return 0;
    if (b->maximum.z < p->z) return 0;
    if (p->x < b->minimum.x) return 0;
    if (p->y < b->minimum.y) return 0;
    return p->z >= b->minimum.z ? 1 : 0;
}
