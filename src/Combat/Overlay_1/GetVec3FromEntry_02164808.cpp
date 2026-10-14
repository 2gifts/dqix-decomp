#include <globaldefs.h>
#include "World/Object3D.h"

struct Entry02164808 { int selector; char pad[8]; unsigned char* target; };
struct Vec3Out02164808 { int x, y, z; };

// USA: func_ov001_02164808  (semantic: GetVec3FromEntry_02164808)
extern "C" ARM int func_ov001_02164808(struct Entry02164808* arr, int index, struct Vec3Out02164808* out) {
    struct Entry02164808* e;
    unsigned char* t;
    unsigned char* src;

    if (index < 0 || index >= 0x20) {
        return 0;
    }
    e = &arr[index];
    switch (e->selector) {
    case 0:
    case 1:
    case 4:
    case 5: {
        t = e->target;
        if (t == NULL) return 0;
        Vector3fix resultA = ((Object3D*)t)->GetScale();
        out->x = resultA.x;
        out->y = resultA.y;
        out->z = resultA.z;
        return 1;
    }
    case 6: {
        t = e->target;
        if (t == NULL) return 0;
        src = *(unsigned char**)(t + 0x18);
        if (src == NULL) return 0;
        Vector3fix resultB = ((Object3D*)src)->GetScale();
        out->x = resultB.x;
        out->y = resultB.y;
        out->z = resultB.z;
        return 1;
    }
    }
    return 0;
}
