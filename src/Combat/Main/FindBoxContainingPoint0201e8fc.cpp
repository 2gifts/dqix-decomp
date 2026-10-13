#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);

struct Mtx43_02030d84 { unsigned int v[12]; };
ARM struct Mtx43_02030d84 RotationMatrixY(int angle);

struct FixedVec3_2034 { int x; int y; int z; };
struct FixedMtx3T_2034 {
    struct FixedVec3_2034 row0;
    struct FixedVec3_2034 row1;
    struct FixedVec3_2034 row2;
    struct FixedVec3_2034 trans;
};
extern "C" ARM void Mat4x3_ApplyToVector(struct FixedVec3_2034* v, struct FixedMtx3T_2034* m, struct FixedVec3_2034* out);

ARM void StoreThreeWordsAt0x00201ce78(int* obj, int a, int b, int c);

struct Point02031118 { int x; int y; int z; };
struct Bounds02031118 { int minx; int miny; int minz; int maxx; int maxy; int maxz; };
extern "C" ARM int func_02031118(struct Point02031118* p, struct Bounds02031118* b);

extern "C" int _Z22fix32ReduceAngle0To2Pii(int angle);

struct BoxEntry0201e8fc {
    int cx, cy, cz;
    int ex, ey, ez;
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
        struct Vec3 diff;
        struct Mtx43_02030d84 mtxB;
        struct Bounds02031118 bounds;
        int angle;

        if (pt->x < e->minX || pt->z < e->minZ) continue;
        if (pt->x > e->maxX || pt->z > e->maxZ) continue;

        Vector3fix_Subtract(pt, (struct Vec3*)e, &diff);
        angle = _Z22fix32ReduceAngle0To2Pii(-(short)e->angle);
        mtxB = RotationMatrixY(angle);
        Mat4x3_ApplyToVector((struct FixedVec3_2034*)&diff, (struct FixedMtx3T_2034*)&mtxB, (struct FixedVec3_2034*)&diff);
        Vector3fix_Add(&diff, (struct Vec3*)e, &diff);

        StoreThreeWordsAt0x00201ce78(&bounds.maxx, e->cx - e->ex / 2, e->cy - e->ey / 2, e->cz - e->ez / 2);
        StoreThreeWordsAt0x00201ce78(&bounds.minx, e->cx + e->ex / 2, e->cy + e->ey / 2, e->cz + e->ez / 2);

        if (func_02031118((struct Point02031118*)&diff, &bounds) != 0)
            return e;
    }
    return 0;
}
