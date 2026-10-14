#include <globaldefs.h>
#include "World/Bounds3D.h"
#include "Graphics/Vector.h"

struct Vec3 { int x; int y; int z; };

ARM void StoreThreeWordsAt0x00201ce78(int* obj, int a, int b, int c);

struct BoxEntry0201e8fc {
    Vector3fix center;
    Vector3fix extent;
    short angle;
    int minX, minZ, maxX, maxZ;
};

struct Container0201e8fc {
    unsigned char pad[0x80];
    unsigned short count;
    unsigned char pad2[2];
    struct BoxEntry0201e8fc* list;
};

// USA: func_0201e8fc
ARM void* FindBoxContainingPoint0201e8fc(struct Container0201e8fc* obj, struct Vec3* pt) {
    int i;
    for (i = 0; i < obj->count; i++) {
        struct BoxEntry0201e8fc* e = &obj->list[i];
        Vector3fix diff;
        Matrix4x3 mtxB;
        Bounds3D bounds;
        int angle;

        if (pt->x < e->minX || pt->z < e->minZ) continue;
        if (pt->x > e->maxX || pt->z > e->maxZ) continue;

        Vector3fix_Subtract((const Vector3fix*)pt, &e->center, &diff);
        angle = fix32ReduceAngle0To2Pi(-(short)e->angle);
        mtxB = RotationMatrixY(angle);
        Mat4x3_ApplyToVector(&diff, &mtxB, &diff);
        Vector3fix_Add(&diff, &e->center, &diff);

        StoreThreeWordsAt0x00201ce78(&bounds.minimum.x, e->center.x - e->extent.x / 2, e->center.y - e->extent.y / 2, e->center.z - e->extent.z / 2);
        StoreThreeWordsAt0x00201ce78(&bounds.maximum.x, e->center.x + e->extent.x / 2, e->center.y + e->extent.y / 2, e->center.z + e->extent.z / 2);

        if (func_02031118(&diff, &bounds) != 0)
            return e;
    }
    return 0;
}
